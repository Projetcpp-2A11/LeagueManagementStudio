/********************************************************************************
** Form generated from reading UI file 'arduinosmarttimer.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARDUINOSMARTTIMER_H
#define UI_ARDUINOSMARTTIMER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_arduinoSmartTimer
{
public:
    QLabel *label;
    QLineEdit *matchIdInput;
    QGroupBox *interfaceGroupBox;
    QLabel *label_2;
    QLabel *ballStatusLabel;
    QLabel *label_3;
    QLabel *ballStatusLabel_2;
    QLabel *label_4;
    QLabel *addTimeLabel;
    QPushButton *resetTimerBtn;
    QPushButton *pushButton;

    void setupUi(QWidget *arduinoSmartTimer)
    {
        if (arduinoSmartTimer->objectName().isEmpty())
            arduinoSmartTimer->setObjectName("arduinoSmartTimer");
        arduinoSmartTimer->resize(940, 706);
        arduinoSmartTimer->setStyleSheet(QString::fromUtf8("\n"
"    background: qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));;  ;  \n"
"    \n"
""));
        label = new QLabel(arduinoSmartTimer);
        label->setObjectName("label");
        label->setGeometry(QRect(31, 32, 141, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("Azonix")});
        font.setPointSize(16);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("background:none;\n"
"color:black;"));
        matchIdInput = new QLineEdit(arduinoSmartTimer);
        matchIdInput->setObjectName("matchIdInput");
        matchIdInput->setGeometry(QRect(160, 40, 151, 31));
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
        interfaceGroupBox = new QGroupBox(arduinoSmartTimer);
        interfaceGroupBox->setObjectName("interfaceGroupBox");
        interfaceGroupBox->setGeometry(QRect(40, 90, 851, 581));
        interfaceGroupBox->setStyleSheet(QString::fromUtf8("background-color:lightblue;"));
        label_2 = new QLabel(interfaceGroupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 50, 191, 51));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("background:none;\n"
"color:black;"));
        ballStatusLabel = new QLabel(interfaceGroupBox);
        ballStatusLabel->setObjectName("ballStatusLabel");
        ballStatusLabel->setGeometry(QRect(310, 50, 191, 51));
        ballStatusLabel->setFont(font);
        ballStatusLabel->setStyleSheet(QString::fromUtf8("background:none;\n"
"color:green"));
        label_3 = new QLabel(interfaceGroupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 170, 191, 51));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("background:none;\n"
"color:black;"));
        ballStatusLabel_2 = new QLabel(interfaceGroupBox);
        ballStatusLabel_2->setObjectName("ballStatusLabel_2");
        ballStatusLabel_2->setGeometry(QRect(310, 170, 191, 51));
        ballStatusLabel_2->setFont(font);
        ballStatusLabel_2->setStyleSheet(QString::fromUtf8("background:none;\n"
"color:green"));
        label_4 = new QLabel(interfaceGroupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 310, 211, 51));
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("background:none;\n"
"color:black;"));
        addTimeLabel = new QLabel(interfaceGroupBox);
        addTimeLabel->setObjectName("addTimeLabel");
        addTimeLabel->setGeometry(QRect(300, 310, 91, 51));
        addTimeLabel->setFont(font);
        addTimeLabel->setStyleSheet(QString::fromUtf8("background:none;\n"
"color:green"));
        resetTimerBtn = new QPushButton(interfaceGroupBox);
        resetTimerBtn->setObjectName("resetTimerBtn");
        resetTimerBtn->setGeometry(QRect(460, 320, 51, 31));
        QFont font1;
        font1.setPointSize(12);
        resetTimerBtn->setFont(font1);
        resetTimerBtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::EditUndo));
        resetTimerBtn->setIcon(icon);
        pushButton = new QPushButton(arduinoSmartTimer);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(320, 40, 51, 31));
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
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::HelpFaq));
        pushButton->setIcon(icon1);

        retranslateUi(arduinoSmartTimer);

        QMetaObject::connectSlotsByName(arduinoSmartTimer);
    } // setupUi

    void retranslateUi(QWidget *arduinoSmartTimer)
    {
        arduinoSmartTimer->setWindowTitle(QCoreApplication::translate("arduinoSmartTimer", "Form", nullptr));
        label->setText(QCoreApplication::translate("arduinoSmartTimer", "Match Id", nullptr));
        interfaceGroupBox->setTitle(QCoreApplication::translate("arduinoSmartTimer", "GroupBox", nullptr));
        label_2->setText(QCoreApplication::translate("arduinoSmartTimer", "Ball Status :", nullptr));
        ballStatusLabel->setText(QCoreApplication::translate("arduinoSmartTimer", "Ball is in Play", nullptr));
        label_3->setText(QCoreApplication::translate("arduinoSmartTimer", "Original Time : ", nullptr));
        ballStatusLabel_2->setText(QCoreApplication::translate("arduinoSmartTimer", "90 Minutes", nullptr));
        label_4->setText(QCoreApplication::translate("arduinoSmartTimer", "AdditionalTime : ", nullptr));
        addTimeLabel->setText(QCoreApplication::translate("arduinoSmartTimer", "0", nullptr));
        resetTimerBtn->setText(QString());
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class arduinoSmartTimer: public Ui_arduinoSmartTimer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARDUINOSMARTTIMER_H
