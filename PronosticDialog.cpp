#include "PronosticDialog.h"
// L'inclusion doit être APRÈS le .h principal
#include "ui_PronosticDialog.h" // ✔️ Inclusion capitale
#include <QSqlQuery>
#include <QDate>

PronosticDialog::PronosticDialog(int matchId, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PronosticDialog)
{
    ui->setupUi(this);
    loadMatchData(matchId);
}


void PronosticDialog::loadMatchData(int matchId)
{
    QSqlQuery query;
    query.prepare("SELECT MATCHDATE, TEAM1ID, TEAM2ID FROM MATCHES WHERE MATCHID = ?");
    query.addBindValue(matchId);

    if(query.exec() && query.next()) {
        ui->Date->setText(query.value("MATCHDATE").toDate().toString("dd/MM/yyyy"));

        int team1Id = query.value("TEAM1ID").toInt();
        int team2Id = query.value("TEAM2ID").toInt();

        ui->team1->setText(getTeamName(team1Id));
        ui->team2->setText(getTeamName(team2Id));

        calculateAndDisplayOdds(team1Id, team2Id);

        ui->FormeE1->setText(getRecentTeamForm(team1Id));
        ui->FormeE2->setText(getRecentTeamForm(team2Id));
    }
}

void PronosticDialog::calculateAndDisplayOdds(int team1Id, int team2Id)
{
    QSqlQuery statsQuery;

    // Calcul équipe 1
    statsQuery.prepare(
        "SELECT "
        "SUM(CASE WHEN (TEAM1ID = ? AND SCORE1 > SCORE2) OR (TEAM2ID = ? AND SCORE2 > SCORE1) THEN 1 ELSE 0 END) AS wins, "
        "COUNT(*) AS total "
        "FROM MATCHES WHERE TEAM1ID = ? OR TEAM2ID = ?");
    statsQuery.addBindValue(team1Id);
    statsQuery.addBindValue(team1Id);
    statsQuery.addBindValue(team1Id);
    statsQuery.addBindValue(team1Id);

    double winRate1 = 0.5;
    if(statsQuery.exec() && statsQuery.next()) {
        int wins = statsQuery.value("wins").toInt();
        int total = statsQuery.value("total").toInt();
        if(total > 0) winRate1 = static_cast<double>(wins) / total;
    }

    // Calcul équipe 2
    statsQuery.prepare(
        "SELECT "
        "SUM(CASE WHEN (TEAM1ID = ? AND SCORE1 > SCORE2) OR (TEAM2ID = ? AND SCORE2 > SCORE1) THEN 1 ELSE 0 END) AS wins, "
        "COUNT(*) AS total "
        "FROM MATCHES WHERE TEAM1ID = ? OR TEAM2ID = ?");
    statsQuery.addBindValue(team2Id);
    statsQuery.addBindValue(team2Id);
    statsQuery.addBindValue(team2Id);
    statsQuery.addBindValue(team2Id);

    double winRate2 = 0.5;
    if(statsQuery.exec() && statsQuery.next()) {
        int wins = statsQuery.value("wins").toInt();
        int total = statsQuery.value("total").toInt();
        if(total > 0) winRate2 = static_cast<double>(wins) / total;
    }

    // Calcul des cotes
    double cote1 = 1.0 / winRate1;
    double cote2 = 1.0 / winRate2;
    double coteX = (cote1 + cote2) / 2;

    ui->Cote1->setText(QString::number(cote1, 'f', 2));
    ui->CoteX->setText(QString::number(coteX, 'f', 2));
    ui->Cote2->setText(QString::number(cote2, 'f', 2));
}

QString PronosticDialog::getRecentTeamForm(int teamId)
{
    QSqlQuery formQuery;
    formQuery.prepare(
        "SELECT SCORE, TEAM1ID, TEAM2ID FROM MATCHES "
        "WHERE (TEAM1ID = ? OR TEAM2ID = ?) "
        "ORDER BY MATCHDATE DESC LIMIT 5");
    formQuery.addBindValue(teamId);
    formQuery.addBindValue(teamId);

    QString form;
    if(formQuery.exec()) {
        while(formQuery.next()) {
            QString score = formQuery.value("SCORE").toString();
            int t1 = formQuery.value("TEAM1ID").toInt();
            int t2 = formQuery.value("TEAM2ID").toInt();

            QStringList scores = score.split('-');
            if(scores.size() == 2) {
                int s1 = scores[0].toInt();
                int s2 = scores[1].toInt();

                if((teamId == t1 && s1 > s2) || (teamId == t2 && s2 > s1)) {
                    form += "W";
                } else if(s1 == s2) {
                    form += "D";
                } else {
                    form += "L";
                }
            }
        }
    }
    return form;
}

QString PronosticDialog::getTeamName(int teamId)
{
    QSqlQuery query;
    query.prepare("SELECT NAME FROM TEAMS WHERE TEAMID = ?");
    query.addBindValue(teamId);
    if(query.exec() && query.next()) {
        return query.value("NAME").toString();
    }
    return tr("Équipe inconnue");
}

PronosticDialog::~PronosticDialog()
{
    delete ui;
}
