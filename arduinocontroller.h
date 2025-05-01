#ifndef ARDUINOCONTROLLER_H
#define ARDUINOCONTROLLER_H
#include "lmspenalty.h"
#include "lmstimer.h"
#include "lmsvar.h"
#include <arduino.h>
#include "match.h"
#include "uianimationhelper.h"

#include <QWidget>

namespace Ui {
class arduinocontroller;
}

class arduinocontroller : public QWidget
{
    Q_OBJECT

public:
    explicit arduinocontroller(QWidget *parent = nullptr);
    ~arduinocontroller();

    void handleVar(QString info);
    void handleTimer(int time);
    void handlePenalty(QString info);
    void intializeUI();

    void updateCountdown();
    void displayMatchInfo();
    void updateScoreUI(int teamAScore , int teamBScore);
private slots:
    void on_pushButton_clicked();




    void on_resetTimerBtn_clicked();

    void on_connectVAR_clicked();

    void on_connectTimer_clicked();

    void on_connectPenalty_clicked();

    void on_cancelChangesButton_clicked();

    void on_validatePlayerNum_clicked();

    void on_ConfigureMatchBtn_clicked();

    void on_GoLiveBtn_clicked();

    void on_EndMatchBtn_clicked();


    void on_SaveMatchBtn_clicked();

protected:
    Ui::arduinocontroller *ui;
    arduino *ard = new arduino();
    LMSVAR * varArd;
    LMSTIMER * timerArd;
    LMSPENALTY * penaltyArd;
    Match * currentMatch;
    int matchID;
private:
    QTimer* countdownTimer;
    int secondsLeft;
    bool isCancelled;
    QString lastPenaltySignal ="";



};

#endif // ARDUINOCONTROLLER_H
