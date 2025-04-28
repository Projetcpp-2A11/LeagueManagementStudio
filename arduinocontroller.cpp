#include "arduinocontroller.h"
#include "match.h"
#include "qmessagebox.h"
#include "qtimer.h"
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

    connect(varArd,     &LMSVAR::varSignal,     this, &arduinocontroller::handleVar);
    connect(timerArd,   &LMSTIMER::timerSignal, this, &arduinocontroller::handleTimer);
    connect(penaltyArd, &LMSPENALTY::penaltySignal, this, &arduinocontroller::handlePenalty);
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
        delete match;
        ui->tabWidget->setVisible(true);


    } else {


        QMessageBox::critical(this, "Error", "Match not found");

    }


}

void arduinocontroller::handleVar(QString info)
{




}

void arduinocontroller::handleTimer(int time)
{

    qDebug() << "Time " << time;
    ui->addTimeNumbers->setText(QString::number(time));
    UiAnimationHelper::fadeInWidget(ui->notificationGroupBox,1000);
    secondsLeft = 10;
    isCancelled = false;
    ui->savingChangedLabel->setText(QString("Applying changes in %1 seconds...").arg(secondsLeft));
    ui->cancelChangesButton->setEnabled(true);
    countdownTimer->start(1000);






}

void arduinocontroller::handlePenalty(QString info)
{
    qDebug() << " Penalty Info :" << info;
}

void arduinocontroller::intializeUI()
{
    ui->connectionSucessGreenMark->setVisible(false);
    ui->notificationGroupBox->setVisible(false);
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
    } else { // connection successful



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





void arduinocontroller::on_connectPenalty_clicked()
{
    int rc = penaltyArd->begin();
    if ( rc!=0) {
        qDebug() << "Penalty NOT CONNECTED";

    } else {
        qDebug("Penalty CONNECTED");
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

