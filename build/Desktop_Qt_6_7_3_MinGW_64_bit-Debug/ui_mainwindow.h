/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *loginText;
    QPushButton *forgotPasswordClicked;
    QLabel *ErrorZone;
    QLabel *usernameLabel;
    QLabel *passwordLabel;
    QPushButton *facialRecogButton;
    QPushButton *vocalRecogButton;
    QLineEdit *username;
    QLineEdit *password;
    QPushButton *login;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setEnabled(true);
        MainWindow->resize(1080, 631);
        MainWindow->setStyleSheet(QString::fromUtf8(" QMainWindow {\n"
"           background-image: url(:/textures/textures/login_background.png);\n"
"         background-position: center;\n"
"        background-repeat: no-repeat;\n"
"           background-size: cover;\n"
"        }"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("QWidget#centralwidget {\n"
"\n"
"background:transparent;\n"
"\n"
"}"));
        loginText = new QLabel(centralwidget);
        loginText->setObjectName("loginText");
        loginText->setGeometry(QRect(940, 850, 111, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Azonix")});
        font.setPointSize(25);
        loginText->setFont(font);
        loginText->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        forgotPasswordClicked = new QPushButton(centralwidget);
        forgotPasswordClicked->setObjectName("forgotPasswordClicked");
        forgotPasswordClicked->setGeometry(QRect(723, 430, 181, 31));
        forgotPasswordClicked->setMaximumSize(QSize(16777215, 16777215));
        forgotPasswordClicked->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        forgotPasswordClicked->setStyleSheet(QString::fromUtf8("border: none; background: none; color: blue; }\n"
"                      QPushButton:hover { text-decoration: underline; "));
        ErrorZone = new QLabel(centralwidget);
        ErrorZone->setObjectName("ErrorZone");
        ErrorZone->setGeometry(QRect(30, 440, 1171, 81));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Azonix")});
        font1.setPointSize(16);
        ErrorZone->setFont(font1);
        ErrorZone->setStyleSheet(QString::fromUtf8("color:red"));
        ErrorZone->setAlignment(Qt::AlignmentFlag::AlignCenter);
        usernameLabel = new QLabel(centralwidget);
        usernameLabel->setObjectName("usernameLabel");
        usernameLabel->setGeometry(QRect(720, 190, 371, 51));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Origin Tech Demo")});
        font2.setPointSize(30);
        usernameLabel->setFont(font2);
        usernameLabel->setStyleSheet(QString::fromUtf8("color:black"));
        passwordLabel = new QLabel(centralwidget);
        passwordLabel->setObjectName("passwordLabel");
        passwordLabel->setGeometry(QRect(710, 330, 281, 31));
        passwordLabel->setFont(font2);
        passwordLabel->setStyleSheet(QString::fromUtf8("color:black\n"
""));
        facialRecogButton = new QPushButton(centralwidget);
        facialRecogButton->setObjectName("facialRecogButton");
        facialRecogButton->setGeometry(QRect(970, 30, 51, 51));
        facialRecogButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        facialRecogButton->setStyleSheet(QString::fromUtf8("background-color:red;"));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::CameraPhoto));
        facialRecogButton->setIcon(icon);
        vocalRecogButton = new QPushButton(centralwidget);
        vocalRecogButton->setObjectName("vocalRecogButton");
        vocalRecogButton->setGeometry(QRect(890, 30, 51, 51));
        vocalRecogButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        vocalRecogButton->setStyleSheet(QString::fromUtf8("background-color:red;"));
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::AudioInputMicrophone));
        vocalRecogButton->setIcon(icon1);
        username = new QLineEdit(centralwidget);
        username->setObjectName("username");
        username->setGeometry(QRect(710, 250, 311, 41));
        username->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #c21d1d;          /* Background color */\n"
"    border-radius: 15px;                 /* Rounded corners */\n"
"    border: 2px solid #8B0000;           /* Darker border */\n"
"    color: white;                        /* Text color */\n"
"    padding: 10px;                       /* Padding inside the input box */\n"
"    font-size: 14px;                     /* Font size */\n"
"}\n"
""));
        password = new QLineEdit(centralwidget);
        password->setObjectName("password");
        password->setEnabled(true);
        password->setGeometry(QRect(710, 380, 311, 41));
        password->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: green;          /* Background color */\n"
"    border-radius: 15px;                 /* Rounded corners */\n"
"    border: 2px solid #8B0000;           /* Darker border */\n"
"    color: white;                        /* Text color */\n"
"    padding: 10px;                       /* Padding inside the input box */\n"
"    font-size: 14px;                     /* Font size */\n"
"}\n"
""));
        login = new QPushButton(centralwidget);
        login->setObjectName("login");
        login->setGeometry(QRect(360, 530, 411, 61));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Azonix")});
        font3.setPointSize(25);
        font3.setBold(false);
        font3.setItalic(false);
        login->setFont(font3);
        login->setStyleSheet(QString::fromUtf8("font: 25pt \"Azonix\";\n"
"\n"
"background-color: #b60000;\n"
"border-radius:20px"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1080, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        loginText->setText(QCoreApplication::translate("MainWindow", "LOGIN", nullptr));
        forgotPasswordClicked->setText(QString());
        ErrorZone->setText(QString());
        usernameLabel->setText(QCoreApplication::translate("MainWindow", "USER ID", nullptr));
        passwordLabel->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        facialRecogButton->setText(QString());
        vocalRecogButton->setText(QString());
        login->setText(QCoreApplication::translate("MainWindow", "Authenticate", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
