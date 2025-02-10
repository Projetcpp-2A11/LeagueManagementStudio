#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employeepage.h"
#include <qtimer.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_login_clicked()
{
    qDebug() << "Login Clicked";
    if ( ui->username->text().isEmpty() || ui->password->text().isEmpty() ) {
        ui->ErrorZone->setText("Login failed: Invalid credentials!");

    } else {
        ui->ErrorZone->setStyleSheet("color:white");
        ui->ErrorZone->setText("Login clicked");

        employeePage *  employe = new employeePage();
        employe->show();
        this->hide();


    }

    QTimer::singleShot(3000, this, [this]() {
        ui->ErrorZone->setText(""); // Clear the text
    });
}




void MainWindow::on_forgotPasswordClicked_clicked()
{
    qDebug() << "Forgot Password Clicked";
    ui->ErrorZone->setStyleSheet("color:white");
    ui->ErrorZone->setText("Forgot password clicked");
    QTimer::singleShot(3000,this,[this]() {
        ui->ErrorZone->setText("");

    });
}

