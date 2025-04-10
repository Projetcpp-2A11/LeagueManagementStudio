#include "DialogPronostic.h"
#include <QDebug>
#include <QSqlQuery>
#include <QDateTime>
#include <QSqlError>


void DialogPronostic::ComputeAndDebug(int matchID)
{
    QSqlQuery matchQuery;
    matchQuery.prepare("SELECT MATCHDATE, TEAM1ID, TEAM2ID FROM MATCHES WHERE MATCHID = ?");
    matchQuery.addBindValue(matchID);

    if(matchQuery.exec() && matchQuery.next()) {
        QDateTime date = matchQuery.value("MATCHDATE").toDateTime();
        int team1ID = matchQuery.value("TEAM1ID").toInt();
        int team2ID = matchQuery.value("TEAM2ID").toInt();

        QString team1 = getTeamName(team1ID);
        QString team2 = getTeamName(team2ID);

        QString form1 = calculateTeamForm(team1ID, date);
        QString form2 = calculateTeamForm(team2ID, date);

        float cote1, coteX, cote2;
        calculateOdds(form1, form2, cote1, coteX, cote2);

        qDebug().nospace() << "\n=== PRONOSTIC DEBUG ===";
        qDebug() << "Match ID: " << matchID;
        qDebug() << "Date: " << date.toString("dd/MM/yyyy ");
        qDebug() << "Équipes: " << team1 << " vs " << team2;
        qDebug() << "Cotes - 1|X|2: "
                 << QString::number(cote1, 'f', 2) << "|"
                 << QString::number(coteX, 'f', 2) << "|"
                 << QString::number(cote2, 'f', 2);
        qDebug() << "Forme " << team1 << ": " << form1;
        qDebug() << "Forme " << team2 << ": " << form2;
        qDebug() << "==========================\n";
    } else {
        qDebug() << "Erreur de récupération des informations du match.";
    }
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

    qDebug() << "[DEBUG] Calcul de la forme pour l'équipe ID:" << teamID << " avant le " << matchDate.toString("yyyy-MM-dd HH:mm:ss");

    query.prepare(
        "SELECT * FROM ("
        "  SELECT SCORE, TEAM1ID, TEAM2ID, MATCHDATE "
        "  FROM MATCHES "
        "  WHERE (TEAM1ID = :team OR TEAM2ID = :team) "
        "  AND MATCHDATE < TO_DATE(:matchDate, 'YYYY-MM-DD HH24:MI:SS') "
        "  ORDER BY MATCHDATE DESC"
        ") WHERE ROWNUM <= 5"
        );
    query.bindValue(":team", teamID);
    query.bindValue(":matchDate", matchDate.toString("yyyy-MM-dd HH:mm:ss"));

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
