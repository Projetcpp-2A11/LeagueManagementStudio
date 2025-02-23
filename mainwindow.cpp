#include "mainwindow.h"
#include "homepage.h"
#include "qbuffer.h"
#include "ui_mainwindow.h"
#include "employeepage.h"
#include <qtimer.h>
#include <QProcess>
#include <QMessageBox>
#include <QAudioInput>
#include <QMediaDevices>
#include <QEventLoop>
#include <QFile>
#include <QDir>


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

        homepage *  homePage = new homepage();
        homePage->show();
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
    qDebug() << "Current Directory: " << QDir::currentPath();

    arguments << "../../faceRecogScript.py";

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

void MainWindow::startSpeechRecognition()
{
    QProcess *process = new QProcess(this);
    process->setProgram("python");

    process->setArguments(QStringList() << "../../speechRecognition.py");

    // Show "Recording..." message
    QMessageBox *recordingBox = new QMessageBox(this);
    recordingBox->setText("🎤 Recording...");
    recordingBox->setIcon(QMessageBox::Information);
    recordingBox->setStandardButtons(QMessageBox::NoButton);
    recordingBox->show();

    connect(process, &QProcess::finished, this, [=]() {
        recordingBox->hide(); // Hide the recording message

        QString recognizedText = process->readAllStandardOutput().trimmed();
        if (recognizedText.startsWith("ERROR")) {
            QMessageBox::warning(this, "Speech Recognition", recognizedText);
        } else {
            ui->password->setText(recognizedText);
            qDebug() << "Recognized text: " << recognizedText;
        }

        process->deleteLater();
    });

    process->start();
}


void MainWindow::on_vocalRecogButton_clicked()
{
    QMessageBox *msgBox = new QMessageBox(this);
    msgBox->setText("Recording starts in 3...");
    msgBox->setIcon(QMessageBox::Information);
    msgBox->setStandardButtons(QMessageBox::NoButton);
    msgBox->show();

    int delay = 1000;  // 1 second per countdown step

    // Countdown steps
    QTimer::singleShot(delay, this, [=]() { msgBox->setText("Recording starts in 2..."); });
    QTimer::singleShot(delay * 2, this, [=]() { msgBox->setText("Recording starts in 1..."); });

    // Start recording after countdown
    QTimer::singleShot(delay * 3, this, [=]() {
        msgBox->hide();
        startSpeechRecognition();
    });
}

