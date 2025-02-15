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

QByteArray MainWindow::captureAudio()
{
    QByteArray audioData;
    QBuffer buffer(&audioData);
    buffer.open(QIODevice::WriteOnly);

    // Set up audio format
    QAudioFormat format;
    format.setSampleRate(16000); // 16 kHz
    format.setChannelCount(1);   // Mono
    format.setSampleFormat(QAudioFormat::Int16); // 16-bit PCM

    // Get the default audio input device
    QAudioDevice inputDevice = QMediaDevices::defaultAudioInput();
    if (inputDevice.isNull()) {
        QMessageBox::critical(this, "Error", "No audio input device found.");
        return QByteArray();
    }

    // Check if the format is supported
    if (!inputDevice.isFormatSupported(format)) {
        QMessageBox::critical(this, "Error", "Audio format not supported.");
        return QByteArray();
    }

    // Initialize audio input
    QAudioSource audioInput(inputDevice, format, this);
    audioInput.start(&buffer);

    // Record for 3 seconds (adjust as needed)
    QEventLoop loop;
    QTimer::singleShot(3000, &loop, &QEventLoop::quit); // Record for 3 seconds
    loop.exec();

    // Stop recording
    audioInput.stop();
    buffer.close();

    return audioData;
}

void MainWindow::on_vocalRecogButton_clicked()
{
    // Capture audio
    QByteArray audioData = captureAudio();

    if (audioData.isEmpty()) {
        QMessageBox::warning(this, "Warning", "No audio data captured.");
        return;
    }

    // Initialize PocketSphinx
    ps_decoder_t *ps = nullptr;
    cmd_ln_t *config = nullptr;

    config = cmd_ln_init(nullptr, ps_args(), TRUE,
                         "-hmm", MODELDIR "/en-us/en-us",  // Path to the acoustic model
                         "-lm", MODELDIR "/en-us/en-us.lm.bin",  // Path to the language model
                         "-dict", MODELDIR "/en-us/cmudict-en-us.dict",  // Path to the dictionary
                         nullptr);

    if (config == nullptr) {
        QMessageBox::critical(this, "Error", "Failed to initialize PocketSphinx configuration.");
        return;
    }

    ps = ps_init(config);
    if (ps == nullptr) {
        QMessageBox::critical(this, "Error", "Failed to initialize PocketSphinx decoder.");
        cmd_ln_free_r(config);
        return;
    }

    // Process the audio data
    ps_start_utt(ps);
    ps_process_raw(ps, reinterpret_cast<const int16_t*>(audioData.constData()), audioData.size() / 2, FALSE, FALSE);
    ps_end_utt(ps);

    // Get the recognized text
    const char *hypothesis = ps_get_hyp(ps, nullptr);
    if (hypothesis != nullptr) {
        QString recognizedText = QString::fromUtf8(hypothesis);
        ui->password->setText(recognizedText); // Update the lineEdit with the recognized text
        qDebug() << "Recognized text:" << recognizedText;
    } else {
        QMessageBox::warning(this, "Warning", "No speech recognized.");
    }

    // Clean up
    ps_free(ps);
    cmd_ln_free_r(config);
}

