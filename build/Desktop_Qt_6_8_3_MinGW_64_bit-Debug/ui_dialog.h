/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *area1;
    QLabel *label;
    QPushButton *applyFilterButton;
    QPushButton *cancel;
    QLabel *matchIDLabel;
    QComboBox *stadiumComboBox;
    QDateEdit *startDateEdit;
    QDateEdit *endDateEdit;
    QWidget *resultComboBox;
    QRadioButton *wonRadioButton;
    QRadioButton *lostRadioButton;
    QRadioButton *drawRadioButton;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(681, 524);
        area1 = new QWidget(Dialog);
        area1->setObjectName("area1");
        area1->setGeometry(QRect(0, 0, 671, 531));
        area1->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, \n"
"                                x1:0, y1:0, x2:0, y2:1, \n"
"                                stop:0 rgba(6, 6, 6, 255), \n"
"                                stop:0.41 rgba(56, 50, 52, 255), \n"
"                                stop:1 rgba(34, 33, 33, 255));;\n"
""));
        label = new QLabel(area1);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 10, 341, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("Azonix")});
        font.setPointSize(22);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("background:transparent;"));
        applyFilterButton = new QPushButton(area1);
        applyFilterButton->setObjectName("applyFilterButton");
        applyFilterButton->setGeometry(QRect(150, 420, 131, 41));
        applyFilterButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        cancel = new QPushButton(area1);
        cancel->setObjectName("cancel");
        cancel->setGeometry(QRect(350, 420, 111, 41));
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
        matchIDLabel = new QLabel(area1);
        matchIDLabel->setObjectName("matchIDLabel");
        matchIDLabel->setGeometry(QRect(330, 10, 321, 61));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Azonix")});
        font1.setPointSize(20);
        matchIDLabel->setFont(font1);
        matchIDLabel->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"color:yellow;\n"
""));
        stadiumComboBox = new QComboBox(area1);
        stadiumComboBox->setObjectName("stadiumComboBox");
        stadiumComboBox->setGeometry(QRect(50, 140, 191, 31));
        stadiumComboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
        startDateEdit = new QDateEdit(area1);
        startDateEdit->setObjectName("startDateEdit");
        startDateEdit->setGeometry(QRect(50, 230, 191, 31));
        startDateEdit->setStyleSheet(QString::fromUtf8("QDateEdit {\n"
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
        endDateEdit = new QDateEdit(area1);
        endDateEdit->setObjectName("endDateEdit");
        endDateEdit->setGeometry(QRect(50, 320, 191, 31));
        endDateEdit->setStyleSheet(QString::fromUtf8("QDateEdit {\n"
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
        resultComboBox = new QWidget(area1);
        resultComboBox->setObjectName("resultComboBox");
        resultComboBox->setGeometry(QRect(330, 170, 191, 131));
        wonRadioButton = new QRadioButton(resultComboBox);
        wonRadioButton->setObjectName("wonRadioButton");
        wonRadioButton->setGeometry(QRect(10, 10, 112, 26));
        lostRadioButton = new QRadioButton(resultComboBox);
        lostRadioButton->setObjectName("lostRadioButton");
        lostRadioButton->setGeometry(QRect(10, 50, 112, 26));
        drawRadioButton = new QRadioButton(resultComboBox);
        drawRadioButton->setObjectName("drawRadioButton");
        drawRadioButton->setGeometry(QRect(10, 90, 112, 26));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "filter Match :", nullptr));
        applyFilterButton->setText(QCoreApplication::translate("Dialog", "applyFilter", nullptr));
        cancel->setText(QCoreApplication::translate("Dialog", "cancelFilter", nullptr));
        matchIDLabel->setText(QCoreApplication::translate("Dialog", "label", nullptr));
        stadiumComboBox->setPlaceholderText(QCoreApplication::translate("Dialog", "Stadium", nullptr));
        wonRadioButton->setText(QCoreApplication::translate("Dialog", "win", nullptr));
        lostRadioButton->setText(QCoreApplication::translate("Dialog", "lose", nullptr));
        drawRadioButton->setText(QCoreApplication::translate("Dialog", "draw", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
