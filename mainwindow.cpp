#include "mainwindow.h"
#include "homepage.h"
#include "qboxlayout.h"
#include "qbuffer.h"
#include "qcamera.h"
#include "qimagecapture.h"
#include "qmediacapturesession.h"
#include "qsqlerror.h"
#include "qvideowidget.h"
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
    setWindowTitle("League Management Studio");
    setWindowIcon(QIcon(":/textures/textures/app_icon.png"));
    setFixedSize(1050,681);
    ui->passwordLabel->setVisible(false);
    ui->password->setVisible(false);
    ui->passwordToggleButton->setVisible(false);
    ui->vocalRecogButton->setVisible(false);
    ui->forgotPasswordClicked->setVisible(false);
    isPasswordVisible=false;
    ui->password->setEchoMode(QLineEdit::Password);
    ui->passwordToggleButton->setIcon(QIcon(":/textures/textures/visible.png"));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_login_clicked()
{
    qDebug() << "Login Clicked";
    int id = ui->username->text().toInt();
    employee *emp = new employee();
    *emp = checkIdExistance(id);
    qDebug() << emp->getUserID();
    if ( emp->getUserID() ==-1) {
        ui->ErrorZone->setText("This id doesnt exist");
        QTimer::singleShot(1500,this,[this]() {
            ui->ErrorZone->setText("");

        });


    } else {

        ui->password->setVisible(true);
        ui->forgotPasswordClicked->setVisible(true);
        ui->passwordLabel->setVisible(true);
        ui->passwordToggleButton->setVisible(true);
        ui->vocalRecogButton->setVisible(true);
        ui->login->setText("Login");
        if ( authenticateEmployee(*emp) ) {
            qDebug() << "Authentication successful!";

            homepage *home = new homepage(nullptr,emp);
            home->show();
            this->hide();
        } else {
            ui->ErrorZone->setText("Invalid Password");

            QTimer::singleShot(1500,this,[this]() {
                ui->ErrorZone->setText("");

            });
        }
    }

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

void MainWindow::captureImageAndSaveToTpmFolder() {
    QString projectDir = QDir::cleanPath(QCoreApplication::applicationDirPath() + "/../../..");
    QString saveDir = projectDir + "/tmp/";

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
    QPushButton *captureButton = new QPushButton("Verify ", captureDialog);
    captureButton->setFixedSize(150, 40);

    // Layout setup
    QVBoxLayout *layout = new QVBoxLayout(captureDialog);
    layout->addWidget(viewfinder, 1);
    layout->addWidget(captureButton, 0, Qt::AlignHCenter);

    // Connect capture button
    connect(captureButton, &QPushButton::clicked, this, [=]() {
        QString filePath = saveDir + "tmp" + ".jpg";

        if (imageCapture->captureToFile(filePath)) {
            QMessageBox::information(this, "Success", "Checking for Face existance !");
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


 void MainWindow::on_facialRecogButton_clicked()
    {

        captureImageAndSaveToTpmFolder();
        QProcess process;
        QString pythonPath = "python";
        QStringList arguments;
        arguments << "../../faceRecogScript.py";

        process.start(pythonPath, arguments);
        process.waitForFinished();
        QString output = process.readAllStandardOutput().trimmed();
        QString errOutput = process.readAllStandardError();
        qDebug() << "Python error output:" << errOutput;
        qDebug() << "Python script output:" << output;
        int userID = output.toInt();

        if (!output.isEmpty() && !output.contains("No match")) {
            qDebug() << "Face match found! User ID:" << output;
            QMessageBox::information(this, "Face Recognition", "Face match found for user: " + output);
            employee *emp = new employee();
            *emp = checkIdExistance(userID);
            homepage *home = new homepage(nullptr,emp);
            home->show();
            this->hide();



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

employee MainWindow::checkIdExistance(int userID)
{
    QSqlQuery query;
    query.clear();
    query.prepare("SELECT USERID, FIRSTNAME, LASTNAME, PHONENUM, ADDRESS, DEPNAME, POSITION FROM employees WHERE USERID=:userID");
    query.bindValue(":userID", userID);
    employee p;

    if (query.exec() && query.next()) {
        int id = query.value(0).toInt();
        QString firstName = query.value(1).toString();
        QString lastName = query.value(2).toString();
        QString phone = query.value(3).toString();
        QString address = query.value(4).toString();
        QString department = query.value(5).toString();
        QString position = query.value(6).toString();



        p.setFirstName(firstName);
        p.setLastName(lastName);
        p.setUserID(id);
        p.setDepName(department);
        p.setPosition(position);
        p.setAddress(address);


        return p;
    } else {
        p.setUserID(-1);  // Mark the user as not found
        qDebug() << query.lastError().text();  // Log the query error
        return p;  // Return the employee object with -1
    }
}


bool MainWindow::authenticateEmployee(employee emp)
{
    int id = emp.getUserID();
    QString mdp = ui->password->text();
    QSqlQuery query;
    query.clear();
    query.prepare("SELECT COUNT(*) FROM EMPLOYEES WHERE USERID=:id AND MDP=:mdp");
    query.bindValue(":id", id);
    query.bindValue(":mdp", mdp);

    if (query.exec() && query.next()) {
        int count = query.value(0).toInt();
        return count > 0;  // If count is greater than 0, the employee exists with the provided password
    } else {
        qDebug() << query.lastError().text();  // Log the error in case something goes wrong
        return false;
    }
}






void MainWindow::on_passwordToggleButton_clicked()
{
    if (!isPasswordVisible) {
        ui->password->setEchoMode(QLineEdit::Password);
        ui->passwordToggleButton->setIcon(QIcon(":/textures/textures/visible.png"));
    } else {
        ui->password->setEchoMode(QLineEdit::Normal);
        ui->passwordToggleButton->setIcon(QIcon(":/textures/textures/hidden.png"));
    }
    isPasswordVisible = !isPasswordVisible;
}

