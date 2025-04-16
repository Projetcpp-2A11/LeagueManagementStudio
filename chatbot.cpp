#include "chatbot.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDate>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

Chatbot::Chatbot(Connection* conn) : connection(conn) {
    if (!connection->createconnection()) {
        qWarning() << "Erreur de connexion à la base de données.";
    }
}

Chatbot::~Chatbot() {
    connection->closeConnection();
}

QString Chatbot::getAnswer(const QString &question) {
    QSqlQuery query;
    QString answer = "Désolé, je n'ai pas trouvé de réponse.";

    QDate currentDate = QDate::currentDate();
    QString dateFilter;
    QString teamFilter;
    QString stadiumFilter;

    // Détection de la date dans la question
    QRegularExpression dateRegex("\\b(\\d{4}-\\d{2}-\\d{2})\\b");
    QRegularExpressionMatch dateMatch = dateRegex.match(question);
    if (dateMatch.hasMatch()) {
        dateFilter = dateMatch.captured(1);
    } else if (question.contains("aujourd'hui", Qt::CaseInsensitive)) {
        dateFilter = currentDate.toString("yyyy-MM-dd");
    }

    // Détection d'équipe
    QRegularExpression teamRegex("\\b(équipe|joueur)\\s+([a-zA-Z0-9\\-]+)\\b", QRegularExpression::CaseInsensitiveOption);
    QRegularExpressionMatch teamMatch = teamRegex.match(question);
    if (teamMatch.hasMatch()) {
        teamFilter = teamMatch.captured(2);  // Capture le nom de l'équipe ou du joueur
    }

    // Détection de stade
    QRegularExpression stadiumRegex("\\bstade\\s+([a-zA-Z0-9\\-]+)\\b", QRegularExpression::CaseInsensitiveOption);
    QRegularExpressionMatch stadiumMatch = stadiumRegex.match(question);
    if (stadiumMatch.hasMatch()) {
        stadiumFilter = stadiumMatch.captured(1);  // Capture le nom du stade
    }
    // ------------------ MATCHS ------------------
    if (question.contains("match", Qt::CaseInsensitive)) {
        QString queryStr = "SELECT T1.NAME AS TEAM1_NAME, T2.NAME AS TEAM2_NAME, M.MATCHDATE "
                           "FROM MATCHES M "
                           "JOIN TEAMS T1 ON M.TEAM1ID = T1.TEAMID "
                           "JOIN TEAMS T2 ON M.TEAM2ID = T2.TEAMID";

        bool hasCondition = false;

        if (!dateFilter.isEmpty()) {
            queryStr += " WHERE M.MATCHDATE = :date";
            hasCondition = true;
        }

        if (!teamFilter.isEmpty()) {
            queryStr += (hasCondition ? QString(" AND") : QString(" WHERE")) + " (T1.NAME = :team OR T2.NAME = :team)";
            hasCondition = true;
        }

        query.prepare(queryStr);
        if (!dateFilter.isEmpty()) {
            query.bindValue(":date", dateFilter);
        }
        if (!teamFilter.isEmpty()) {
            query.bindValue(":team", teamFilter);
        }

        if (query.exec()) {
            answer = "Matchs trouvés :\n";
            while (query.next()) {
                answer += query.value("TEAM1_NAME").toString() + " vs " + query.value("TEAM2_NAME").toString() +
                          " le " + query.value(2).toDate().toString("yyyy-MM-dd") + "\n";
            }

            if (answer.trimmed() == "Matchs trouvés :") {
                answer = "Aucun match trouvé pour cette date.";
            }
        } else {
            answer = "Erreur DB (matchs) : " + query.lastError().text();
        }
    }

    // ------------------ SCORES ------------------
    else if (question.contains("score", Qt::CaseInsensitive)) {
        QString queryStr = "SELECT T1.NAME AS TEAM1_NAME, T2.NAME AS TEAM2_NAME, M.SCORE "
                           "FROM MATCHES M "
                           "JOIN TEAMS T1 ON M.TEAM1ID = T1.TEAMID "
                           "JOIN TEAMS T2 ON M.TEAM2ID = T2.TEAMID";
        if (!teamFilter.isEmpty()) {
            queryStr += " WHERE T1.NAME = :team OR T2.NAME = :team";
        }

        query.prepare(queryStr);
        if (!teamFilter.isEmpty())
            query.bindValue(":team", teamFilter);

        if (query.exec()) {
            answer = "Scores des matchs :\n";
            while (query.next()) {
                QString score = query.value("SCORE").toString();
                answer += query.value("TEAM1_NAME").toString() + " " + score + " " +
                          query.value("TEAM2_NAME").toString() + "\n";
            }
        } else {
            answer = "Erreur DB (scores) : " + query.lastError().text();
        }

    }
    // ------------------ PARTENAIRES ------------------
    else if (question.contains("partenaire", Qt::CaseInsensitive)) {
        query.prepare("SELECT NAME FROM PARTNERS");
        if (query.exec()) {
            answer = "Liste des partenaires :\n";
            while (query.next()) {
                answer += "- " + query.value(0).toString() + "\n";
            }
        } else {
            answer = "Erreur DB (partenaires) : " + query.lastError().text();
        }

    }
    // ------------------ ÉQUIPES ------------------
    else if (question.contains("equipe", Qt::CaseInsensitive)) {
        QString queryStr = "SELECT NAME FROM TEAMS";

        if (!teamFilter.isEmpty()) {
            queryStr += " WHERE UPPER(NAME) LIKE UPPER(:team)";
        }

        query.prepare(queryStr);

        if (!teamFilter.isEmpty())
            query.bindValue(":team", "%" + teamFilter + "%");

        if (query.exec()) {
            answer = "Liste des équipes :\n";
            while (query.next()) {
                answer += "- " + query.value("NAME").toString() + "\n";
            }
        } else {
            answer = "Erreur DB (équipes) : " + query.lastError().text();
        }
    }

    // ------------------ JOUEURS ------------------
    else if (question.contains("joueur", Qt::CaseInsensitive)) {
        QString queryStr = "SELECT FNAME, LNAME, POSITION, STATUS, TEAMID FROM PLAYERS";

        // Filtrage facultatif par nom de joueur ou équipe
        if (!teamFilter.isEmpty()) {
            queryStr += " WHERE TEAMID = (SELECT TEAMID FROM TEAMS WHERE NAME = :team)";
        }

        query.prepare(queryStr);

        if (!teamFilter.isEmpty()) {
            query.bindValue(":team", teamFilter);
        }

        if (query.exec()) {
            answer = "Liste des joueurs :\n";
            bool found = false;
            while (query.next()) {
                found = true;

                QString firstName = query.value("FNAME").toString();
                QString lastName = query.value("LNAME").toString();
                QString position = query.value("POSITION").toString();
                QString status = query.value("STATUS").toString();
                int teamId = query.value("TEAMID").toInt();  // The ID of the team the player belongs to

                answer += "🧑‍💼 " + firstName + " " + lastName + "\n";
                answer += "  ➤ Position : " + position + "\n";
                answer += "  ➤ Statut : " + status + "\n";
                answer += "  ➤ Équipe ID : " + QString::number(teamId) + "\n\n";
            }

            if (!found) {
                answer = "Aucun joueur trouvé pour cette équipe.";
            }
        } else {
            answer = "❌ Erreur lors de la récupération des joueurs : " + query.lastError().text();
        }
    }

    // ------------------ STADES -----------------
    // ------------------ AUTRES QUESTIONS ------------------
    else {
        answer = handleGenericQuestions(question);
    }

    return answer;
}

QString Chatbot::handleGenericQuestions(const QString &question) {
    QString lowerQuestion = question.toLower();

    if (lowerQuestion.contains("meilleur")) {
        return "Le titre de 'meilleur joueur' dépend des critères comme les buts ou la technique. Messi et Ronaldo sont des exemples avec des critères différents. Quels critères utilises-tu ?";
    } else if (lowerQuestion.contains("règle hors-jeu")) {
        return "Le hors-jeu empêche un joueur d'être plus proche du but adverse que l'avant-dernier défenseur lorsqu'une passe lui est faite.";
    } else if (lowerQuestion.contains("règle")) {
        return "Les règles du football incluent l'alignement des équipes, les fautes, le hors-jeu et l'arbitrage (VAR). Tu veux plus de détails sur une règle ?";
    } else if (lowerQuestion.contains("bonjour")) {
        return "Bonjour ! 👋 Je suis ton assistant football, prêt à t'aider sur tout sujet concernant le foot. Que puis-je faire pour toi ?";
    } else if (lowerQuestion.contains("cv") || lowerQuestion.contains("ça va")) {
        return "Je vais bien, merci ! 😊 Et toi ? Prêt à discuter foot ?";
    } else if (lowerQuestion.contains("duree du jeu") || lowerQuestion.contains("durée du jeu")) {
        return "Un match dure 90 minutes, avec 45 minutes par mi-temps et une pause de 15 minutes.";
    } else if (lowerQuestion.contains("taille du terrain")) {
        return "Le terrain mesure généralement entre 100 et 110 m de long et entre 64 et 75 m de large, selon les normes FIFA.";
    } else if (lowerQuestion.contains("var") || lowerQuestion.contains("arbitrage vidéo")) {
        return "La VAR aide l'arbitre pour les buts, penalties, cartons rouges et erreurs d’identité, pour des décisions plus justes.";
    } else if (lowerQuestion.contains("carton jaune")) {
        return "Un carton jaune avertit un joueur pour une faute. Deux jaunes = un rouge et une expulsion.";
    } else if (lowerQuestion.contains("carton rouge")) {
        return "Le carton rouge expulse immédiatement un joueur pour une faute grave.";
    } else if (lowerQuestion.contains("penalty") || lowerQuestion.contains("penalty")) {
        return "Le penalty est tiré depuis 11 m lorsque la faute se produit dans la surface de réparation.";
    } else if (lowerQuestion.contains("corner")) {
        return "Un corner est accordé quand le ballon dépasse la ligne de but, touché en dernier par un défenseur.";
    } else if (lowerQuestion.contains("hors-jeu")) {
        return "Le hors-jeu se produit lorsqu’un joueur est plus près du but adverse que le ballon et l'avant-dernier défenseur.";
    } else if (lowerQuestion.contains("merci")) {
        return "Avec plaisir ! 😊 Si tu as d'autres questions, je suis là pour toi.";
    }

    return "Je n'ai pas encore la réponse à ça. Essaie de poser une question sur les règles ou les joueurs.";
}
