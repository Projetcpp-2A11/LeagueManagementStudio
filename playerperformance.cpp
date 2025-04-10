#include "playerperformance.h"
#include "qdialog.h"
#include "ui_playerperformance.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QPixmap>
#include <QDebug>

#include "playerperformance.h"
#include "ui_playerperformance.h"

PlayerPerformance::PlayerPerformance(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::playerperformance)  // Use lowercase 'p' here
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

    // 1. Get PLAYERID from Players table
    QSqlQuery query;
    query.prepare("SELECT PLAYERID FROM Players WHERE FNAME = :fname AND LNAME = :lname");
    query.bindValue(":fname", fname);
    query.bindValue(":lname", lname);

    int playerId = -1;
    if (query.exec() && query.next()) {
        playerId = query.value(0).toInt();  // Retrieve PLAYERID
    } else {
        qDebug() << "Failed to find player ID:" << query.lastError().text();
        return;
    }

    // 2. Get image path from IMG table
    query.prepare("SELECT IMG FROM PLAYERS WHERE FNAME = :fname AND LNAME = :lname");
    query.bindValue(":fname", fname);
    query.bindValue(":lname", lname);

    if (query.exec() && query.next()) {
        QString imgPath = query.value("IMG").toString(); // IMG is the column name
        if (!imgPath.isEmpty()) {
            QPixmap pix(imgPath);
            ui->labelImage->setPixmap(pix.scaled(100, 100, Qt::KeepAspectRatio));
        } else {
            qDebug() << "No image found for player:" << fname << lname;
        }
    } else {
        qDebug() << "Failed to load image:" << query.lastError().text();
    }

    // 3. Set name labels
    ui->labelFirstName->setText(fname);
    //ui->labelLastName->setText(lname);  // Restoring the last name label

    // 4. Get stats from PLAYERPERFORMANCE
    query.prepare("SELECT TOTALYELLOWCARDS, TOTALREDCARDS, NUMGOALS, NUMASSISTS, NUMSAVES, PLAYTIMEINMINUTES "
                  "FROM PLAYERPERFORMANCE WHERE PLAYERID = :playerId");
    query.bindValue(":playerId", playerId);

    if (query.exec() && query.next()) {
        // Fetch the total yellow and red cards
        int totalYellowCards = query.value("TOTALYELLOWCARDS").isNull() ? 0 : query.value("TOTALYELLOWCARDS").toInt();
        int totalRedCards = query.value("TOTALREDCARDS").isNull() ? 0 : query.value("TOTALREDCARDS").toInt();

        // Create labels for stats
        QLabel *goalsLabel = new QLabel("Goals:", this);
        QLabel *assistsLabel = new QLabel("Assists:", this);
        QLabel *savesLabel = new QLabel("Saves:", this);
        QLabel *yellowCardsLabel = new QLabel("Yellow Cards:", this);
        QLabel *redCardsLabel = new QLabel("Red Cards:", this);
        QLabel *playTimeLabel = new QLabel("Play Time:", this);

        // Set the style for the labels
        QString labelStyle = "color: yellow; font-weight: bold; font-size: 14px;";
        goalsLabel->setStyleSheet(labelStyle);
        assistsLabel->setStyleSheet(labelStyle);
        savesLabel->setStyleSheet(labelStyle);
        yellowCardsLabel->setStyleSheet(labelStyle);
        redCardsLabel->setStyleSheet(labelStyle);
        playTimeLabel->setStyleSheet(labelStyle);

        // Set text for the stats (set to the respective QLineEdit fields)
        ui->lineEditGoals->setText(QString::number(query.value("NUMGOALS").toInt()));
        ui->lineEditAssists->setText(QString::number(query.value("NUMASSISTS").toInt()));
        ui->lineEditSaves->setText(QString::number(query.value("NUMSAVES").toInt()));
        ui->lineEditYellows->setText(QString::number(totalYellowCards));
        ui->lineEditReds->setText(QString::number(totalRedCards));

        int playTime = query.value("PLAYTIMEINMINUTES").isNull() ? 0 : query.value("PLAYTIMEINMINUTES").toInt();
        ui->labelPlayTime->setText(QString::number(playTime) + " min");

        // Adjust the positions for labels
        goalsLabel->move(10, ui->lineEditGoals->y());
        assistsLabel->move(10, ui->lineEditAssists->y());
        savesLabel->move(10, ui->lineEditSaves->y());
        yellowCardsLabel->move(10, ui->lineEditYellows->y());
        redCardsLabel->move(10, ui->lineEditReds->y());
        playTimeLabel->move(10, ui->labelPlayTime->y());

        // Make QLineEdits read-only and hide the cursor
        ui->lineEditGoals->setReadOnly(true);
        ui->lineEditGoals->setCursor(Qt::BlankCursor);
        ui->lineEditAssists->setReadOnly(true);
        ui->lineEditAssists->setCursor(Qt::BlankCursor);
        ui->lineEditSaves->setReadOnly(true);
        ui->lineEditSaves->setCursor(Qt::BlankCursor);
        ui->lineEditYellows->setReadOnly(true);
        ui->lineEditYellows->setCursor(Qt::BlankCursor);
        ui->lineEditReds->setReadOnly(true);
        ui->lineEditReds->setCursor(Qt::BlankCursor);
    } else {
        qDebug() << "Failed to fetch performance stats:" << query.lastError().text();
    }
}




void PlayerPerformance::on_exitButton_clicked()
{
    // Close the PlayerPerformance window
    this->close();
}




