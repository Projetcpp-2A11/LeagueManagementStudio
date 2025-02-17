#include "mainwindow.h"
#include "qbuffer.h"
#include "ui_mainwindow.h"
#include "employeepage.h"
#include <qtimer.h>
#include <QProcess>
#include <QMessageBox>
#include <QAudioInput>
#include "QAudioDevice"
#include <QMediaDevices>
#include <QAudioSource>
#include <pocketsphinx.h>
#include <QEventLoop>
#include <QFile>
#define MODELDIR "C:/pocketsphinx-5.0.4/models"


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

QByteArray MainWindow::readAudioFromFile(const QString &filePath)
{
    QFile audioFile(filePath);
    if (!audioFile.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(this, "Error", "Failed to open audio file.");
        return QByteArray();
    }

    QByteArray audioData = audioFile.readAll();
    audioFile.close();
    return audioData;
}

QByteArray MainWindow::captureAudio()
{
    QMessageBox *msgBox = new QMessageBox(this);
    msgBox->setText("Recording audio...");
    msgBox->setIcon(QMessageBox::Information);
    msgBox->setStandardButtons(QMessageBox::NoButton);  // No button to close the box
    msgBox->show();

    QByteArray audioData;
    QBuffer buffer(&audioData);
    buffer.open(QIODevice::WriteOnly);

    QAudioFormat format;
    format.setSampleRate(16000); // 16 kHz
    format.setChannelCount(1);   // Mono
    format.setSampleFormat(QAudioFormat::Int16); // 16-bit PCM

    QAudioDevice inputDevice = QMediaDevices::defaultAudioInput();
    if (inputDevice.isNull()) {
        QMessageBox::critical(this, "Error", "No audio input device found.");
        return QByteArray();
    }

    if (!inputDevice.isFormatSupported(format)) {
        QMessageBox::critical(this, "Error", "Audio format not supported.");
        return QByteArray();
    }

    QAudioSource audioInput(inputDevice, format, this);
    audioInput.start(&buffer);

    QEventLoop loop;
    QTimer::singleShot(3000, &loop, &QEventLoop::quit); // Record for 3 seconds
    loop.exec();

    audioInput.stop();
    buffer.close();
    msgBox->hide();

    return audioData;
}

void MainWindow::on_vocalRecogButton_clicked()
{
   /*
    * TEST WITH PRERecorded :
    * QString audioFilePath = "C:/Users/choua/OneDrive/Bureau/Recording.wav";

    QByteArray audioData = readAudioFromFile(audioFilePath);
    if (audioData.isEmpty()) {
        QMessageBox::warning(this, "Warning", "No audio data read from file.");
        return;
    }*/



    // Capture audio
    QByteArray audioData = captureAudio();
    qDebug() << "Audio data size:" << audioData.size();

    if (audioData.isEmpty()) {
        QMessageBox::warning(this, "Warning", "No audio data captured.");
        return;
    }



    ps_config_t *config = ps_config_init(NULL);

    if (config == nullptr) {
        QMessageBox::critical(this, "Error", "Failed to initialize PocketSphinx configuration.");
        return;
    }

    ps_config_set_str(config, "hmm", "C:/pocketsphinx-5.0.4/model/en-us/en-us");
    ps_config_set_str(config, "lm", "C:/pocketsphinx-5.0.4/model/en-us/en-us.lm.bin");
    ps_config_set_str(config, "dict", "C:/pocketsphinx-5.0.4/model/en-us/cmudict-en-us.dict");

    ps_config_set_int(config, "samprate", 16000);
    ps_config_set_int(config, "maxwpf", 40);
    ps_config_set_int(config, "logfn", 1);

    ps_decoder_t *ps = ps_init(config);
    if (ps == nullptr) {
        QMessageBox::critical(this, "Error", "Failed to initialize PocketSphinx decoder.");
        ps_config_free(config);
        return;
    }

    ps_start_utt(ps);
    ps_process_raw(ps, reinterpret_cast<const int16_t*>(audioData.constData()), audioData.size() / 2, FALSE, FALSE);
    ps_end_utt(ps);

    const char *hypothesis = ps_get_hyp(ps, nullptr);
    if (hypothesis != nullptr) {
        qDebug() << "Hypothesis: " << (hypothesis ? QString::fromUtf8(hypothesis) : "No recognition");

        QString recognizedText = QString::fromUtf8(hypothesis);
        ui->password->setText(recognizedText);
        qDebug() << "Recognized text:" << recognizedText;
    } else {
        QMessageBox::warning(this, "Warning", "No speech recognized.");
    }

    ps_free(ps);
    ps_config_free(config);
}
