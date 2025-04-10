/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "custombutton.h"
#include "customtextinput.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    CustomButton *login;
    CustomTextInput *username;
    CustomTextInput *password;
    QLabel *loginText;
    QPushButton *forgotPasswordClicked;
    QLabel *ErrorZone;
    QLabel *usernameLabel;
    QLabel *passwordLabel;
    QPushButton *facialRecogButton;
    QPushButton *vocalRecogButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1920, 1080);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        login = new CustomButton(centralwidget);
        login->setObjectName("login");
        login->setGeometry(QRect(180, 310, 241, 111));
        login->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        login->setStyleSheet(QString::fromUtf8(""));
        username = new CustomTextInput(centralwidget);
        username->setObjectName("username");
        username->setGeometry(QRect(1320, 390, 521, 71));
        QFont font;
        font.setFamilies({QString::fromUtf8("Azonix")});
        font.setPointSize(55);
        username->setFont(font);
        password = new CustomTextInput(centralwidget);
        password->setObjectName("password");
        password->setGeometry(QRect(1320, 740, 521, 71));
        password->setFont(font);
        loginText = new QLabel(centralwidget);
        loginText->setObjectName("loginText");
        loginText->setGeometry(QRect(940, 850, 111, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Azonix")});
        font1.setPointSize(25);
        loginText->setFont(font1);
        loginText->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        forgotPasswordClicked = new QPushButton(centralwidget);
        forgotPasswordClicked->setObjectName("forgotPasswordClicked");
        forgotPasswordClicked->setGeometry(QRect(1230, 490, 291, 51));
        forgotPasswordClicked->setMaximumSize(QSize(16777215, 16777215));
        forgotPasswordClicked->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        forgotPasswordClicked->setStyleSheet(QString::fromUtf8("border: none; background: none; color: blue; }\n"
"                      QPushButton:hover { text-decoration: underline; "));
        ErrorZone = new QLabel(centralwidget);
        ErrorZone->setObjectName("ErrorZone");
        ErrorZone->setGeometry(QRect(460, 960, 1171, 71));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Azonix")});
        font2.setPointSize(20);
        ErrorZone->setFont(font2);
        ErrorZone->setStyleSheet(QString::fromUtf8("color:red"));
        ErrorZone->setAlignment(Qt::AlignmentFlag::AlignCenter);
        usernameLabel = new QLabel(centralwidget);
        usernameLabel->setObjectName("usernameLabel");
        usernameLabel->setGeometry(QRect(1330, 340, 371, 51));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Origin Tech Demo")});
        font3.setPointSize(30);
        usernameLabel->setFont(font3);
        usernameLabel->setStyleSheet(QString::fromUtf8("color:black"));
        passwordLabel = new QLabel(centralwidget);
        passwordLabel->setObjectName("passwordLabel");
        passwordLabel->setGeometry(QRect(1330, 680, 281, 31));
        passwordLabel->setFont(font3);
        passwordLabel->setStyleSheet(QString::fromUtf8("color:black\n"
""));
        facialRecogButton = new QPushButton(centralwidget);
        facialRecogButton->setObjectName("facialRecogButton");
        facialRecogButton->setGeometry(QRect(1550, 960, 61, 61));
        facialRecogButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        facialRecogButton->setStyleSheet(QString::fromUtf8("background-color:red;"));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::CameraPhoto));
        facialRecogButton->setIcon(icon);
        vocalRecogButton = new QPushButton(centralwidget);
        vocalRecogButton->setObjectName("vocalRecogButton");
        vocalRecogButton->setGeometry(QRect(1630, 960, 61, 61));
        vocalRecogButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        vocalRecogButton->setStyleSheet(QString::fromUtf8("background-color:red;"));
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::AudioInputMicrophone));
        vocalRecogButton->setIcon(icon1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1920, 25));
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
        login->setText(QString());
        username->setPlaceholderText(QString());
        password->setPlaceholderText(QString());
        loginText->setText(QCoreApplication::translate("MainWindow", "LOGIN", nullptr));
        forgotPasswordClicked->setText(QString());
        ErrorZone->setText(QString());
        usernameLabel->setText(QCoreApplication::translate("MainWindow", "Username", nullptr));
        passwordLabel->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        facialRecogButton->setText(QString());
        vocalRecogButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
