#ifndef TEAMS_H
#define TEAMS_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QRandomGenerator>
#include <QDate>
#include <QTableWidget>

class teams
{
private:
    int teamID;
    QString name;
    QString contry;
    QString logo;
    int nbsubscribers;
    QString kit;
    int matchesplayed;

public:
    teams();
    teams(const QString &name, const QString &contry, const QString &logo, const int &nbsubscribers, const QString &kit, const int &matchesplayed);

    // Getters and Setters
    int getTeamID() const;
    void setTeamID(int newTeamID);
    QString getName() const;
    void setName(const QString &newName);
    QString getContry() const;
    void setContry(const QString &newContry);
    QString getLogo() const;
    void setLogo(const QString &newLogo);
    int getNbsubscribers() const; // Changed return type to int
    void setNbsubscribers(const int &newNbsubscribers);
    QString getKit() const;
    void setKit(const QString &newKit);
    int getMatchesPlayed() const; // Changed return type to int
    void setMatchesPlayed(const int &newMatchesPlayed);

    // CRUD Methods
    bool addTeams();
    void listTeams(QTableWidget* table);
    bool updateTeamsUsingTeamId(int teamID);
    bool deleteTeamsUsingTeamID(int teamID);
    QString generateTeamsID(const QString &name, const QString &contry, const QString &logo, const int &nbsubscribers, const QString &kit, const int matchesplayed);
};

#endif // TEAMS_H
