#include "homepage.h"
#include "matchpage.h"
#include "qdatetime.h"
#include "qtimer.h"
#include "ui_homepage.h"

homepage::homepage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::homepage)
{
    setFixedSize(1000,800);
    QTimer *timer = new QTimer(this);

    connect(timer, &QTimer::timeout, [=]() {
        QDateTime current = QDateTime::currentDateTime();
        QString formattedTime = current.toString("hh:mm:ss - dddd, MMMM d yyyy");
       ui->timeLabel->setText(formattedTime);
    });

    timer->start(1000);





    ui->setupUi(this);
}

homepage::~homepage()
{
    delete ui;
}
/*
void homepage::on_employeeButton_clicked()
{
    employeePage * employeepage = new employeePage();
    employeepage->show();
    this->hide();
}
*/



void homepage::on_matchsButton_clicked()
{

    MatchPage *mp =new MatchPage();
    mp->show();
    this->hide();
}

