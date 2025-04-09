/********************************************************************************
** Form generated from reading UI file 'homepage.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMEPAGE_H
#define UI_HOMEPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_homepage
{
public:
    QWidget *topBar;
    QPushButton *myAccountButton;
    QLabel *usernameLabel;
    QLabel *accountSettingsLabel;
    QLabel *timeLabel;
    QLabel *label;
    QGroupBox *AccountSettingsGrpBox;
    QPushButton *configureFidButton;
    QPushButton *closeButton;
    QLabel *empIoyeeIcon;
    QPushButton *employeeButton;
    QPushButton *teamsButton;
    QLabel *teamsIcon;
    QPushButton *matchsButton;
    QLabel *matchsIcon;
    QPushButton *playersButton;
    QLabel *playersIcon;
    QPushButton *stadiumsButton;
    QLabel *stadiumIcon;
    QPushButton *partnersButton;
    QLabel *partnersIcon;

    void setupUi(QWidget *homepage)
    {
        if (homepage->objectName().isEmpty())
            homepage->setObjectName("homepage");
        homepage->resize(1000, 800);
        homepage->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, \n"
"                                x1:0, y1:0, x2:0, y2:1, \n"
"                                stop:0 rgba(6, 6, 6, 255), \n"
"                                stop:0.41 rgba(56, 50, 52, 255), \n"
"                                stop:1 rgba(34, 33, 33, 255));;\n"
""));
        topBar = new QWidget(homepage);
        topBar->setObjectName("topBar");
        topBar->setGeometry(QRect(0, 0, 1001, 141));
        topBar->setStyleSheet(QString::fromUtf8("QWidget#topBar{\n"
"    background: qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));\n"
"    border: 2px solid #8B0000;\n"
"    border-radius: 8px;\n"
"    padding: 5px;\n"
"    \n"
"    /* Fake shadow using an outline effect */\n"
"    box-shadow: 0px 4px 10px rgba(0, 0, 0, 0.5);\n"
"\n"
"}"));
        myAccountButton = new QPushButton(topBar);
        myAccountButton->setObjectName("myAccountButton");
        myAccountButton->setGeometry(QRect(10, 10, 71, 61));
        myAccountButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        myAccountButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: none;\n"
"    border: none;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    icon: url(:/textures/textures/myaccountIconHovered.png)\n"
"}\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/textures/textures/myaccountIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        myAccountButton->setIcon(icon);
        myAccountButton->setIconSize(QSize(50, 50));
        usernameLabel = new QLabel(topBar);
        usernameLabel->setObjectName("usernameLabel");
        usernameLabel->setGeometry(QRect(75, 25, 321, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Azonix")});
        font.setPointSize(12);
        usernameLabel->setFont(font);
        usernameLabel->setStyleSheet(QString::fromUtf8("background:none;\n"
"border:none;"));
        accountSettingsLabel = new QLabel(topBar);
        accountSettingsLabel->setObjectName("accountSettingsLabel");
        accountSettingsLabel->setGeometry(QRect(13, 64, 71, 20));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial Rounded MT Bold")});
        font1.setPointSize(7);
        accountSettingsLabel->setFont(font1);
        accountSettingsLabel->setStyleSheet(QString::fromUtf8("border:none;\n"
"background:none;"));
        timeLabel = new QLabel(topBar);
        timeLabel->setObjectName("timeLabel");
        timeLabel->setGeometry(QRect(700, 0, 301, 41));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Arial Black")});
        font2.setBold(true);
        timeLabel->setFont(font2);
        timeLabel->setStyleSheet(QString::fromUtf8("background:none;\n"
"border:none;\n"
""));
        label = new QLabel(topBar);
        label->setObjectName("label");
        label->setGeometry(QRect(340, -30, 271, 231));
        label->setStyleSheet(QString::fromUtf8("background:none;\n"
""));
        label->setPixmap(QPixmap(QString::fromUtf8(":/textures/textures/app_icon.png")));
        label->setScaledContents(true);
        AccountSettingsGrpBox = new QGroupBox(topBar);
        AccountSettingsGrpBox->setObjectName("AccountSettingsGrpBox");
        AccountSettingsGrpBox->setGeometry(QRect(90, 0, 281, 141));
        configureFidButton = new QPushButton(AccountSettingsGrpBox);
        configureFidButton->setObjectName("configureFidButton");
        configureFidButton->setGeometry(QRect(30, 30, 211, 61));
        configureFidButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"\n"
""));
        closeButton = new QPushButton(AccountSettingsGrpBox);
        closeButton->setObjectName("closeButton");
        closeButton->setGeometry(QRect(191, 104, 81, 31));
        closeButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"\n"
""));
        empIoyeeIcon = new QLabel(homepage);
        empIoyeeIcon->setObjectName("empIoyeeIcon");
        empIoyeeIcon->setGeometry(QRect(130, 310, 51, 41));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(empIoyeeIcon->sizePolicy().hasHeightForWidth());
        empIoyeeIcon->setSizePolicy(sizePolicy);
        empIoyeeIcon->setStyleSheet(QString::fromUtf8("background-color:none"));
        empIoyeeIcon->setPixmap(QPixmap(QString::fromUtf8(":/textures/textures/employeeIcon.png")));
        empIoyeeIcon->setScaledContents(true);
        employeeButton = new QPushButton(homepage);
        employeeButton->setObjectName("employeeButton");
        employeeButton->setGeometry(QRect(120, 300, 181, 61));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Arial")});
        font3.setPointSize(16);
        employeeButton->setFont(font3);
        employeeButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        employeeButton->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        employeeButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        teamsButton = new QPushButton(homepage);
        teamsButton->setObjectName("teamsButton");
        teamsButton->setGeometry(QRect(420, 300, 181, 61));
        teamsButton->setFont(font3);
        teamsButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        teamsButton->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        teamsButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        teamsIcon = new QLabel(homepage);
        teamsIcon->setObjectName("teamsIcon");
        teamsIcon->setGeometry(QRect(430, 300, 51, 61));
        teamsIcon->setStyleSheet(QString::fromUtf8("background-color:none"));
        teamsIcon->setPixmap(QPixmap(QString::fromUtf8(":/textures/textures/teamsIcon.png")));
        teamsIcon->setScaledContents(true);
        matchsButton = new QPushButton(homepage);
        matchsButton->setObjectName("matchsButton");
        matchsButton->setGeometry(QRect(700, 300, 181, 61));
        matchsButton->setFont(font3);
        matchsButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        matchsButton->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        matchsButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        matchsIcon = new QLabel(homepage);
        matchsIcon->setObjectName("matchsIcon");
        matchsIcon->setGeometry(QRect(702, 306, 51, 51));
        matchsIcon->setStyleSheet(QString::fromUtf8("background-color:none"));
        matchsIcon->setPixmap(QPixmap(QString::fromUtf8(":/textures/textures/matchsIcon.png")));
        matchsIcon->setScaledContents(true);
        playersButton = new QPushButton(homepage);
        playersButton->setObjectName("playersButton");
        playersButton->setGeometry(QRect(120, 490, 181, 61));
        playersButton->setFont(font3);
        playersButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        playersButton->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        playersButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        playersIcon = new QLabel(homepage);
        playersIcon->setObjectName("playersIcon");
        playersIcon->setGeometry(QRect(100, 487, 91, 71));
        playersIcon->setStyleSheet(QString::fromUtf8("background-color:none"));
        playersIcon->setPixmap(QPixmap(QString::fromUtf8(":/textures/textures/playersIcon.png")));
        playersIcon->setScaledContents(true);
        stadiumsButton = new QPushButton(homepage);
        stadiumsButton->setObjectName("stadiumsButton");
        stadiumsButton->setGeometry(QRect(420, 490, 181, 61));
        stadiumsButton->setFont(font3);
        stadiumsButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        stadiumsButton->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        stadiumsButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        stadiumIcon = new QLabel(homepage);
        stadiumIcon->setObjectName("stadiumIcon");
        stadiumIcon->setGeometry(QRect(428, 506, 31, 31));
        stadiumIcon->setStyleSheet(QString::fromUtf8("background-color:none"));
        stadiumIcon->setPixmap(QPixmap(QString::fromUtf8(":/textures/textures/stadiumIcon.png")));
        stadiumIcon->setScaledContents(true);
        partnersButton = new QPushButton(homepage);
        partnersButton->setObjectName("partnersButton");
        partnersButton->setGeometry(QRect(700, 490, 181, 61));
        partnersButton->setFont(font3);
        partnersButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        partnersButton->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        partnersButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        partnersIcon = new QLabel(homepage);
        partnersIcon->setObjectName("partnersIcon");
        partnersIcon->setGeometry(QRect(707, 507, 41, 31));
        partnersIcon->setStyleSheet(QString::fromUtf8("background-color:none"));
        partnersIcon->setPixmap(QPixmap(QString::fromUtf8(":/textures/textures/partnersIcon.png")));
        partnersIcon->setScaledContents(true);
        topBar->raise();
        employeeButton->raise();
        empIoyeeIcon->raise();
        teamsButton->raise();
        teamsIcon->raise();
        matchsButton->raise();
        matchsIcon->raise();
        playersButton->raise();
        playersIcon->raise();
        stadiumsButton->raise();
        stadiumIcon->raise();
        partnersButton->raise();
        partnersIcon->raise();

        retranslateUi(homepage);

        QMetaObject::connectSlotsByName(homepage);
    } // setupUi

    void retranslateUi(QWidget *homepage)
    {
        homepage->setWindowTitle(QCoreApplication::translate("homepage", "Form", nullptr));
        myAccountButton->setText(QString());
        usernameLabel->setText(QString());
        accountSettingsLabel->setText(QCoreApplication::translate("homepage", "account settings", nullptr));
        timeLabel->setText(QString());
        label->setText(QString());
        AccountSettingsGrpBox->setTitle(QString());
        configureFidButton->setText(QCoreApplication::translate("homepage", "Configure Face Recognition", nullptr));
        closeButton->setText(QCoreApplication::translate("homepage", "Close", nullptr));
        empIoyeeIcon->setText(QString());
        employeeButton->setText(QCoreApplication::translate("homepage", "      Employees", nullptr));
        teamsButton->setText(QCoreApplication::translate("homepage", "Teams", nullptr));
        teamsIcon->setText(QString());
        matchsButton->setText(QCoreApplication::translate("homepage", "Matchs", nullptr));
        matchsIcon->setText(QString());
        playersButton->setText(QCoreApplication::translate("homepage", "Players", nullptr));
        playersIcon->setText(QString());
        stadiumsButton->setText(QCoreApplication::translate("homepage", "Stadiums", nullptr));
        stadiumIcon->setText(QString());
        partnersButton->setText(QCoreApplication::translate("homepage", "Partners", nullptr));
        partnersIcon->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class homepage: public Ui_homepage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEPAGE_H
