#include "homepage.h"
<<<<<<< HEAD
#include "employeepage.h"
#include "matchpage.h"
=======
#include "Staduimpage.h"
>>>>>>> d87739afc8594a1567a22d28d94f597f500e3067
#include "qdatetime.h"
#include "qtimer.h"
#include "ui_homepage.h"

<<<<<<< HEAD
homepage::homepage(QWidget *parent, employee * loggedInEmployee)
    : QWidget(parent) ,ui(new Ui::homepage)
    , emp(loggedInEmployee)
{
    setFixedSize(1000,800);
    QTimer *timer = new QTimer(this);
    qDebug() << "emp id" << loggedInEmployee->getUserID();
    qDebug() << "emp name" << loggedInEmployee->getFirstName();
    QString FullName = loggedInEmployee->getFirstName() + " " + loggedInEmployee->getLastName();

=======
homepage::homepage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::homepage)
{
    setFixedSize(1000,800);
    QTimer *timer = new QTimer(this);
>>>>>>> d87739afc8594a1567a22d28d94f597f500e3067

    connect(timer, &QTimer::timeout, [=]() {
        QDateTime current = QDateTime::currentDateTime();
        QString formattedTime = current.toString("hh:mm:ss - dddd, MMMM d yyyy");
       ui->timeLabel->setText(formattedTime);
    });

    timer->start(1000);
<<<<<<< HEAD
    ui->setupUi(this);
    ui->usernameLabel->setText(FullName);

=======





    ui->setupUi(this);
>>>>>>> d87739afc8594a1567a22d28d94f597f500e3067
}

homepage::~homepage()
{
    delete ui;
}

<<<<<<< HEAD
void homepage::on_employeeButton_clicked()
{
    employeePage * employeepage = new employeePage(nullptr,this->emp);
    employeepage->show();
    delete this;
}


void homepage::on_matchsButton_clicked()
{
    matchPage* matchpage = new matchPage();
    matchpage->show();
    delete this;
=======
void homepage::on_stadiumsButton_clicked()
{
    stadiumPage * stadiumpage = new stadiumPage();
    stadiumpage->show();
    this->hide();
>>>>>>> d87739afc8594a1567a22d28d94f597f500e3067
}

