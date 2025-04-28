#include "arduinocontroller.h"
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





}

arduinocontroller::~arduinocontroller()
{
    delete ui;
}

void arduinocontroller::on_pushButton_clicked() // check id existance
{
    bool matchExists = true;

    if ( matchExists) {
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




}

void arduinocontroller::handlePenalty(QString info)
{
    qDebug() << " Penalty Info :" << info;
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

