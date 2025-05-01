/********************************************************************************
** Form generated from reading UI file 'arduinocontroller.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARDUINOCONTROLLER_H
#define UI_ARDUINOCONTROLLER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_arduinocontroller
{
public:
    QLabel *label;
    QLineEdit *matchIdInput;
    QPushButton *pushButton;
    QLabel *label_2;
    QLabel *label_3;
    QTabWidget *tabWidget;
    QWidget *LMSVAR;
    QPushButton *connectVAR;
    QGroupBox *groupBox;
    QLabel *team2LogoLabel;
    QLabel *team1LogoLabel;
    QLabel *TeamBName;
    QLabel *TeamAName;
    QLabel *StadiumName;
    QLabel *TeamAScore;
    QLabel *TeamBScoreLabel;
    QLabel *label_9;
    QPushButton *ConfigureMatchBtn;
    QPushButton *GoLiveBtn;
    QPushButton *EndMatchBtn;
    QPushButton *SaveMatchBtn;
    QWidget *LMSTIMER;
    QPushButton *connectTimer;
    QLabel *connectionSucessGreenMark;
    QGroupBox *notificationGroupBox;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *addTimeNumbers;
    QLabel *label_7;
    QPushButton *cancelChangesButton;
    QLabel *savingChangedLabel;
    QWidget *LMSPENALTY;
    QPushButton *connectPenalty;
    QLabel *PenaltyConnctSuccessGreenMark;
    QGroupBox *PenaltynotificationGroupBox;
    QLabel *label_6;
    QLabel *addTimeNumbers_2;
    QPushButton *cancelChangesButton_2;
    QLabel *errorLabel;
    QLineEdit *playerNumInput;
    QLabel *cardTypeLabel;
    QLabel *cardColorLabel;
    QLabel *label_8;
    QPushButton *validatePlayerNum;
    QLabel *sucessMessage;

    void setupUi(QWidget *arduinocontroller)
    {
        if (arduinocontroller->objectName().isEmpty())
            arduinocontroller->setObjectName("arduinocontroller");
        arduinocontroller->resize(940, 706);
        arduinocontroller->setStyleSheet(QString::fromUtf8("\n"
"background-color: qlineargradient(spread:pad, \n"
"                                x1:0, y1:0, x2:0, y2:1, \n"
"                                stop:0 rgba(6, 6, 6, 255), \n"
"                                stop:0.41 rgba(56, 50, 52, 255), \n"
"                                stop:1 rgba(34, 33, 33, 255));;\n"
"\n"
""));
        label = new QLabel(arduinocontroller);
        label->setObjectName("label");
        label->setGeometry(QRect(230, 400, 141, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("Azonix")});
        font.setPointSize(16);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("background:none;\n"
"color:black;"));
        matchIdInput = new QLineEdit(arduinocontroller);
        matchIdInput->setObjectName("matchIdInput");
        matchIdInput->setGeometry(QRect(350, 410, 151, 31));
        matchIdInput->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: white;\n"
"    padding: 5px;\n"
"    color: black;\n"
"    font-size: 16px;\n"
"}\n"
"\n"
"/* Hover effect */\n"
"QLineEdit:hover {\n"
"	border:3px dashed qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));;  ;  ;\n"
"}\n"
"\n"
"/* Focus effect */\n"
"QLineEdit:focus {\n"
"    border:2px solid  qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));;  ;  ;\n"
"}\n"
""));
        pushButton = new QPushButton(arduinocontroller);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(510, 410, 51, 31));
        QFont font1;
        font1.setPointSize(12);
        pushButton->setFont(font1);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(0, 213, 246, 255), \n"
"                            stop:0.18 rgba(100, 100, 138, 255), \n"
"                            stop:1 rgba(0, 212, 255, 255));;\n"
"    color: white;\n"
"    border: 2px solid black;\n"
"    padding: 10px;\n"
"	width: 263%\n"
"	\n"
"   \n"
"}\n"
"\n"
"QPushButton:selected {\n"
"    background:qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));;  \n"
"\n"
"    font-weight: bold;\n"
"	color:white;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background: lightblue;\n"
"    color: black;\n"
"}\n"
"\n"
""));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::HelpFaq));
        pushButton->setIcon(icon);
        label_2 = new QLabel(arduinocontroller);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(50, 200, 851, 61));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("background:none;\n"
"color:black;"));
        label_3 = new QLabel(arduinocontroller);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(260, 260, 411, 61));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("background:none;\n"
"color:black;"));
        tabWidget = new QTabWidget(arduinocontroller);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(0, 0, 941, 711));
        tabWidget->setStyleSheet(QString::fromUtf8("QTabBar::tab {\n"
"    background: qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));;  ;  \n"
"    color: white;\n"
"    border: 2px solid black;\n"
"    padding: 10px;\n"
"	width: 263%\n"
"	\n"
"   \n"
"}\n"
"\n"
"\n"
"QTabBar::tab:selected {\n"
"    background:qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(0, 213, 246, 255), \n"
"                            stop:0.18 rgba(100, 100, 138, 255), \n"
"                            stop:1 rgba(0, 212, 255, 255));;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QTabBar::tab:hover {\n"
"    background: lightblue;\n"
"    color: black;\n"
"}\n"
"\n"
"background-color: qlineargradient(spread:pad, \n"
"                                x1:0, y1:0, x"
                        "2:0, y2:1, \n"
"                                stop:0 rgba(6, 6, 6, 255), \n"
"                                stop:0.41 rgba(56, 50, 52, 255), \n"
"                                stop:1 rgba(34, 33, 33, 255));;\n"
""));
        LMSVAR = new QWidget();
        LMSVAR->setObjectName("LMSVAR");
        connectVAR = new QPushButton(LMSVAR);
        connectVAR->setObjectName("connectVAR");
        connectVAR->setGeometry(QRect(30, 20, 151, 51));
        connectVAR->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));;             /* Red background */\n"
"    border-radius: 15px;               /* Rounded corners */\n"
"    color: white;                      /* White text */\n"
"    border: none;                      /* No border */\n"
"    padding: 10px 20px;                /* Padding inside the button */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color:  qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(0, 213, 246, 255), \n"
"                            stop:0.18 rgba(100, 100, 138, 255), \n"
"                            stop:1 rgba(0, 212, 255, 255));\n"
"	color:white;\n"
"border:2px solid black;\n"
"}\n"
"\n"
"QPushBu"
                        "tton[selected=\"true\"] {\n"
"    background-color: blue;            /* Blue background when selected */\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: qlineargradient(\n"
"    x1:1, y1:0, x2:0, y2:1,\n"
"    stop:0 rgba(38, 39, 39, 255),\n"
"    stop:0.26 rgba(8, 4, 4, 255),\n"
"    stop:0.67 rgba(108, 105, 139, 255),\n"
"    stop:1 rgba(106, 109, 110, 255)\n"
");;\n"
"\n"
"    color: white;\n"
"    border: 2px solid black;\n"
"}\n"
""));
        groupBox = new QGroupBox(LMSVAR);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(0, 110, 941, 341));
        team2LogoLabel = new QLabel(groupBox);
        team2LogoLabel->setObjectName("team2LogoLabel");
        team2LogoLabel->setGeometry(QRect(170, 50, 111, 101));
        team2LogoLabel->setStyleSheet(QString::fromUtf8("background:none"));
        team2LogoLabel->setScaledContents(true);
        team1LogoLabel = new QLabel(groupBox);
        team1LogoLabel->setObjectName("team1LogoLabel");
        team1LogoLabel->setGeometry(QRect(630, 50, 111, 101));
        team1LogoLabel->setStyleSheet(QString::fromUtf8("background:none"));
        team1LogoLabel->setScaledContents(true);
        TeamBName = new QLabel(groupBox);
        TeamBName->setObjectName("TeamBName");
        TeamBName->setGeometry(QRect(630, 170, 121, 31));
        QFont font2;
        font2.setPointSize(14);
        TeamBName->setFont(font2);
        TeamBName->setStyleSheet(QString::fromUtf8("background:none"));
        TeamAName = new QLabel(groupBox);
        TeamAName->setObjectName("TeamAName");
        TeamAName->setGeometry(QRect(170, 170, 121, 31));
        TeamAName->setFont(font2);
        TeamAName->setStyleSheet(QString::fromUtf8("background:none"));
        StadiumName = new QLabel(groupBox);
        StadiumName->setObjectName("StadiumName");
        StadiumName->setGeometry(QRect(360, 5, 241, 31));
        QFont font3;
        font3.setPointSize(20);
        StadiumName->setFont(font3);
        StadiumName->setStyleSheet(QString::fromUtf8("background:none"));
        TeamAScore = new QLabel(groupBox);
        TeamAScore->setObjectName("TeamAScore");
        TeamAScore->setGeometry(QRect(530, 90, 41, 31));
        QFont font4;
        font4.setPointSize(24);
        TeamAScore->setFont(font4);
        TeamAScore->setStyleSheet(QString::fromUtf8("background:none"));
        TeamBScoreLabel = new QLabel(groupBox);
        TeamBScoreLabel->setObjectName("TeamBScoreLabel");
        TeamBScoreLabel->setGeometry(QRect(310, 90, 51, 31));
        TeamBScoreLabel->setFont(font4);
        TeamBScoreLabel->setStyleSheet(QString::fromUtf8("background:none"));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(400, 80, 111, 31));
        QFont font5;
        font5.setPointSize(72);
        label_9->setFont(font5);
        label_9->setStyleSheet(QString::fromUtf8("background:none\n"
""));
        ConfigureMatchBtn = new QPushButton(LMSVAR);
        ConfigureMatchBtn->setObjectName("ConfigureMatchBtn");
        ConfigureMatchBtn->setGeometry(QRect(210, 20, 151, 51));
        ConfigureMatchBtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));;             /* Red background */\n"
"    border-radius: 15px;               /* Rounded corners */\n"
"    color: white;                      /* White text */\n"
"    border: none;                      /* No border */\n"
"    padding: 10px 20px;                /* Padding inside the button */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color:  qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(0, 213, 246, 255), \n"
"                            stop:0.18 rgba(100, 100, 138, 255), \n"
"                            stop:1 rgba(0, 212, 255, 255));\n"
"	color:white;\n"
"border:2px solid black;\n"
"}\n"
"\n"
"QPushBu"
                        "tton[selected=\"true\"] {\n"
"    background-color: blue;            /* Blue background when selected */\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: qlineargradient(\n"
"    x1:1, y1:0, x2:0, y2:1,\n"
"    stop:0 rgba(38, 39, 39, 255),\n"
"    stop:0.26 rgba(8, 4, 4, 255),\n"
"    stop:0.67 rgba(108, 105, 139, 255),\n"
"    stop:1 rgba(106, 109, 110, 255)\n"
");;\n"
"\n"
"    color: white;\n"
"    border: 2px solid black;\n"
"}\n"
""));
        GoLiveBtn = new QPushButton(LMSVAR);
        GoLiveBtn->setObjectName("GoLiveBtn");
        GoLiveBtn->setGeometry(QRect(380, 20, 151, 51));
        GoLiveBtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));;             /* Red background */\n"
"    border-radius: 15px;               /* Rounded corners */\n"
"    color: white;                      /* White text */\n"
"    border: none;                      /* No border */\n"
"    padding: 10px 20px;                /* Padding inside the button */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color:  qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(0, 213, 246, 255), \n"
"                            stop:0.18 rgba(100, 100, 138, 255), \n"
"                            stop:1 rgba(0, 212, 255, 255));\n"
"	color:white;\n"
"border:2px solid black;\n"
"}\n"
"\n"
"QPushBu"
                        "tton[selected=\"true\"] {\n"
"    background-color: blue;            /* Blue background when selected */\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: qlineargradient(\n"
"    x1:1, y1:0, x2:0, y2:1,\n"
"    stop:0 rgba(38, 39, 39, 255),\n"
"    stop:0.26 rgba(8, 4, 4, 255),\n"
"    stop:0.67 rgba(108, 105, 139, 255),\n"
"    stop:1 rgba(106, 109, 110, 255)\n"
");;\n"
"\n"
"    color: white;\n"
"    border: 2px solid black;\n"
"}\n"
""));
        EndMatchBtn = new QPushButton(LMSVAR);
        EndMatchBtn->setObjectName("EndMatchBtn");
        EndMatchBtn->setGeometry(QRect(770, 470, 151, 51));
        EndMatchBtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));;             /* Red background */\n"
"    border-radius: 15px;               /* Rounded corners */\n"
"    color: white;                      /* White text */\n"
"    border: none;                      /* No border */\n"
"    padding: 10px 20px;                /* Padding inside the button */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color:  qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(0, 213, 246, 255), \n"
"                            stop:0.18 rgba(100, 100, 138, 255), \n"
"                            stop:1 rgba(0, 212, 255, 255));\n"
"	color:white;\n"
"border:2px solid black;\n"
"}\n"
"\n"
"QPushBu"
                        "tton[selected=\"true\"] {\n"
"    background-color: blue;            /* Blue background when selected */\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: qlineargradient(\n"
"    x1:1, y1:0, x2:0, y2:1,\n"
"    stop:0 rgba(38, 39, 39, 255),\n"
"    stop:0.26 rgba(8, 4, 4, 255),\n"
"    stop:0.67 rgba(108, 105, 139, 255),\n"
"    stop:1 rgba(106, 109, 110, 255)\n"
");;\n"
"\n"
"    color: white;\n"
"    border: 2px solid black;\n"
"}\n"
""));
        SaveMatchBtn = new QPushButton(LMSVAR);
        SaveMatchBtn->setObjectName("SaveMatchBtn");
        SaveMatchBtn->setGeometry(QRect(770, 530, 151, 51));
        SaveMatchBtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));;             /* Red background */\n"
"    border-radius: 15px;               /* Rounded corners */\n"
"    color: white;                      /* White text */\n"
"    border: none;                      /* No border */\n"
"    padding: 10px 20px;                /* Padding inside the button */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color:  qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(0, 213, 246, 255), \n"
"                            stop:0.18 rgba(100, 100, 138, 255), \n"
"                            stop:1 rgba(0, 212, 255, 255));\n"
"	color:white;\n"
"border:2px solid black;\n"
"}\n"
"\n"
"QPushBu"
                        "tton[selected=\"true\"] {\n"
"    background-color: blue;            /* Blue background when selected */\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: qlineargradient(\n"
"    x1:1, y1:0, x2:0, y2:1,\n"
"    stop:0 rgba(38, 39, 39, 255),\n"
"    stop:0.26 rgba(8, 4, 4, 255),\n"
"    stop:0.67 rgba(108, 105, 139, 255),\n"
"    stop:1 rgba(106, 109, 110, 255)\n"
");;\n"
"\n"
"    color: white;\n"
"    border: 2px solid black;\n"
"}\n"
""));
        tabWidget->addTab(LMSVAR, QString());
        LMSTIMER = new QWidget();
        LMSTIMER->setObjectName("LMSTIMER");
        connectTimer = new QPushButton(LMSTIMER);
        connectTimer->setObjectName("connectTimer");
        connectTimer->setGeometry(QRect(20, 20, 151, 51));
        connectTimer->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));;             /* Red background */\n"
"    border-radius: 15px;               /* Rounded corners */\n"
"    color: white;                      /* White text */\n"
"    border: none;                      /* No border */\n"
"    padding: 10px 20px;                /* Padding inside the button */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color:  qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(0, 213, 246, 255), \n"
"                            stop:0.18 rgba(100, 100, 138, 255), \n"
"                            stop:1 rgba(0, 212, 255, 255));\n"
"	color:white;\n"
"border:2px solid black;\n"
"}\n"
"\n"
"QPushBu"
                        "tton[selected=\"true\"] {\n"
"    background-color: blue;            /* Blue background when selected */\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: qlineargradient(\n"
"    x1:1, y1:0, x2:0, y2:1,\n"
"    stop:0 rgba(38, 39, 39, 255),\n"
"    stop:0.26 rgba(8, 4, 4, 255),\n"
"    stop:0.67 rgba(108, 105, 139, 255),\n"
"    stop:1 rgba(106, 109, 110, 255)\n"
");;\n"
"\n"
"    color: white;\n"
"    border: 2px solid black;\n"
"}\n"
""));
        connectionSucessGreenMark = new QLabel(LMSTIMER);
        connectionSucessGreenMark->setObjectName("connectionSucessGreenMark");
        connectionSucessGreenMark->setGeometry(QRect(187, 28, 41, 41));
        connectionSucessGreenMark->setStyleSheet(QString::fromUtf8("background:none;"));
        connectionSucessGreenMark->setPixmap(QPixmap(QString::fromUtf8(":/textures/textures/greenCheckIcon.png")));
        connectionSucessGreenMark->setScaledContents(true);
        notificationGroupBox = new QGroupBox(LMSTIMER);
        notificationGroupBox->setObjectName("notificationGroupBox");
        notificationGroupBox->setGeometry(QRect(0, 470, 381, 191));
        notificationGroupBox->setStyleSheet(QString::fromUtf8(" background:qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(0, 213, 246, 255), \n"
"                            stop:0.18 rgba(100, 100, 138, 255), \n"
"                            stop:1 rgba(0, 212, 255, 255));;"));
        label_4 = new QLabel(notificationGroupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(73, 0, 201, 71));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Impact")});
        font6.setPointSize(14);
        label_4->setFont(font6);
        label_4->setStyleSheet(QString::fromUtf8("background:none\n"
""));
        label_5 = new QLabel(notificationGroupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 75, 141, 41));
        QFont font7;
        font7.setPointSize(10);
        label_5->setFont(font7);
        label_5->setStyleSheet(QString::fromUtf8("background:none\n"
""));
        addTimeNumbers = new QLabel(notificationGroupBox);
        addTimeNumbers->setObjectName("addTimeNumbers");
        addTimeNumbers->setGeometry(QRect(152, 85, 31, 21));
        QFont font8;
        font8.setPointSize(15);
        font8.setBold(true);
        addTimeNumbers->setFont(font8);
        addTimeNumbers->setStyleSheet(QString::fromUtf8("background:none;\n"
"color:red"));
        label_7 = new QLabel(notificationGroupBox);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(190, 85, 161, 21));
        label_7->setFont(font7);
        label_7->setStyleSheet(QString::fromUtf8("background:none\n"
""));
        cancelChangesButton = new QPushButton(notificationGroupBox);
        cancelChangesButton->setObjectName("cancelChangesButton");
        cancelChangesButton->setGeometry(QRect(10, 160, 81, 31));
        cancelChangesButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));;             /* Red background */\n"
"    border-radius: 15px;               /* Rounded corners */\n"
"    color: white;                      /* White text */\n"
"    border: none;                      /* No border */\n"
"    padding: 10px 20px;                /* Padding inside the button */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color:  qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(0, 213, 246, 255), \n"
"                            stop:0.18 rgba(100, 100, 138, 255), \n"
"                            stop:1 rgba(0, 212, 255, 255));\n"
"	color:white;\n"
"border:2px solid black;\n"
"}\n"
"\n"
"QPushBu"
                        "tton[selected=\"true\"] {\n"
"    background-color: blue;            /* Blue background when selected */\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: qlineargradient(\n"
"    x1:1, y1:0, x2:0, y2:1,\n"
"    stop:0 rgba(38, 39, 39, 255),\n"
"    stop:0.26 rgba(8, 4, 4, 255),\n"
"    stop:0.67 rgba(108, 105, 139, 255),\n"
"    stop:1 rgba(106, 109, 110, 255)\n"
");;\n"
"\n"
"    color: white;\n"
"    border: 2px solid black;\n"
"}\n"
""));
        savingChangedLabel = new QLabel(notificationGroupBox);
        savingChangedLabel->setObjectName("savingChangedLabel");
        savingChangedLabel->setGeometry(QRect(110, 166, 221, 21));
        savingChangedLabel->setStyleSheet(QString::fromUtf8("background:none"));
        tabWidget->addTab(LMSTIMER, QString());
        LMSPENALTY = new QWidget();
        LMSPENALTY->setObjectName("LMSPENALTY");
        connectPenalty = new QPushButton(LMSPENALTY);
        connectPenalty->setObjectName("connectPenalty");
        connectPenalty->setGeometry(QRect(20, 10, 121, 51));
        connectPenalty->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));;             /* Red background */\n"
"    border-radius: 15px;               /* Rounded corners */\n"
"    color: white;                      /* White text */\n"
"    border: none;                      /* No border */\n"
"    padding: 10px 20px;                /* Padding inside the button */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color:  qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(0, 213, 246, 255), \n"
"                            stop:0.18 rgba(100, 100, 138, 255), \n"
"                            stop:1 rgba(0, 212, 255, 255));\n"
"	color:white;\n"
"border:2px solid black;\n"
"}\n"
"\n"
"QPushBu"
                        "tton[selected=\"true\"] {\n"
"    background-color: blue;            /* Blue background when selected */\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: qlineargradient(\n"
"    x1:1, y1:0, x2:0, y2:1,\n"
"    stop:0 rgba(38, 39, 39, 255),\n"
"    stop:0.26 rgba(8, 4, 4, 255),\n"
"    stop:0.67 rgba(108, 105, 139, 255),\n"
"    stop:1 rgba(106, 109, 110, 255)\n"
");;\n"
"\n"
"    color: white;\n"
"    border: 2px solid black;\n"
"}\n"
""));
        PenaltyConnctSuccessGreenMark = new QLabel(LMSPENALTY);
        PenaltyConnctSuccessGreenMark->setObjectName("PenaltyConnctSuccessGreenMark");
        PenaltyConnctSuccessGreenMark->setGeometry(QRect(160, 20, 41, 41));
        PenaltyConnctSuccessGreenMark->setStyleSheet(QString::fromUtf8("background:none;"));
        PenaltyConnctSuccessGreenMark->setPixmap(QPixmap(QString::fromUtf8(":/textures/textures/greenCheckIcon.png")));
        PenaltyConnctSuccessGreenMark->setScaledContents(true);
        PenaltynotificationGroupBox = new QGroupBox(LMSPENALTY);
        PenaltynotificationGroupBox->setObjectName("PenaltynotificationGroupBox");
        PenaltynotificationGroupBox->setGeometry(QRect(0, 200, 551, 271));
        PenaltynotificationGroupBox->setStyleSheet(QString::fromUtf8(" background:qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(0, 213, 246, 255), \n"
"                            stop:0.18 rgba(100, 100, 138, 255), \n"
"                            stop:1 rgba(0, 212, 255, 255));;"));
        label_6 = new QLabel(PenaltynotificationGroupBox);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(180, 0, 201, 71));
        label_6->setFont(font6);
        label_6->setStyleSheet(QString::fromUtf8("background:none\n"
""));
        addTimeNumbers_2 = new QLabel(PenaltynotificationGroupBox);
        addTimeNumbers_2->setObjectName("addTimeNumbers_2");
        addTimeNumbers_2->setGeometry(QRect(152, 85, 31, 21));
        addTimeNumbers_2->setFont(font8);
        addTimeNumbers_2->setStyleSheet(QString::fromUtf8("background:none;\n"
"color:red"));
        cancelChangesButton_2 = new QPushButton(PenaltynotificationGroupBox);
        cancelChangesButton_2->setObjectName("cancelChangesButton_2");
        cancelChangesButton_2->setGeometry(QRect(10, 230, 81, 31));
        cancelChangesButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));;             /* Red background */\n"
"    border-radius: 15px;               /* Rounded corners */\n"
"    color: white;                      /* White text */\n"
"    border: none;                      /* No border */\n"
"    padding: 10px 20px;                /* Padding inside the button */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color:  qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(0, 213, 246, 255), \n"
"                            stop:0.18 rgba(100, 100, 138, 255), \n"
"                            stop:1 rgba(0, 212, 255, 255));\n"
"	color:white;\n"
"border:2px solid black;\n"
"}\n"
"\n"
"QPushBu"
                        "tton[selected=\"true\"] {\n"
"    background-color: blue;            /* Blue background when selected */\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: qlineargradient(\n"
"    x1:1, y1:0, x2:0, y2:1,\n"
"    stop:0 rgba(38, 39, 39, 255),\n"
"    stop:0.26 rgba(8, 4, 4, 255),\n"
"    stop:0.67 rgba(108, 105, 139, 255),\n"
"    stop:1 rgba(106, 109, 110, 255)\n"
");;\n"
"\n"
"    color: white;\n"
"    border: 2px solid black;\n"
"}\n"
""));
        errorLabel = new QLabel(PenaltynotificationGroupBox);
        errorLabel->setObjectName("errorLabel");
        errorLabel->setGeometry(QRect(70, 190, 421, 21));
        errorLabel->setFont(font2);
        errorLabel->setStyleSheet(QString::fromUtf8("color:red;\n"
"background:none"));
        playerNumInput = new QLineEdit(PenaltynotificationGroupBox);
        playerNumInput->setObjectName("playerNumInput");
        playerNumInput->setGeometry(QRect(250, 120, 51, 41));
        playerNumInput->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: white;\n"
"    padding: 5px;\n"
"    color: black;\n"
"    font-size: 16px;\n"
"}\n"
"\n"
"/* Hover effect */\n"
"QLineEdit:hover {\n"
"	border:3px dashed qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));;  ;  ;\n"
"}\n"
"\n"
"/* Focus effect */\n"
"QLineEdit:focus {\n"
"    border:2px solid  qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));;  ;  ;\n"
"}\n"
""));
        cardTypeLabel = new QLabel(PenaltynotificationGroupBox);
        cardTypeLabel->setObjectName("cardTypeLabel");
        cardTypeLabel->setGeometry(QRect(110, 80, 281, 21));
        cardTypeLabel->setFont(font1);
        cardTypeLabel->setStyleSheet(QString::fromUtf8("background:none;"));
        cardColorLabel = new QLabel(PenaltynotificationGroupBox);
        cardColorLabel->setObjectName("cardColorLabel");
        cardColorLabel->setGeometry(QRect(400, 70, 21, 41));
        cardColorLabel->setStyleSheet(QString::fromUtf8("background:yellow;"));
        label_8 = new QLabel(PenaltynotificationGroupBox);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(20, 130, 221, 21));
        label_8->setFont(font1);
        label_8->setStyleSheet(QString::fromUtf8("background:none;"));
        validatePlayerNum = new QPushButton(PenaltynotificationGroupBox);
        validatePlayerNum->setObjectName("validatePlayerNum");
        validatePlayerNum->setGeometry(QRect(310, 120, 41, 41));
        validatePlayerNum->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));;             /* Red background */\n"
"    border-radius: 15px;               /* Rounded corners */\n"
"    color: white;                      /* White text */\n"
"    border: none;                      /* No border */\n"
"    padding: 10px 20px;                /* Padding inside the button */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color:  qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(0, 213, 246, 255), \n"
"                            stop:0.18 rgba(100, 100, 138, 255), \n"
"                            stop:1 rgba(0, 212, 255, 255));\n"
"	color:white;\n"
"border:2px solid black;\n"
"}\n"
"\n"
"QPushBu"
                        "tton[selected=\"true\"] {\n"
"    background-color: blue;            /* Blue background when selected */\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: qlineargradient(\n"
"    x1:1, y1:0, x2:0, y2:1,\n"
"    stop:0 rgba(38, 39, 39, 255),\n"
"    stop:0.26 rgba(8, 4, 4, 255),\n"
"    stop:0.67 rgba(108, 105, 139, 255),\n"
"    stop:1 rgba(106, 109, 110, 255)\n"
");;\n"
"\n"
"    color: white;\n"
"    border: 2px solid black;\n"
"}\n"
""));
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::InsertLink));
        validatePlayerNum->setIcon(icon1);
        sucessMessage = new QLabel(PenaltynotificationGroupBox);
        sucessMessage->setObjectName("sucessMessage");
        sucessMessage->setGeometry(QRect(110, 230, 411, 21));
        sucessMessage->setFont(font2);
        sucessMessage->setStyleSheet(QString::fromUtf8("background:none;\n"
"color:green;\n"
""));
        tabWidget->addTab(LMSPENALTY, QString());

        retranslateUi(arduinocontroller);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(arduinocontroller);
    } // setupUi

    void retranslateUi(QWidget *arduinocontroller)
    {
        arduinocontroller->setWindowTitle(QCoreApplication::translate("arduinocontroller", "Form", nullptr));
        label->setText(QCoreApplication::translate("arduinocontroller", "Match Id", nullptr));
        pushButton->setText(QString());
        label_2->setText(QCoreApplication::translate("arduinocontroller", "Please Provide the current match ID to start Monitoring", nullptr));
        label_3->setText(QCoreApplication::translate("arduinocontroller", "This is a very important step ", nullptr));
        connectVAR->setText(QCoreApplication::translate("arduinocontroller", "Connect", nullptr));
        groupBox->setTitle(QString());
        team2LogoLabel->setText(QString());
        team1LogoLabel->setText(QString());
        TeamBName->setText(QString());
        TeamAName->setText(QString());
        StadiumName->setText(QString());
        TeamAScore->setText(QCoreApplication::translate("arduinocontroller", "0", nullptr));
        TeamBScoreLabel->setText(QCoreApplication::translate("arduinocontroller", "0", nullptr));
        label_9->setText(QCoreApplication::translate("arduinocontroller", "-", nullptr));
        ConfigureMatchBtn->setText(QCoreApplication::translate("arduinocontroller", "Configure Match", nullptr));
        GoLiveBtn->setText(QCoreApplication::translate("arduinocontroller", "GO LIVE", nullptr));
        EndMatchBtn->setText(QCoreApplication::translate("arduinocontroller", "End Match", nullptr));
        SaveMatchBtn->setText(QCoreApplication::translate("arduinocontroller", "Save Match", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(LMSVAR), QCoreApplication::translate("arduinocontroller", "Goal Detection Technology", nullptr));
        connectTimer->setText(QCoreApplication::translate("arduinocontroller", "Connect", nullptr));
        connectionSucessGreenMark->setText(QString());
        notificationGroupBox->setTitle(QString());
        label_4->setText(QCoreApplication::translate("arduinocontroller", "New Arduino Notification", nullptr));
        label_5->setText(QCoreApplication::translate("arduinocontroller", "The Referee Has added", nullptr));
        addTimeNumbers->setText(QString());
        label_7->setText(QCoreApplication::translate("arduinocontroller", "minutes of additional time", nullptr));
        cancelChangesButton->setText(QCoreApplication::translate("arduinocontroller", "Cancel", nullptr));
        savingChangedLabel->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(LMSTIMER), QCoreApplication::translate("arduinocontroller", "Additional Time Controller", nullptr));
        connectPenalty->setText(QCoreApplication::translate("arduinocontroller", "Connect", nullptr));
        PenaltyConnctSuccessGreenMark->setText(QString());
        PenaltynotificationGroupBox->setTitle(QString());
        label_6->setText(QCoreApplication::translate("arduinocontroller", "New Arduino Notification", nullptr));
        addTimeNumbers_2->setText(QString());
        cancelChangesButton_2->setText(QCoreApplication::translate("arduinocontroller", "Cancel", nullptr));
        errorLabel->setText(QString());
        playerNumInput->setText(QString());
        playerNumInput->setPlaceholderText(QCoreApplication::translate("arduinocontroller", "num", nullptr));
        cardTypeLabel->setText(QCoreApplication::translate("arduinocontroller", "The Referee has signaled a Yellow Card", nullptr));
        cardColorLabel->setText(QString());
        label_8->setText(QCoreApplication::translate("arduinocontroller", "Please Enter  the player number", nullptr));
        validatePlayerNum->setText(QString());
        sucessMessage->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(LMSPENALTY), QCoreApplication::translate("arduinocontroller", "Player Penalisation System", nullptr));
    } // retranslateUi

};

namespace Ui {
    class arduinocontroller: public Ui_arduinocontroller {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARDUINOCONTROLLER_H
