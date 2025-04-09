#include "homepage.h"
#include "employeepage.h"
#include "matchpage.h"
#include "qdatetime.h"
#include "qtimer.h"
#include "ui_homepage.h"
#include <QCamera>
#include <QImageCapture>
#include <QMediaCaptureSession>
#include <QVideoWidget>
#include <QMediaDevices>
#include <QMessageBox>
#include <QDir>
#include <QDebug>


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
    ui->AccountSettingsGrpBox->setVisible(false);
    setupRoleAccess(loggedInEmployee);


}

homepage::~homepage()
{
    delete ui;
}


// homepage methods
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
void homepage::on_myAccountButton_clicked()
{
    ui->AccountSettingsGrpBox->setVisible(true);
}


void homepage::on_closeButton_clicked() // close face id window
{
    ui->AccountSettingsGrpBox->setVisible(false);


}

void homepage::on_configureFidButton_clicked()
{
    // Validate employee data
    if (!emp) {
        QMessageBox::warning(this, "Error", "Employee data not available!");
        return;
    }

    QString userId = QString::number(emp->getUserID());
    if (userId.isEmpty()) {
        QMessageBox::warning(this, "Error", "Invalid user ID!");
        return;
    }

    // Save to project directory (./img/)
    QString projectDir = QDir::cleanPath(QCoreApplication::applicationDirPath() + "/../../..");
    QString saveDir = projectDir + "/img/";

    // Rest of your code remains the same...
    if (!QDir().mkpath(saveDir)) {
        QMessageBox::warning(this, "Error", "Failed to create save directory!");
        return;
    }

    // Check for available cameras
    auto cameras = QMediaDevices::videoInputs();
    if (cameras.isEmpty()) {
        QMessageBox::warning(this, "Error", "No camera found!");
        return;
    }

    // Create a dialog for camera preview
    QDialog *captureDialog = new QDialog(this);
    captureDialog->setWindowTitle("Configure Face ID");
    captureDialog->setMinimumSize(800, 600);

    // Set up media capture
    QMediaCaptureSession *captureSession = new QMediaCaptureSession(captureDialog);
    QCamera *camera = new QCamera(cameras.first(), captureDialog);
    QVideoWidget *viewfinder = new QVideoWidget(captureDialog);

    // Configure viewfinder
    viewfinder->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    viewfinder->setAspectRatioMode(Qt::KeepAspectRatio);

    // Set up image capture
    QImageCapture *imageCapture = new QImageCapture(captureDialog);
    imageCapture->setQuality(QImageCapture::HighQuality); // Set high quality

    // Configure the capture session
    captureSession->setCamera(camera);
    captureSession->setVideoOutput(viewfinder);
    captureSession->setImageCapture(imageCapture);

    // Add capture button
    QPushButton *captureButton = new QPushButton("Capture", captureDialog);
    captureButton->setFixedSize(150, 40);

    // Layout setup
    QVBoxLayout *layout = new QVBoxLayout(captureDialog);
    layout->addWidget(viewfinder, 1);
    layout->addWidget(captureButton, 0, Qt::AlignHCenter);

    // Connect capture button
    connect(captureButton, &QPushButton::clicked, this, [=]() {
        QString filePath = saveDir + userId + ".jpg";

        if (imageCapture->captureToFile(filePath)) {
            QMessageBox::information(this, "Success", "Face ID saved successfully!");
            captureDialog->accept();
        } else {
            QMessageBox::warning(this, "Error", "Failed to capture image!");
        }
    });

    // Handle errors
    connect(imageCapture, &QImageCapture::errorOccurred, this, [=](int id, QImageCapture::Error error, const QString &errorString) {
        QMessageBox::warning(this, "Error", "Capture failed: " + errorString);
        captureDialog->reject();
    });

    // Start camera and show dialog
    camera->start();
    captureDialog->exec();

    // Clean up when dialog closes
    camera->stop();
}






















 // modules
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










