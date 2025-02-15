#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employeepage.h"
#include <qtimer.h>
#include <QProcess>
#include <QMessageBox>

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


void MainWindow::on_facialRecogButton_clicked()
{
    QProcess process;

    QString pythonPath = "python";
    QStringList arguments;
    arguments << "C:/Users/choua/OneDrive/Bureau/Projet C++/LMS/faceRecogScript.py";

    process.start(pythonPath, arguments);

    process.waitForFinished();

    QString output = process.readAllStandardOutput();

    qDebug() << "Python script output:" << output;

    if (output.contains("True")) {
        qDebug() << "Face match found!";
        QMessageBox::information(this, "Face Recognition", "Face match found!");
        this->setCursor(Qt::WaitCursor);
        QTimer::singleShot(3000,this,[this]() {

            employeePage *  employe = new employeePage();
            employe->show();
            this->hide();


        });
    } else {
        qDebug() << "No face match found!";
        QMessageBox::warning(this, "Face Recognition", "No face match found.");
    }



}

