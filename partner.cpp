#include "partner.h"
#include "qdatetime.h"
#include "qheaderview.h"
#include "qsqlerror.h"
#include "partner.h"
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QDate>

Partner::Partner(QString nom)
{
    this->nom = nom;

}

bool Partner::ajouter()
{
    QSqlQuery query;

    QString res = QString::number(id);

    // prepare() prend la requête en paramètre pour la préparer à l'exécution.
    query.prepare("INSERT INTO PARTNERS ( NAME) "
                  "VALUES (:nom)");

    // Création des variables liées
    query.bindValue(":nom", nom);


    // exec() envoie la requête pour l'exécuter
    return query.exec();
}

void Partner::listSponsorshipsInTable(QTableWidget *table)
{

    table->setRowCount(0);    // Reset row count
    table->verticalHeader()->setVisible(false);  // Hide vertical header
    QSqlQuery query;
    query.prepare(R"(
        SELECT p.name AS partner_name,
               t.name AS team_name,
               s.name AS stadium_name,
               sp.sponsorshipstartdate AS start_date,
               sp.sponsorshipenddate AS end_date
        FROM sponsorships sp
        JOIN partners p ON sp.partnerid = p.partnerid
        JOIN teams t ON sp.teamid = t.teamid
        LEFT JOIN stadium s ON sp.stadiumid = s.stadiumid
    )");

    if (query.exec()) {
        int row = 0;  // Row index for table
        while (query.next()) {
            table->insertRow(row);
           table->setItem(row, 0, new QTableWidgetItem(query.value("partner_name").toString()));
            table->setItem(row, 1, new QTableWidgetItem(query.value("team_name").toString()));
            table->setItem(row, 2, new QTableWidgetItem(query.value("stadium_name").toString()));

           table->setItem(row, 3, new QTableWidgetItem(query.value("start_date").toDate().toString("yyyy-MM-dd")));
            table->setItem(row, 4, new QTableWidgetItem(query.value("end_date").toDate().toString("yyyy-MM-dd")));
            table->item(row, 0)->setData(Qt::UserRole, query.value(0).toInt());  // Store partner ID

            row++; // Move to the next row
        }
    } else {
        qDebug() << "Failed to fetch sponsorship data: " << query.lastError().text();
    }


}


bool Partner::addSponsorship(int teamID, int stadiumID, int partnerID, const QDate &startDate, const QDate &endDate)
{
    QSqlQuery query;
    query.clear();

    query.prepare(R"(
        INSERT INTO SPONSORSHIPS (TEAMID, STADIUMID, PARTNERID, SPONSORSHIPSTARTDATE, SPONSORSHIPENDDATE)
        VALUES (:teamID, :stadiumID, :partnerID, TO_DATE(:startDate, 'YYYY-MM-DD'), TO_DATE(:endDate, 'YYYY-MM-DD'))
    )");

    // Ensure teamID and stadiumID are either valid or NULL
    QVariant teamVal = teamID > 0 ? QVariant(teamID) : QVariant();
    QVariant stadiumVal = stadiumID > 0 ? QVariant(stadiumID) : QVariant();

    query.bindValue(":teamID", teamVal);
    query.bindValue(":stadiumID", stadiumVal);


    query.bindValue(":partnerID", QVariant(partnerID));  // PartnerID should always be valid

    // Convert QDate to string format for Oracle
    query.bindValue(":startDate", startDate.toString("yyyy-MM-dd"));
    query.bindValue(":endDate", endDate.toString("yyyy-MM-dd"));

    // Debugging to check bound values
    qDebug() << "Executing query with values:";
    qDebug() << "Team ID:" << teamID;
    qDebug() << "Stadium ID:" << stadiumID;
    qDebug() << "Partner ID:" << partnerID;
    qDebug() << "Start Date:" << startDate.toString("yyyy-MM-dd");
    qDebug() << "End Date:" << endDate.toString("yyyy-MM-dd");

    if (query.exec()) {
        return true;
    }

    qDebug() << "Failed to add sponsorship: " << query.lastError().text();
    return false;
}

bool Partner::deleteSponsorship(int partnerId, int teamId)
{
    QSqlQuery query;
    query.prepare("DELETE FROM SPONSORSHIPS WHERE PARTNERID = :partnerId AND TEAMID = :teamId");
    query.bindValue(":partnerId", partnerId);
    query.bindValue(":teamId", teamId);
    return query.exec();  // Exécuter la suppression
}


int Partner::getStadiumIdByName(const QString &stadiumName) {
    QSqlQuery query;
    query.prepare("SELECT STADIUMID FROM STADIUM WHERE NAME = :stadiumName");
    query.bindValue(":stadiumName", stadiumName);
    if (query.exec() && query.next()) {
        return query.value(0).toInt();
    }
    return -1;  // Retourner -1 si le stade n'est pas trouvé
}

int Partner::getTeamIdByName(const QString &teamName) {
    QSqlQuery query;
    query.prepare("SELECT TEAMID FROM TEAMS WHERE NAME = :teamName");
    query.bindValue(":teamName", teamName);
    if (query.exec() && query.next()) {
        return query.value(0).toInt();
    }
    return -1;  // Retourner -1 si l'équipe n'est pas trouvée
}

Partner Partner::getPartnerById(int partnerId)
{
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query(db);

    // Préparer la requête pour récupérer un partenaire par son ID
    query.prepare("SELECT * FROM PARTNERS WHERE PARTNERID = :partnerId");
    query.bindValue(":partnerId", partnerId);

    if (query.exec() && query.next()) {
        Partner partner;
        partner.setID(query.value("PARTNERID").toInt());  // Utiliser setID au lieu de setId
        partner.setNom(query.value("NAME").toString());  // Utilisez setNom ici au lieu de setName
        partner.setTeamName(query.value("TEAMNAME").toString());  // Assurez-vous que la colonne TEAMNAME existe
        partner.setStadiumName(query.value("STADIUMNAME").toString());  // Idem pour STADIUMNAME
        partner.setStartDate(query.value("SPONSORSHIPSTARTDATE").toDate());
        partner.setEndDate(query.value("SPONSORSHIPENDDATE").toDate());
        return partner;
    }

    return Partner();  // Retourne un objet Partner vide si l'ID n'a pas été trouvé
}


bool Partner::updatePartnerInfo(int partnerId, const QString &newName,
                                const QString &newTeamName, const QString &newStadiumName,
                                const QDate &newStartDate, const QDate &newEndDate) {
    // Récupérer les IDs des équipes et des stades
    int newTeamId = getTeamIdByName(newTeamName);
    if (newTeamId == -1) {
        qWarning() << "Équipe introuvable: " << newTeamName;
        return false;
    }

    int newStadiumId = getStadiumIdByName(newStadiumName);
    if (newStadiumId == -1) {
        qWarning() << "Stade introuvable: " << newStadiumName;
        return false;
    }

    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query(db);

    db.transaction();  // Démarre une transaction

    // Mise à jour de PARTNERS (juste le nom)
    query.prepare("UPDATE PARTNERS SET NAME = :newName WHERE PARTNERID = :partnerId");
    query.bindValue(":newName", newName);
    query.bindValue(":partnerId", partnerId);

    if (!query.exec()) {
        db.rollback();
        return false;
    }

    // Mise à jour de SPONSORSHIPS
    query.prepare(R"(
        UPDATE SPONSORSHIPS
        SET TEAMID = :newTeamId, STADIUMID = :newStadiumId,
            SPONSORSHIPSTARTDATE = :newStartDate, SPONSORSHIPENDDATE = :newEndDate
        WHERE PARTNERID = :partnerId
    )");

    query.bindValue(":newTeamId", newTeamId);
    query.bindValue(":newStadiumId", newStadiumId);
    query.bindValue(":newStartDate", newStartDate);
    query.bindValue(":newEndDate", newEndDate);
    query.bindValue(":partnerId", partnerId);

    if (!query.exec()) {
        db.rollback();
        return false;
    }

    db.commit();  // Valide la transaction
    return true;
}
////*---------------------------------------------------------------------------------------------
