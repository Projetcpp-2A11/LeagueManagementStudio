#ifndef TEAMS_H
#define TEAMS_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QRandomGenerator>
#include <QDate>
#include <QTableWidget>
#include <QObject>

class teams : public QObject
{
    Q_OBJECT
private:
    int teamID;
    QString name;
    QString contry;
    QString logo;
    int nbsubscribers;
    QString kit;
    int matchesplayed;
    QTableWidget* tableWidget;

public:
    teams(): teamID(-1), name(""), contry(""), logo("") {}
    teams(const QString &name, const QString &contry, const QString &logo, const int &nbsubscribers, const QString &kit, const int &matchesplayed);
    teams(int id , QString name,QString logo,QString contry);

    // Getters and Setters
    int getTeamID() const;
    void setTeamID(int newTeamID);
    QString getName() const;
    void setName(const QString &newName);
    QString getContry() const;
    void setContry(const QString &newContry);
    QString getLogo() const;
    void setLogo(const QString &newLogo);
    int getNbsubscribers() const;
    void setNbsubscribers(const int &newNbsubscribers);
    QString getKit() const;
    void setKit(const QString &newKit);
    int getMatchesPlayed() const;
    void setMatchesPlayed(const int &newMatchesPlayed);

    // CRUD Methods
    bool addTeams();
    void listTeams(QTableWidget* table);
    bool updateTeamsUsingTeamId(int teamID, const QString& name, const QString& country, const QString& logo, int subscribers, const QString& kit, int matchesPlayed);
    bool deleteTeamsUsingTeamID(int teamID);
    QString generateTeamsID(const QString &name, const QString &contry, const QString &logo, const int &nbsubscribers, const QString &kit, const int matchesplayed);
    //void displayTeamStats();
    void displayTeamStats(QWidget *statsWidget);
    //dispal equie form
    void displayMatchesWithScores();


    // crud methods ll arduino

     teams getTeamById(int id);





private slots:
    //    void onCellClicked(int row, int column);
};


#endif // TEAMS_H
