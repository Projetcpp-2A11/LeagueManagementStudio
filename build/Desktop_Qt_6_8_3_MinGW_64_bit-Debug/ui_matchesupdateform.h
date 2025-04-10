/********************************************************************************
** Form generated from reading UI file 'matchesupdateform.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATCHESUPDATEFORM_H
#define UI_MATCHESUPDATEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_matchesUpdateForm
{
public:
    QWidget *area;
    QLabel *label;
    QPushButton *save_exit;
    QPushButton *cancel;
    QLabel *matchIDLabel;
    QComboBox *team1;
    QComboBox *team2;
    QLineEdit *score;
    QComboBox *stadium;
    QDateEdit *dateEdit;
    QLabel *mesupteam;
    QLabel *mesupteam2;
    QLabel *mesupscore;
    QLabel *mesupstaduim;
    QLabel *mesupdate;

    void setupUi(QWidget *matchesUpdateForm)
    {
        if (matchesUpdateForm->objectName().isEmpty())
            matchesUpdateForm->setObjectName("matchesUpdateForm");
        matchesUpdateForm->resize(739, 510);
        area = new QWidget(matchesUpdateForm);
        area->setObjectName("area");
        area->setGeometry(QRect(0, 0, 751, 511));
        area->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, \n"
"                                x1:0, y1:0, x2:0, y2:1, \n"
"                                stop:0 rgba(6, 6, 6, 255), \n"
"                                stop:0.41 rgba(56, 50, 52, 255), \n"
"                                stop:1 rgba(34, 33, 33, 255));;\n"
""));
        label = new QLabel(area);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 10, 341, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("Azonix")});
        font.setPointSize(22);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("background:transparent;"));
        save_exit = new QPushButton(area);
        save_exit->setObjectName("save_exit");
        save_exit->setGeometry(QRect(150, 400, 111, 41));
        save_exit->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color:qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));;  ;  \n"
"border-radius:10px;\n"
"color:white;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color:qlineargradient(x1: 0.25, y1: 0, x2: 0.75, y2: 1, \n"
"                            stop: 0 rgba(0, 255, 254, 255),     \n"
"                            stop: 0.26 rgba(38, 170, 196, 255), \n"
"                            stop: 0.67 rgba(89, 85, 131, 255),\n"
"                            stop: 1 rgba(0, 238, 255, 255));  \n"
"}"));
        cancel = new QPushButton(area);
        cancel->setObjectName("cancel");
        cancel->setGeometry(QRect(350, 400, 111, 41));
        cancel->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color:qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));;  ;  \n"
"border-radius:10px;\n"
"color:white;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color:qlineargradient(x1: 0.25, y1: 0, x2: 0.75, y2: 1, \n"
"                            stop: 0 rgba(0, 255, 254, 255),     \n"
"                            stop: 0.26 rgba(38, 170, 196, 255), \n"
"                            stop: 0.67 rgba(89, 85, 131, 255),\n"
"                            stop: 1 rgba(0, 238, 255, 255));  \n"
"}"));
        matchIDLabel = new QLabel(area);
        matchIDLabel->setObjectName("matchIDLabel");
        matchIDLabel->setGeometry(QRect(330, 10, 321, 61));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Azonix")});
        font1.setPointSize(20);
        matchIDLabel->setFont(font1);
        matchIDLabel->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"color:yellow;\n"
""));
        team1 = new QComboBox(area);
        team1->setObjectName("team1");
        team1->setGeometry(QRect(30, 110, 191, 31));
        team1->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: white;\n"
"    padding: 5px;\n"
"    color: black;\n"
"    font-size: 16px;\n"
"    border: 2px solid transparent; /* Default border */\n"
"}\n"
"\n"
"/* Drop-down arrow area */\n"
"QComboBox::drop-down {\n"
"    border: none;\n"
"    width: 30px;\n"
"   ; /* Keep background for drop-down */\n"
"    border-top-right-radius: 8px;\n"
"    border-bottom-right-radius: 8px;\n"
"    image: url(:/textures/textures/downArrowIcon.png);\n"
"}\n"
"\n"
"/* Hover effect */\n"
"QComboBox:hover {\n"
"    border: 3px dashed qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));\n"
"}\n"
"\n"
"/* Focus effect */\n"
"QComboBox:focus {\n"
"    border: 2px solid qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                      "
                        "      stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));\n"
"}\n"
"\n"
"/* Style for the dropdown list */\n"
"QComboBox QAbstractItemView {\n"
"    background-color: white;\n"
"    border: 2px solid #C51D34;\n"
"    selection-background-color: #ff0004;\n"
"    selection-color: white;\n"
"    border-radius: 8px;\n"
"    color: black;\n"
"}\n"
""));
        team2 = new QComboBox(area);
        team2->setObjectName("team2");
        team2->setGeometry(QRect(350, 110, 191, 31));
        team2->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: white;\n"
"    padding: 5px;\n"
"    color: black;\n"
"    font-size: 16px;\n"
"    border: 2px solid transparent; /* Default border */\n"
"}\n"
"\n"
"/* Drop-down arrow area */\n"
"QComboBox::drop-down {\n"
"    border: none;\n"
"    width: 30px;\n"
"   ; /* Keep background for drop-down */\n"
"    border-top-right-radius: 8px;\n"
"    border-bottom-right-radius: 8px;\n"
"    image: url(:/textures/textures/downArrowIcon.png);\n"
"}\n"
"\n"
"/* Hover effect */\n"
"QComboBox:hover {\n"
"    border: 3px dashed qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));\n"
"}\n"
"\n"
"/* Focus effect */\n"
"QComboBox:focus {\n"
"    border: 2px solid qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                      "
                        "      stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));\n"
"}\n"
"\n"
"/* Style for the dropdown list */\n"
"QComboBox QAbstractItemView {\n"
"    background-color: white;\n"
"    border: 2px solid #C51D34;\n"
"    selection-background-color: #ff0004;\n"
"    selection-color: white;\n"
"    border-radius: 8px;\n"
"    color: black;\n"
"}\n"
""));
        score = new QLineEdit(area);
        score->setObjectName("score");
        score->setGeometry(QRect(200, 210, 211, 31));
        score->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        stadium = new QComboBox(area);
        stadium->setObjectName("stadium");
        stadium->setGeometry(QRect(30, 310, 191, 31));
        stadium->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: white;\n"
"    padding: 5px;\n"
"    color: black;\n"
"    font-size: 16px;\n"
"    border: 2px solid transparent; /* Default border */\n"
"}\n"
"\n"
"/* Drop-down arrow area */\n"
"QComboBox::drop-down {\n"
"    border: none;\n"
"    width: 30px;\n"
"   ; /* Keep background for drop-down */\n"
"    border-top-right-radius: 8px;\n"
"    border-bottom-right-radius: 8px;\n"
"    image: url(:/textures/textures/downArrowIcon.png);\n"
"}\n"
"\n"
"/* Hover effect */\n"
"QComboBox:hover {\n"
"    border: 3px dashed qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));\n"
"}\n"
"\n"
"/* Focus effect */\n"
"QComboBox:focus {\n"
"    border: 2px solid qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                      "
                        "      stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));\n"
"}\n"
"\n"
"/* Style for the dropdown list */\n"
"QComboBox QAbstractItemView {\n"
"    background-color: white;\n"
"    border: 2px solid #C51D34;\n"
"    selection-background-color: #ff0004;\n"
"    selection-color: white;\n"
"    border-radius: 8px;\n"
"    color: black;\n"
"}\n"
""));
        dateEdit = new QDateEdit(area);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(370, 312, 181, 31));
        dateEdit->setStyleSheet(QString::fromUtf8("QDateEdit {\n"
"    background-color: white;\n"
"    padding: 5px;\n"
"    color: black;\n"
"    font-size: 16px;\n"
"    border: 2px solid transparent; /* Default border */\n"
"}\n"
"\n"
"/* Drop-down arrow area */\n"
"\n"
"/* Hover effect */\n"
"QDateEdit:hover {\n"
"    border: 3px dashed qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));\n"
"}\n"
"\n"
"\n"
""));
        mesupteam = new QLabel(area);
        mesupteam->setObjectName("mesupteam");
        mesupteam->setGeometry(QRect(30, 150, 231, 41));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Arial Rounded MT Bold")});
        font2.setPointSize(7);
        mesupteam->setFont(font2);
        mesupteam->setStyleSheet(QString::fromUtf8("border:none;\n"
"background:none;"));
        mesupteam2 = new QLabel(area);
        mesupteam2->setObjectName("mesupteam2");
        mesupteam2->setGeometry(QRect(340, 150, 231, 41));
        mesupteam2->setFont(font2);
        mesupteam2->setStyleSheet(QString::fromUtf8("border:none;\n"
"background:none;"));
        mesupscore = new QLabel(area);
        mesupscore->setObjectName("mesupscore");
        mesupscore->setGeometry(QRect(190, 250, 231, 41));
        mesupscore->setFont(font2);
        mesupscore->setStyleSheet(QString::fromUtf8("border:none;\n"
"background:none;"));
        mesupstaduim = new QLabel(area);
        mesupstaduim->setObjectName("mesupstaduim");
        mesupstaduim->setGeometry(QRect(20, 350, 231, 41));
        mesupstaduim->setFont(font2);
        mesupstaduim->setStyleSheet(QString::fromUtf8("border:none;\n"
"background:none;"));
        mesupdate = new QLabel(area);
        mesupdate->setObjectName("mesupdate");
        mesupdate->setGeometry(QRect(330, 350, 231, 41));
        mesupdate->setFont(font2);
        mesupdate->setStyleSheet(QString::fromUtf8("border:none;\n"
"background:none;"));

        retranslateUi(matchesUpdateForm);

        QMetaObject::connectSlotsByName(matchesUpdateForm);
    } // setupUi

    void retranslateUi(QWidget *matchesUpdateForm)
    {
        matchesUpdateForm->setWindowTitle(QCoreApplication::translate("matchesUpdateForm", "Form", nullptr));
        label->setText(QCoreApplication::translate("matchesUpdateForm", "Update Match :", nullptr));
        save_exit->setText(QCoreApplication::translate("matchesUpdateForm", "Save and Exit", nullptr));
        cancel->setText(QCoreApplication::translate("matchesUpdateForm", "Cancel Update", nullptr));
        matchIDLabel->setText(QCoreApplication::translate("matchesUpdateForm", "label", nullptr));
        score->setPlaceholderText(QCoreApplication::translate("matchesUpdateForm", "Updated Score", nullptr));
        stadium->setPlaceholderText(QCoreApplication::translate("matchesUpdateForm", "Stadium", nullptr));
        mesupteam->setText(QString());
        mesupteam2->setText(QString());
        mesupscore->setText(QString());
        mesupstaduim->setText(QString());
        mesupdate->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class matchesUpdateForm: public Ui_matchesUpdateForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATCHESUPDATEFORM_H
