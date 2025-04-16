#ifndef PARTNER_H
#define PARTNER_H

#include "qtablewidget.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

class Partner
{
private:
    QString nom;
    int id;
    QString teamName;
    QString stadiumName;
    QDate startDate;
    QDate endDate;

public:
    // Constructeurs
    Partner() {}
    Partner(QString nom);

    // Getters
    QString getNom() const { return nom; }
    int getID() const { return id; }
    QString getTeamName() const { return teamName; }
    QString getStadiumName() const { return stadiumName; }
    QDate getStartDate() const { return startDate; }
    QDate getEndDate() const { return endDate; }

    // Setters
    void setNom(const QString &n) { nom = n; }
    void setID(int newID) { id = newID; }
    void setTeamName(const QString &name) { teamName = name; }
    void setStadiumName(const QString &name) { stadiumName = name; }
    void setStartDate(const QDate &date) { startDate = date; }
    void setEndDate(const QDate &date) { endDate = date; }

    // Fonctionnalités de Base relatives à l'entité Partner
    bool ajouter();
    void listSponsorshipsInTable(QTableWidget *table);

    bool addSponsorship(int teamID, int stadiumID, int partnerID, const QDate &startDate, const QDate &endDate);
    bool deleteSponsorship(int partnerId, int teamId);
    bool updatePartnerInfo(int partnerId, const QString &newName,
                           const QString &newTeamName, const QString &newStadiumName,
                           const QDate &newStartDate, const QDate &newEndDate);

    int getPartnerIdByName(const QString &partnerName) const;
    int getTeamIdByName(const QString &teamName) const;
    static Partner getById(int id);
    int getStadiumIdByName(const QString &stadiumName);
    int getTeamIdByName(const QString &teamName);
    QString getFullName() const;
    /*





*/

    static Partner getPartnerById(int partnerId);  // Static function to get Partner by ID
};

#endif // PARTNER_H
