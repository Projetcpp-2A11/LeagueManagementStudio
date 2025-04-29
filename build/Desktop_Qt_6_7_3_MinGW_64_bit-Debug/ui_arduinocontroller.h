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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
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
    QGroupBox *groupBox;
    QLabel *team2LogoLabel;
    QLabel *team1LogoLabel;
    QLabel *TeamAName;
    QLabel *TeamBName;
    QLabel *StadiumName;
    QWidget *LMSPENALTY;
    QTableWidget *tableWidget;
    QPushButton *connectPenalty;

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
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Impact")});
        font2.setPointSize(14);
        label_4->setFont(font2);
        label_4->setStyleSheet(QString::fromUtf8("background:none\n"
""));
        label_5 = new QLabel(notificationGroupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 75, 141, 41));
        QFont font3;
        font3.setPointSize(10);
        label_5->setFont(font3);
        label_5->setStyleSheet(QString::fromUtf8("background:none\n"
""));
        addTimeNumbers = new QLabel(notificationGroupBox);
        addTimeNumbers->setObjectName("addTimeNumbers");
        addTimeNumbers->setGeometry(QRect(152, 85, 31, 21));
        QFont font4;
        font4.setPointSize(15);
        font4.setBold(true);
        addTimeNumbers->setFont(font4);
        addTimeNumbers->setStyleSheet(QString::fromUtf8("background:none;\n"
"color:red"));
        label_7 = new QLabel(notificationGroupBox);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(190, 85, 161, 21));
        label_7->setFont(font3);
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
        groupBox = new QGroupBox(LMSTIMER);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(0, 90, 941, 341));
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
        TeamAName = new QLabel(groupBox);
        TeamAName->setObjectName("TeamAName");
        TeamAName->setGeometry(QRect(170, 170, 121, 31));
        QFont font5;
        font5.setPointSize(14);
        TeamAName->setFont(font5);
        TeamAName->setStyleSheet(QString::fromUtf8("background:none"));
        TeamBName = new QLabel(groupBox);
        TeamBName->setObjectName("TeamBName");
        TeamBName->setGeometry(QRect(650, 170, 121, 31));
        TeamBName->setFont(font5);
        TeamBName->setStyleSheet(QString::fromUtf8("background:none"));
        StadiumName = new QLabel(groupBox);
        StadiumName->setObjectName("StadiumName");
        StadiumName->setGeometry(QRect(390, 5, 121, 31));
        StadiumName->setStyleSheet(QString::fromUtf8("background:none"));
        tabWidget->addTab(LMSTIMER, QString());
        LMSPENALTY = new QWidget();
        LMSPENALTY->setObjectName("LMSPENALTY");
        tableWidget = new QTableWidget(LMSPENALTY);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(110, 60, 741, 521));
        connectPenalty = new QPushButton(LMSPENALTY);
        connectPenalty->setObjectName("connectPenalty");
        connectPenalty->setGeometry(QRect(20, 10, 101, 41));
        tabWidget->addTab(LMSPENALTY, QString());

        retranslateUi(arduinocontroller);

        tabWidget->setCurrentIndex(1);


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
        groupBox->setTitle(QString());
        team2LogoLabel->setText(QString());
        team1LogoLabel->setText(QString());
        TeamAName->setText(QString());
        TeamBName->setText(QString());
        StadiumName->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(LMSTIMER), QCoreApplication::translate("arduinocontroller", "Additional Time Controller", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("arduinocontroller", "Penalty", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("arduinocontroller", "Player ", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("arduinocontroller", "Time", nullptr));
        connectPenalty->setText(QCoreApplication::translate("arduinocontroller", "Connect", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(LMSPENALTY), QCoreApplication::translate("arduinocontroller", "Player Penalisation System", nullptr));
    } // retranslateUi

};

namespace Ui {
    class arduinocontroller: public Ui_arduinocontroller {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARDUINOCONTROLLER_H
