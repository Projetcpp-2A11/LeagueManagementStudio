#include "playerperformance.h"
#include "qboxlayout.h"
#include "qdialog.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QPixmap>
#include <QDebug>

#include "playerperformance.h"

PlayerPerformance::PlayerPerformance(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::playerperformance)
{
    ui->setupUi(this);
    // Create the dropdown (QComboBox) to select the match ID
    //matchComboBox = new QComboBox(this);
    // Step 1: Populate the ComboBox with match IDs when the dialog is shown
    populateMatchIDs();

    // Step 2: Connect the select button to fetch and display the match details
    connect(ui->selectMatchButton, &QPushButton::clicked, this, &PlayerPerformance::onSelectMatchClicked);
}


PlayerPerformance::~PlayerPerformance()
{
    delete ui;
}




void PlayerPerformance::setPlayer(const QString &fname, const QString &lname)
{
    qDebug() << "Setting player data: " << fname << lname;

    // Step 1: Fetch the player ID using first and last names
    QSqlQuery query;
    query.prepare("SELECT PLAYERID FROM Players WHERE FNAME = :fname AND LNAME = :lname");
    query.bindValue(":fname", fname);
    query.bindValue(":lname", lname);

    int playerId = -1;
    if (query.exec() && query.next()) {
        playerId = query.value(0).toInt();
        currentPlayerId = playerId;  // Assign the playerId to currentPlayerId
        qDebug() << "Found Player ID:" << playerId;
    } else {
        qDebug() << "Failed to find player ID:" << query.lastError().text();
        return;
    }

    // Step 2: Load player image
    query.prepare("SELECT IMG FROM PLAYERS WHERE PLAYERID = :playerId");
    query.bindValue(":playerId", playerId);

    if (query.exec() && query.next()) {
        QString imgPath = query.value("IMG").toString();
        qDebug() << "Image path:" << imgPath;

        if (!imgPath.isEmpty()) {
            QPixmap pix(imgPath);
            ui->labelImage->setPixmap(pix.scaled(100, 100, Qt::KeepAspectRatio));
        } else {
            qDebug() << "No image found for player:" << fname << lname;
        }
    } else {
        qDebug() << "Failed to load image:" << query.lastError().text();
    }

    // Set player name label
    ui->labelFirstName->setText("Player: " + fname + " " + lname);

    // Step 3: Fetch the most recent performance (latest MATCHID for player)
    QSqlQuery perfQuery;
    perfQuery.prepare("SELECT MATCHID, NUMYELLOWCARDS, NUMREDCARDS, NUMGOALS, NUMASSISTS, NUMSAVES, PLAYTIMEINMINUTES, RATE "
                      "FROM PLAYERPERFORMANCE "
                      "WHERE PLAYERID = :playerId AND MATCHID = (SELECT MAX(MATCHID) FROM PLAYERPERFORMANCE WHERE PLAYERID = :playerId)");
    perfQuery.bindValue(":playerId", playerId);

    if (perfQuery.exec()) {
        if (perfQuery.next()) {
            int matchId = perfQuery.value("MATCHID").toInt();
            int yellowCards = perfQuery.value("NUMYELLOWCARDS").toInt(); // This is for the specific match
            int redCards = perfQuery.value("NUMREDCARDS").toInt(); // This is for the specific match
            int goals = perfQuery.value("NUMGOALS").toInt();
            int assists = perfQuery.value("NUMASSISTS").toInt();
            int saves = perfQuery.value("NUMSAVES").toInt();
            int playTime = perfQuery.value("PLAYTIMEINMINUTES").toInt();
            double rate = perfQuery.value("RATE").toDouble();

            // Elegant style string
            QString labelStyle = "color: yellow; font-weight: bold; font-size: 14px;";

            // Create styled labels in front of each QLineEdit
            auto makeLabel = [&](const QString &text, QWidget *buddy) -> QLabel* {
                QLabel *label = new QLabel(text, this);
                label->setStyleSheet(labelStyle);
                label->move(buddy->x() - 140, buddy->y() + 2); // moved further left for more space
                label->show();
                return label;
            };

            makeLabel("Goals:", ui->lineEditGoals);
            makeLabel("Assists:", ui->lineEditAssists);
            makeLabel("Saves:", ui->lineEditSaves);
            makeLabel("Yellow Cards:", ui->lineEditYellows);
            makeLabel("Red Cards:", ui->lineEditReds);
            makeLabel("Play Time:", ui->labelPlayTimeValue);

            // Add label above the rating label
            QLabel *rateLabel = new QLabel("Rate", this);
            rateLabel->setStyleSheet(labelStyle);
            rateLabel->move(ui->labelRateValue->x(), ui->labelRateValue->y() - 20); // position above the rating label
            rateLabel->show();

            // Set values into UI fields
            ui->lineEditGoals->setText(QString::number(goals));
            ui->lineEditAssists->setText(QString::number(assists));
            ui->lineEditSaves->setText(QString::number(saves));
            ui->lineEditYellows->setText(QString::number(yellowCards)); // Set yellow cards here
            ui->lineEditReds->setText(QString::number(redCards)); // Set red cards here
            ui->labelPlayTimeValue->setText(QString::number(playTime) + " min");

            // Set Rating directly in the label (with styled text)
            ui->labelRateValue->setText(QString("<span style='font-weight:bold; color:#1E8449;'>%1</span>").arg(rate, 0, 'f', 2));

            qDebug() << "Latest Performance - MatchID:" << matchId
                     << "Goals:" << goals << "Assists:" << assists
                     << "Saves:" << saves << "Yellows:" << yellowCards
                     << "Reds:" << redCards << "PlayTime:" << playTime
                     << "Rate:" << rate;
        } else {
            qDebug() << "No valid performance records found for player.";
        }
    } else {
        qDebug() << "Failed to fetch player performances:" << perfQuery.lastError().text();
    }

    // Step 4: Make the fields read-only and disable cursor
    ui->lineEditGoals->setReadOnly(true);
    ui->lineEditAssists->setReadOnly(true);
    ui->lineEditSaves->setReadOnly(true);
    ui->lineEditYellows->setReadOnly(true);
    ui->lineEditReds->setReadOnly(true);

    ui->lineEditGoals->setCursor(Qt::BlankCursor);
    ui->lineEditAssists->setCursor(Qt::BlankCursor);
    ui->lineEditSaves->setCursor(Qt::BlankCursor);
    ui->lineEditYellows->setCursor(Qt::BlankCursor);
    ui->lineEditReds->setCursor(Qt::BlankCursor);
}


void PlayerPerformance::on_exitButton_clicked()
{
    // Close the PlayerPerformance window
    this->close();
}

void PlayerPerformance::populateMatchIDs() {
    // Query to fetch all match IDs from the playerperformance table
    QSqlQuery query;
    query.prepare("SELECT MATCHID FROM PLAYERPERFORMANCE");

    if (query.exec()) {
        while (query.next()) {
            int matchId = query.value(0).toInt();
            ui->matchComboBox->addItem(QString::number(matchId));  // Add each match ID to the ComboBox
        }
    } else {
        qDebug() << "Error fetching match IDs: " << query.lastError().text();
    }
}

void PlayerPerformance::onSelectMatchClicked() {
    // Debug: Check currentPlayerId before proceeding
    qDebug() << "currentPlayerId at the beginning: " << currentPlayerId;

    // Ensure the playerId is set
    if (currentPlayerId == -1) {
        qDebug() << "Player ID is not set. Cannot check match performance.";
        return;  // Exit early if player ID is not set
    }

    // Get the selected match ID from the ComboBox
    int selectedMatchId = ui->matchComboBox->currentText().toInt();  // Using the combo box directly from the UI
    qDebug() << "Selected Match ID: " << selectedMatchId;

    // Query to check if the player has a performance record in the selected match
    QSqlQuery query;
    query.prepare("SELECT 1 FROM PLAYERPERFORMANCE WHERE MATCHID = :matchId AND PLAYERID = :playerId");
    query.bindValue(":matchId", selectedMatchId);
    query.bindValue(":playerId", currentPlayerId);  // Using the stored playerId

    if (query.exec()) {
        if (query.next()) {
            // Player has played in this match
            qDebug() << "Player has played in this match.";

            // Fetch the player's performance stats from this match
            query.prepare("SELECT NUMYELLOWCARDS, NUMREDCARDS, NUMGOALS, NUMASSISTS, NUMSAVES, PLAYTIMEINMINUTES, RATE "
                          "FROM PLAYERPERFORMANCE WHERE MATCHID = :matchId AND PLAYERID = :playerId");
            query.bindValue(":matchId", selectedMatchId);
            query.bindValue(":playerId", currentPlayerId);

            if (query.exec() && query.next()) {
                int yellowCards = query.value("NUMYELLOWCARDS").toInt();
                int redCards = query.value("NUMREDCARDS").toInt();
                int goals = query.value("NUMGOALS").toInt();
                int assists = query.value("NUMASSISTS").toInt();
                int saves = query.value("NUMSAVES").toInt();
                int playTime = query.value("PLAYTIMEINMINUTES").toInt();
                double rate = query.value("RATE").toDouble();

                // Apply the same style used in the setPlayer function
                QString labelStyle = "color: yellow; font-weight: bold; font-size: 14px;";

                // Create styled labels in front of each QLineEdit
                auto makeLabel = [&](const QString &text, QWidget *buddy) -> QLabel* {
                    QLabel *label = new QLabel(text, this);
                    label->setStyleSheet(labelStyle);
                    label->move(buddy->x() - 140, buddy->y() + 2); // moved further left for more space
                    label->show();
                    return label;
                };

                // Create labels with the same style for each input
                makeLabel("Goals:", ui->lineEditGoals);
                makeLabel("Assists:", ui->lineEditAssists);
                makeLabel("Saves:", ui->lineEditSaves);
                makeLabel("Yellow Cards:", ui->lineEditYellows);
                makeLabel("Red Cards:", ui->lineEditReds);
                makeLabel("Play Time:", ui->labelPlayTimeValue);

                // Add label above the rating label
                QLabel *rateLabel = new QLabel("Rate", this);
                rateLabel->setStyleSheet(labelStyle);
                rateLabel->move(ui->labelRateValue->x(), ui->labelRateValue->y() - 20); // position above the rating label
                rateLabel->show();

                // Set values into UI fields
                ui->lineEditGoals->setText(QString::number(goals));
                ui->lineEditAssists->setText(QString::number(assists));
                ui->lineEditSaves->setText(QString::number(saves));
                ui->lineEditYellows->setText(QString::number(yellowCards)); // Set yellow cards here
                ui->lineEditReds->setText(QString::number(redCards)); // Set red cards here
                ui->labelPlayTimeValue->setText(QString::number(playTime) + " min");

                // Set Rating directly in the label (with styled text)
                ui->labelRateValue->setText(QString("<span style='font-weight:bold; color:#1E8449;'>%1</span>").arg(rate, 0, 'f', 2));

                qDebug() << "Latest Performance - MatchID:" << selectedMatchId
                         << "Goals:" << goals << "Assists:" << assists
                         << "Saves:" << saves << "Yellows:" << yellowCards
                         << "Reds:" << redCards << "PlayTime:" << playTime
                         << "Rate:" << rate;
            } else {
                qDebug() << "No valid performance records found for player.";
            }
        } else {
            qDebug() << "Player has not played in this match.";
        }
    } else {
        qDebug() << "Failed to fetch player performance data:" << query.lastError().text();
    }

    // Step 4: Make the fields read-only and disable cursor
    ui->lineEditGoals->setReadOnly(true);
    ui->lineEditAssists->setReadOnly(true);
    ui->lineEditSaves->setReadOnly(true);
    ui->lineEditYellows->setReadOnly(true);
    ui->lineEditReds->setReadOnly(true);

    ui->lineEditGoals->setCursor(Qt::BlankCursor);
    ui->lineEditAssists->setCursor(Qt::BlankCursor);
    ui->lineEditSaves->setCursor(Qt::BlankCursor);
    ui->lineEditYellows->setCursor(Qt::BlankCursor);
    ui->lineEditReds->setCursor(Qt::BlankCursor);
}



void PlayerPerformance::onPlayerSelected(const QString &fname, const QString &lname) {
    qDebug() << "Player selected: " << fname << lname;

    // Step 1: Fetch the player ID based on the name
    QSqlQuery query;
    query.prepare("SELECT PLAYERID FROM Players WHERE FNAME = :fname AND LNAME = :lname");
    query.bindValue(":fname", fname);
    query.bindValue(":lname", lname);

    if (query.exec() && query.next()) {
        currentPlayerId = query.value(0).toInt();  // Set the currentPlayerId
        qDebug() << "Found Player ID:" << currentPlayerId;
    } else {
        qDebug() << "Failed to find player ID:" << query.lastError().text();
        currentPlayerId = -1;  // Ensure it's set to -1 if no match is found
    }
}











