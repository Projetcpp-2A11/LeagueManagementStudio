#include "homepage.h"
#include "employeepage.h"
#include "matchpage.h"
#include "qdatetime.h"
#include "qtimer.h"
#include "ui_homepage.h"

homepage::homepage(QWidget *parent, employee * loggedInEmployee)
    : QWidget(parent) ,ui(new Ui::homepage)
    , emp(loggedInEmployee)
{
    setFixedSize(1000,800);
    QTimer *timer = new QTimer(this);
    qDebug() << "emp id" << loggedInEmployee->getUserID();
    qDebug() << "emp name" << loggedInEmployee->getFirstName();
    QString FullName = loggedInEmployee->getFirstName() + " " + loggedInEmployee->getLastName();


    connect(timer, &QTimer::timeout, [=]() {
        QDateTime current = QDateTime::currentDateTime();
        QString formattedTime = current.toString("hh:mm:ss - dddd, MMMM d yyyy");
       ui->timeLabel->setText(formattedTime);
    });

    timer->start(1000);
    ui->setupUi(this);
    ui->usernameLabel->setText(FullName);

    qDebug() <<  " dep "  << loggedInEmployee->getDepName();
    qDebug() <<  " pos "  << loggedInEmployee->getPosition();
    setupRoleAccess(loggedInEmployee);


}

homepage::~homepage()
{
    delete ui;
}

void homepage::setupRoleAccess(employee *  emp)
{
    QString employeeDepartmentName = emp->getDepName();
    QString pos = emp->getPosition();

    QList<QPushButton*> allButtons = {
        ui->employeeButton,
        ui->stadiumsButton,
        ui->playersButton,
        ui->matchsButton,
        ui->teamsButton,
        ui->partnersButton
    };

    for (QPushButton* btn : allButtons) {
        btn->setEnabled(false);
    }

    QMap<QString, QList<QPushButton*>> accessMap;
    accessMap["HR"] = { ui->employeeButton };
    accessMap["Municipality"] = { ui->stadiumsButton };
    accessMap["Commerce"] = { ui->partnersButton };
    accessMap["League"] = { ui->matchsButton };
    accessMap["Federation"] = { ui->playersButton };
    accessMap["Federation"] = { ui->teamsButton };

    if (accessMap.contains(employeeDepartmentName)) {
        for (QPushButton* btn : accessMap[employeeDepartmentName]) {
            btn->setEnabled(true);
        }
    }

    if (pos == "admin") {
        for (QPushButton* btn : allButtons) {
            btn->setEnabled(true);
        }
    }









}



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
}

