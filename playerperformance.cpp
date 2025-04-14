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




