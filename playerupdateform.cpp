#include "playerupdateform.h"
#include "player.h"
#include "ui_playerupdateform.h"
#include "QSqlQuery"
#include "QSqlError"
#include <QDebug>

playerupdateform::playerupdateform(QWidget *parent, int playerId)
    : QWidget(parent)
    , ui(new Ui::playerupdateform)
{
    ui->setupUi(this);

    // Debug to check the passed playerID
    qDebug() << "PlayerID passed to the form:" << playerId;

    // Set the playerID label
    ui->playerIDLabel->setText(QString::number(playerId));

    populateTeamDropdown();
    // Fetch player details and populate the form
    QSqlQuery query;
    query.prepare("SELECT PLAYERID, FNAME, LNAME, PHONENUM, POSITION, STATUS, TEAMID FROM PLAYERS WHERE PLAYERID = :playerID");
    query.bindValue(":playerID", playerId);

    if (query.exec() && query.next()) {
        qDebug() << "Player found, fetching data...";

        // Set the data from the query result into the UI
        ui->firstName->setText(query.value("FNAME").toString());
        ui->lastName->setText(query.value("LNAME").toString());
        ui->phoneNum->setText(query.value("PHONENUM").toString());
        ui->position->setText(query.value("POSITION").toString());
        ui->status->setText(query.value("STATUS").toString());

        int currentTeamID = query.value("TEAMID").toInt();
        int index = ui->teamIDComboBox->findData(currentTeamID);

        if (index != -1) {
            ui->teamIDComboBox->setCurrentIndex(index);
        } else {
            qDebug() << "TeamID not found in the dropdown list.";
        }
    } else {
        // Debug: Check query execution error
        qDebug() << "Failed to fetch player data for PLAYERID" << playerId << ":" << query.lastError().text();
    }
}



playerupdateform::~playerupdateform()
{
    delete ui;
}

void playerupdateform::populateTeamDropdown()
{
    ui->teamIDComboBox->clear();

    QSqlQuery teamQuery;
    teamQuery.prepare("SELECT TEAMID FROM TEAMS");

    if (teamQuery.exec()) {
        while (teamQuery.next()) {
            int teamID = teamQuery.value(0).toInt();
            ui->teamIDComboBox->addItem(QString::number(teamID), teamID);
        }
    } else {
        qDebug() << "Failed to load TEAMIDs from TEAMS table:" << teamQuery.lastError();
    }
}

void playerupdateform::on_save_exit_clicked()
{
    QString firstName = ui->firstName->text();
    QString lastName = ui->lastName->text();
    QString position = ui->position->text();
    QString status = ui->status->text();
    QString phone = ui->phoneNum->text();
    int playerID = ui->playerIDLabel->text().toInt();
    int teamID = ui->teamIDComboBox->currentData().toInt(); // Get the selected teamID from QComboBox

    qDebug() << "PlayerID before update:" << playerID;  // Log playerID before update

    // Check if the playerID is valid
    if (playerID == 0) {
        qDebug() << "Invalid player ID. Update cannot be performed.";
        return;
    }

    Player playerToBeUpdated;

    if (playerToBeUpdated.updatePlayerUsingTeamID(playerID, firstName, lastName, position, status, phone, teamID))
    {
        qDebug() << "Player with PLAYERID" << playerID << "and TEAMID" << teamID << "updated successfully.";
    } else {
        qDebug() << "Failed to update player.";
    }

    this->close();
}

void playerupdateform::on_cancel_clicked()
{
    this->close();
}
