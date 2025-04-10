#ifndef MATCH_H
#define MATCH_H

#include "qdatetime.h"
#include "qtablewidget.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Match
{
private:


    int matchID;
    int team1ID;
    int team2ID;
    QDate datematch;
    QString score;
    int stadiumID;

public:
    // Constructeurs
    Match() {}
    Match(int team1ID, int team2ID, QDate date, QString score, int stadiumID);

    // Getters
    int getMatchID() { return matchID; }
    int getTeam1ID() { return team1ID; }
    int getTeam2ID() { return team2ID; }
    QDate getDateMatch() { return datematch; }
    QString getScore() { return score; }
    int getStadiumID() { return stadiumID; }

    // Setters
    void setMatchID(int id) { matchID = id; }
    void setTeam1ID(int id) { team1ID = id; }
    void setTeam2ID(int id) { team2ID = id; }
    void setDateMatch(QDate date) { datematch = date; }
    void setScore(QString sc) { score = sc; }
    void setStadiumID(int id) { stadiumID = id; }

    // Fonctionnalités de Base relatives à l'entité Match
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(int);
    void listMatchesInTable(QTableWidget *table);
    void displayTeamGoalStats();
  void searchMatches(const QString &searchText, const QList<QString> &filters, QTableWidget *matchsTable);

};

#endif // MATCH_H
