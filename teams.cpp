#include "teams.h"
#include "connection.h"
#include "qcontainerfwd.h"
#include "qheaderview.h"
#include "qsqlerror.h"
#include <QSignalMapper>

// Getters and Setters
int teams::getTeamID() const
{
    return teamID;
}

void teams::setTeamID(int newTeamID)
{
    teamID = newTeamID;
}

QString teams::getName() const
{
    return name;
}

void teams::setName(const QString &newName)
{
    name = newName;
}

QString teams::getContry() const
{
    return contry;
}

void teams::setContry(const QString &newContry)
{
    contry = newContry;
}

QString teams::getLogo() const
{
    return logo;
}

void teams::setLogo(const QString &newLogo)
{
    logo = newLogo;
}

int teams::getNbsubscribers() const // Changed return type to int
{
    return nbsubscribers;
}

void teams::setNbsubscribers(const int &newNbsubscribers)
{
    nbsubscribers = newNbsubscribers;
}

QString teams::getKit() const
{
    return kit;
}

void teams::setKit(const QString &newKit)
{
    kit = newKit;
}

int teams::getMatchesPlayed() const // Changed return type to int
{
    return matchesplayed;
}

void teams::setMatchesPlayed(const int &newMatchesPlayed)
{
    matchesplayed = newMatchesPlayed;
}

// Constructor
teams::teams() {}

teams::teams(const QString &name, const QString &contry, const QString &logo, const int &nbsubscribers, const QString &kit, const int &matchesplayed)
    : name(name), contry(contry), logo(logo), nbsubscribers(nbsubscribers), kit(kit), matchesplayed(matchesplayed)
{}

// Generate Team ID
QString teams::generateTeamsID(const QString &name, const QString &contry, const QString &logo, const int &nbsubscribers, const QString &kit, const int matchesplayed)
{
    Q_UNUSED(contry); // Mark unused parameters to avoid warnings
    Q_UNUSED(logo);
    Q_UNUSED(nbsubscribers);
    Q_UNUSED(kit);
    Q_UNUSED(matchesplayed);

    QString month = QDate::currentDate().toString("MM");
    int randomNum = QRandomGenerator::global()->bounded(10, 100); // Random 2-digit number
    return QString("%1%2%3").arg(month).arg(name.left(2).toUpper()).arg(randomNum);
}

// CRUD Methods
bool teams::addTeams()
{
    QString teamId = generateTeamsID(this->name, this->contry, this->logo, this->nbsubscribers, this->kit, this->matchesplayed);

    QSqlQuery query;
    query.prepare("INSERT INTO TEAMS ( NAME, COUNTRY, LOGO, NBSUBSCRIBERS, KIT, MATCHESPLAYED) "
                  "VALUES (:teamid, :name, :country, :logo, :nbsubscribers, :kit, :matchesplayed)");

    query.bindValue(":name", name);
    query.bindValue(":country", contry);
    query.bindValue(":logo", logo);
    query.bindValue(":nbsubscribers", nbsubscribers);
    query.bindValue(":kit", kit);
    query.bindValue(":matchesplayed", matchesplayed);

    if (query.exec()) {
        qDebug() << "Team added successfully! TEAMID:" << teamId;
        return true;
    } else {
        qDebug() << "Error adding team:" << query.lastError().text();
        return false;
    }
}

void teams::listTeams(QTableWidget* table)
{
    table->clearContents();
    table->setRowCount(0);
    table->verticalHeader()->setVisible(false); // Fix for QHeaderView incomplete type

    QString queryStr = "SELECT TEAMID, NAME, COUNTRY, LOGO, NBSUBSCRIBERS, KIT, MATCHESPLAYED FROM TEAMS";
    QSqlQuery query;

    if (query.exec(queryStr)) {
        int row = 0;
        while (query.next()) {
            table->insertRow(row);
            table->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));  // TEAMID
            table->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));  // NAME
            table->setItem(row, 2, new QTableWidgetItem(query.value(2).toString()));  // COUNTRY
            table->setItem(row, 3, new QTableWidgetItem(query.value(3).toString()));  // LOGO
            table->setItem(row, 4, new QTableWidgetItem(query.value(4).toString()));  // NBSUBSCRIBERS
            table->setItem(row, 5, new QTableWidgetItem(query.value(5).toString()));  // KIT
            table->setItem(row, 6, new QTableWidgetItem(query.value(6).toString()));  // MATCHESPLAYED
            ++row;
        }
    } else {
        qDebug() << "Failed to fetch data: " << query.lastError();
    }
}

bool teams::updateTeamsUsingTeamId(int teamID)
{
    QSqlQuery query;
    query.prepare("UPDATE TEAMS SET NAME = :name, COUNTRY = :country, LOGO = :logo, NBSUBSCRIBERS = :nbsubscribers, KIT = :kit, MATCHESPLAYED = :matchesplayed "
                  "WHERE TEAMID = :teamid");

    query.bindValue(":name", this->name);
    query.bindValue(":country", this->contry);
    query.bindValue(":logo", this->logo);
    query.bindValue(":nbsubscribers", this->nbsubscribers);
    query.bindValue(":kit", this->kit);
    query.bindValue(":matchesplayed", this->matchesplayed);
    query.bindValue(":teamid", teamID);

    if (query.exec()) {
        qDebug() << "Team updated successfully! TEAMID:" << teamID;
        return true;
    } else {
        qDebug() << "Error updating team:" << query.lastError().text();
        return false;
    }
}

bool teams::deleteTeamsUsingTeamID(int teamID)
{
    QSqlQuery query;
    query.prepare("DELETE FROM TEAMS WHERE TEAMID = :teamid");
    query.bindValue(":teamid", teamID);

    if (query.exec()) {
        qDebug() << "Team with TEAMID" << teamID << "deleted successfully.";
        return true;
    } else {
        qDebug() << "Failed to delete team with TEAMID" << teamID << ":" << query.lastError();
        return false;
    }
}
