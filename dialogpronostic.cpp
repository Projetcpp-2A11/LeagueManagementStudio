
#include "DialogPronostic.h"
#include "PronosticDialog.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError> // Ajouté

void DialogPronostic::ShowPronostic(int matchID, QWidget *parent) {
    QSqlQuery matchQuery;
    matchQuery.prepare(
        "SELECT M.MATCHDATE, M.TEAM1ID, M.TEAM2ID, S.NAME AS STADIUM "
        "FROM MATCHES M "
        "JOIN STADIUM S ON M.STADIUMID = S.STADIUMID "
        "WHERE M.MATCHID = ?"
        );
    matchQuery.addBindValue(matchID);

    if(matchQuery.exec() && matchQuery.next()) {
        QDateTime date = matchQuery.value("MATCHDATE").toDateTime();
        int team1ID = matchQuery.value("TEAM1ID").toInt();
        int team2ID = matchQuery.value("TEAM2ID").toInt();
        QString stadium = matchQuery.value("STADIUM").toString();


        QString team1 = getTeamName(team1ID);
        QString team2 = getTeamName(team2ID);

        QString form1 = calculateTeamForm(team1ID, date);
        QString form2 = calculateTeamForm(team2ID, date);

        float cote1, coteX, cote2;
        calculateOdds(form1, form2, cote1, coteX, cote2);



        PronosticDialog dialog(parent);
        dialog.setPronosticData(
            date,
            stadium, // Ajout du stade

            team1,
            team2,
            form1,
            form2,
            cote1,
            coteX,
            cote2);
        dialog.exec();
    } else {
        QMessageBox::critical(parent, "Erreur",
                              "Impossible de charger les données du match.\n" +
                                  matchQuery.lastError().text());
    }
}
QString DialogPronostic::getStadiumName(int stadiumID) {
    QSqlQuery query;
    query.prepare("SELECT NAME FROM STADIUM WHERE STADIUMID = ?");
    query.addBindValue(stadiumID);
    return query.exec() && query.next() ? query.value(0).toString() : "Stade inconnu";
}

QString DialogPronostic::getTeamName(int teamID)
{
    QSqlQuery query;
    query.prepare("SELECT NAME FROM TEAMS WHERE TEAMID = ?");
    query.addBindValue(teamID);
    if(query.exec() && query.next()) {
        return query.value(0).toString();
    }
    return "Inconnu";
}

QString DialogPronostic::calculateTeamForm(int teamID, const QDateTime &matchDate) {
    QString form;
    QSqlQuery query;

    // Modification de la requête SQL
    query.prepare(
        "SELECT * FROM ("
        "  SELECT SCORE, TEAM1ID, TEAM2ID, MATCHDATE "
        "  FROM MATCHES "
        "  WHERE (TEAM1ID = :team OR TEAM2ID = :team) "
        "  AND MATCHDATE < TO_TIMESTAMP(:matchDate, 'YYYY-MM-DD') " // Comparaison exacte avec timestamp
        "  ORDER BY MATCHDATE DESC"
        ") WHERE ROWNUM <= 20"
        );

    // Utilisation du timestamp complet
    query.bindValue(":matchDate", matchDate.toString("yyyy-MM-dd"));
    query.bindValue(":team", teamID);


    if (!query.exec()) {
        qDebug() << "[ERREUR SQL]" << query.lastError().text();
        return form;
    }

    int count = 0;
    while (query.next()) {
        QString score = query.value("SCORE").toString();
        int team1ID = query.value("TEAM1ID").toInt();
        // int team2ID = query.value("TEAM2ID").toInt(); // <-- peut être supprimé si non utilisé

        if (!score.contains("-"))
            continue;

        QStringList parts = score.split("-");
        if (parts.size() != 2)
            continue;

        int goals1 = parts[0].toInt();
        int goals2 = parts[1].toInt();
        bool isHome = (teamID == team1ID);

        int teamGoals = isHome ? goals1 : goals2;
        int opponentGoals = isHome ? goals2 : goals1;

        if (teamGoals > opponentGoals)
            form += "W ";
        else if (teamGoals == opponentGoals)
            form += "D ";
        else
            form += "L ";

        count++;
    }

    if (count == 0) {
        qDebug() << "[INFO] Aucun match précédent trouvé pour cette équipe.";
    } else {
        qDebug() << "[FORME] Équipe ID:" << teamID << " -> " << form.trimmed();
    }

    return form.trimmed();
}





void DialogPronostic::calculateOdds(const QString& form1, const QString& form2,
                                    float& cote1, float& coteX, float& cote2)
{
    // Si pas de données historiques
    if(form1.isEmpty() && form2.isEmpty()) {
        cote1 = 2.0f;
        coteX = 3.0f;
        cote2 = 2.0f;
        return;
    }

    // Calcul normal
    int wins1 = form1.count("W");
    int wins2 = form2.count("W");
    int draws = form1.count("D") + form2.count("D");

    float total = qMax(1, wins1 + wins2 + draws); // Évite division par zéro

    cote1 = (total / (wins1 + 0.5f)) * 1.1f;
    cote2 = (total / (wins2 + 0.5f)) * 1.1f;
    coteX = (total / (draws + 0.5f)) * 1.3f;
}
