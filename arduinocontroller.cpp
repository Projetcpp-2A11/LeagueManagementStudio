#include "arduinocontroller.h"
#include "match.h"
#include "player.h"
#include "qdir.h"
#include "qmessagebox.h"
#include "qtimer.h"
#include "stadium.h"
#include "teams.h"
#include "ui_arduinocontroller.h"

arduinocontroller::arduinocontroller(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::arduinocontroller)
{
    ui->setupUi(this);

    ui->tabWidget->setVisible(false);

    varArd     = new LMSVAR(this);
    timerArd   = new LMSTIMER(this);
    penaltyArd = new LMSPENALTY(this);

    //connect(varArd,     &LMSVAR::varSignal,     this, &arduinocontroller::handleVar);
    //connect(timerArd,   &LMSTIMER::timerSignal, this, &arduinocontroller::handleTimer);
    connect(penaltyArd, &LMSPENALTY::penaltySignal, this, &arduinocontroller::handlePenalty);
    connect(varArd, &LMSVAR::scoresReceived, this, &arduinocontroller::updateScoreUI);

    intializeUI();




}

arduinocontroller::~arduinocontroller()
{
    delete ui;
}



void arduinocontroller::on_pushButton_clicked() // check id existance
{
    matchID = ui->matchIdInput->text().toInt();
    Match  * match = Match::findMatchById(matchID);
    if ( match!=nullptr) {
        currentMatch = match;
        ui->tabWidget->setVisible(true);
        displayMatchInfo();



    } else {


        QMessageBox::critical(this, "Error", "Match not found");

    }



}

void arduinocontroller::handlePenalty(QString info)
{
    qDebug() << " Penalty Info :" << info;
    UiAnimationHelper::fadeInWidget(ui->PenaltynotificationGroupBox,1000);
    if(info=="YELLOWCARD") {
        ui->cardTypeLabel->setText("The Referee Has issued a Yellow card");
        ui->cardColorLabel->setStyleSheet("background:yellow;");
        lastPenaltySignal="YELLOW";
    } else if(info=="REDCARD") {
        ui->cardTypeLabel->setText("The Referee Has issued a Red card");
        ui->cardColorLabel->setStyleSheet("background:red");
        lastPenaltySignal="RED";
    }
}

void arduinocontroller::intializeUI()
{
    ui->connectionSucessGreenMark->setVisible(false);
    ui->PenaltyConnctSuccessGreenMark->setVisible(false);
    ui->notificationGroupBox->setVisible(false);
    ui->PenaltynotificationGroupBox->setVisible(false);
    countdownTimer = new QTimer(this);
    connect(countdownTimer, &QTimer::timeout, this, &arduinocontroller::updateCountdown);
    isCancelled = false;
    ui->savingChangedLabel->setText("");

}






void arduinocontroller::on_resetTimerBtn_clicked()
{
}



////// var methods








///




void arduinocontroller::on_connectVAR_clicked()
{
    int rc = varArd->begin();
    if (rc != 0 ) {
            //error
    } else {
        qDebug() << "Var connected";



    }
}




void arduinocontroller::on_connectTimer_clicked()
{
    int rc = timerArd->begin();
    if ( rc!=0) {
        qDebug() << "TIMER NOT  CONNECTED";

    } else {
        qDebug() << "TIMER CONNECTED";
        ui->connectionSucessGreenMark->setVisible(true);
        QTimer::singleShot(500, this, [this]() {
            ui->connectTimer->setDisabled(true);
        });






}
}

void arduinocontroller::updateCountdown()
{
    secondsLeft--;

    if (secondsLeft > 0) {
        ui->savingChangedLabel->setText(QString("Applying changes in %1 seconds...").arg(secondsLeft));
    }
    else {
        countdownTimer->stop();
        ui->cancelChangesButton->setEnabled(false);
        ui->savingChangedLabel->setText(""); // clear label when finished

        if (!isCancelled) {
            int time = ui->addTimeNumbers->text().toInt();
            qDebug() << "Match ID" << matchID;

            currentMatch->updateAdditonalTime(matchID,time);
        }

        UiAnimationHelper::fadeOutWidget(ui->notificationGroupBox, 1000);

    }
}

void arduinocontroller::displayMatchInfo()
{
    teams tms;
    Stadium stdm;
    QString stadiumName;



    int Team1ID = currentMatch->getTeam1ID();
    int Team2ID = currentMatch->getTeam2ID();
    teams teamA = tms.getTeamById(Team1ID);
    teams teamB = tms.getTeamById(Team2ID);
    stadiumName = stdm.getStadiumNameById(currentMatch->getStadiumID());

    //

    QString basePath = QDir::currentPath() + "/../../logos/";
    QPixmap team1Logo(basePath + teamA.getLogo());
    QPixmap team2Logo(basePath + teamB.getLogo());

    if (!team1Logo.isNull()) {
        ui->team1LogoLabel->setPixmap(team1Logo.scaled(100, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    } else {
        qDebug() << "Failed to load logo for Team 1";
    }

    if (!team2Logo.isNull()) {
        ui->team2LogoLabel->setPixmap(team2Logo.scaled(100, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    } else {
        qDebug() << "Failed to load logo for Team 2";
    }

    ui->TeamAName->setText(teamA.getName());
    ui->TeamBName->setText(teamB.getName());
    ui->StadiumName->setText(stadiumName);


}

void arduinocontroller::updateScoreUI(int teamAScore, int teamBScore)
{
    ui->TeamBScoreLabel->setText(QString::number(teamAScore));
    ui->TeamAScoreLabel->setText(QString::number(teamBScore));
}





void arduinocontroller::on_connectPenalty_clicked()
{
    int rc = penaltyArd->begin();
    if ( rc!=0) {
        qDebug() << "Penalty NOT CONNECTED";

    } else {
        qDebug("Penalty CONNECTED");
        ui->PenaltyConnctSuccessGreenMark->setVisible(true);
        QTimer::singleShot(500, this, [this]() {
            ui->connectPenalty->setDisabled(true);
        });

    }
}


void arduinocontroller::on_cancelChangesButton_clicked()
{
    isCancelled = true;
    countdownTimer->stop();
    ui->cancelChangesButton->setDisabled(true);
    ui->savingChangedLabel->setText("Cancelled");
    UiAnimationHelper::fadeOutWidget(ui->notificationGroupBox, 1000);

}


void arduinocontroller::on_validatePlayerNum_clicked()
{
    int playerNum = ui->playerNumInput->text().toInt();
    Player p;
    Player player=p.getPlayerByNum(playerNum);
    if(player.getFirstName() == "")  {
        qDebug() << "Player not found";
        ui->errorLabel->setText("Invalid Player");
    } else if ( player.getTeamId() != currentMatch->getTeam1ID() && player.getTeamId() != currentMatch->getTeam2ID()) {
        qDebug() << "Player isnt in the match";
        qDebug() << "Player Team ID" << player.getTeamId();
        ui->errorLabel->setText("This Player isnt on the match");

    } else {
        qDebug() << "Player Found , FName : " << player.getFirstName() << "LNAME :" << player.getLastName();
        int signal = lastPenaltySignal == "RED" ? 1:0;
        if( player.addPenaltyToPlayer(signal,player.getPlayerId())) {
            QString message = "Player" + player.getFirstName() + player.getLastName(); " Has Recieved a " + lastPenaltySignal+ " Card" ;
            ui->sucessMessage->setText(message);
        } else {
            qDebug() << "Error adding penalty to DB";
        }
    }









}


void arduinocontroller::on_ConfigureMatchBtn_clicked()
{
    QString teamA = ui->TeamAName->text().trimmed();
    QString teamB = ui->TeamBName->text().trimmed();

    if (teamA.isEmpty() || teamB.isEmpty()) {
        ui->errorLabel->setText("Both team names are required!");
        return;
    }

    QString msgA = "TEAMA " + teamA + "\n";
    QString msgB = "TEAMB " + teamB + "\n";

    // Assuming you're using varArd to send to Arduino
    varArd->write_to_arduino(msgA.toUtf8());
    varArd->write_to_arduino(msgB.toUtf8());

    //ui->errorLabel->setText("Match configuration sent.");
}


void arduinocontroller::on_GoLiveBtn_clicked()
{
    varArd->close_arduino();

}


void arduinocontroller::on_EndMatchBtn_clicked()
{
    varArd->connect();
    varArd->write_to_arduino("GETSCORES\n");

}

