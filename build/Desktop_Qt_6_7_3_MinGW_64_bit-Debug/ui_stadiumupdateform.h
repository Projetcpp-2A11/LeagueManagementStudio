/********************************************************************************
** Form generated from reading UI file 'stadiumupdateform.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STADIUMUPDATEFORM_H
#define UI_STADIUMUPDATEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_stadiumupdateform
{
public:
    QWidget *widget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *stadiumid;
    QLineEdit *name;
    QLineEdit *nameER;
    QLineEdit *adress;
    QLineEdit *adressER;
    QLineEdit *capacity;
    QLineEdit *capacityER;
    QLineEdit *status;
    QLineEdit *statusER;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QPushButton *save;
    QPushButton *cancel;

    void setupUi(QWidget *stadiumupdateform)
    {
        if (stadiumupdateform->objectName().isEmpty())
            stadiumupdateform->setObjectName("stadiumupdateform");
        stadiumupdateform->resize(935, 495);
        stadiumupdateform->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255))"));
        widget = new QWidget(stadiumupdateform);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(-60, -20, 1011, 511));
        widget->setStyleSheet(QString::fromUtf8("QWidget_background_color:rgb(0, 0, 0);"));
        layoutWidget = new QWidget(widget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(290, 30, 461, 401));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        stadiumid = new QLineEdit(layoutWidget);
        stadiumid->setObjectName("stadiumid");
        stadiumid->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
"}"));
        stadiumid->setReadOnly(true);

        verticalLayout->addWidget(stadiumid);

        name = new QLineEdit(layoutWidget);
        name->setObjectName("name");
        name->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
"}"));

        verticalLayout->addWidget(name);

        nameER = new QLineEdit(layoutWidget);
        nameER->setObjectName("nameER");
        nameER->setStyleSheet(QString::fromUtf8("color:rgb(0, 0, 0);"));
        nameER->setReadOnly(true);

        verticalLayout->addWidget(nameER);

        adress = new QLineEdit(layoutWidget);
        adress->setObjectName("adress");
        adress->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
"}"));

        verticalLayout->addWidget(adress);

        adressER = new QLineEdit(layoutWidget);
        adressER->setObjectName("adressER");
        adressER->setStyleSheet(QString::fromUtf8("color:rgb(170, 0, 0);"));
        adressER->setReadOnly(true);

        verticalLayout->addWidget(adressER);

        capacity = new QLineEdit(layoutWidget);
        capacity->setObjectName("capacity");
        capacity->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
"}"));

        verticalLayout->addWidget(capacity);

        capacityER = new QLineEdit(layoutWidget);
        capacityER->setObjectName("capacityER");
        capacityER->setStyleSheet(QString::fromUtf8("color:rgb(170, 0, 0);"));
        capacityER->setReadOnly(true);

        verticalLayout->addWidget(capacityER);

        status = new QLineEdit(layoutWidget);
        status->setObjectName("status");
        status->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
"}"));

        verticalLayout->addWidget(status);

        statusER = new QLineEdit(layoutWidget);
        statusER->setObjectName("statusER");
        statusER->setStyleSheet(QString::fromUtf8("color:rgb(170, 0, 0);"));
        statusER->setReadOnly(true);

        verticalLayout->addWidget(statusER);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(170, 90, 113, 28));
        lineEdit->setReadOnly(true);
        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(170, 170, 113, 28));
        lineEdit_2->setReadOnly(true);
        lineEdit_3 = new QLineEdit(widget);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(170, 260, 113, 28));
        lineEdit_3->setReadOnly(true);
        lineEdit_4 = new QLineEdit(widget);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(170, 350, 113, 28));
        lineEdit_4->setStyleSheet(QString::fromUtf8("background_color: rgb(0, 0, 0);"));
        lineEdit_4->setReadOnly(true);
        save = new QPushButton(widget);
        save->setObjectName("save");
        save->setGeometry(QRect(771, 398, 192, 51));
        save->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(spread:pad, \n"
"                                x1:0, y1:0, x2:1, y2:1, \n"
"                                stop:0 rgba(255, 0, 0, 255), \n"
"                                stop:0.41 rgba(195, 22, 58, 255), \n"
"                                stop:1 rgba(255, 117, 0, 255));\n"
"    color: white;\n"
"    border: 2px solid #990000;\n"
"    border-radius: 10px;\n"
"    padding: 12px 24px;\n"
"    font: bold 14pt \"Segoe UI\";\n"
"    min-width: 140px;\n"
"    cursor: pointer;\n"
"    transition: all 0.3s ease; /* Transition fluide */\n"
"}\n"
"\n"
"/* Hover effect */\n"
"QPushButton:hover {\n"
"    background: qlineargradient(spread:pad, \n"
"                                x1:0.25, y1:0, x2:0.75, y2:1, \n"
"                                stop:0 rgba(0, 255, 254, 255),     \n"
"                                stop:0.26 rgba(38, 170, 196, 255), \n"
"                                stop:0.67 rgba(89, 85, 131, 255),\n"
"                                stop:1 rgb"
                        "a(0, 238, 255, 255));\n"
"    border: 2px solid #ff0004; /* Border change on hover */\n"
"    color: #ffffff;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* Pressed effect */\n"
"QPushButton:pressed {\n"
"    background-color: #cc0000;\n"
"    border: 2px solid #990000;\n"
"    color: white;\n"
"    padding-left: 14px;\n"
"    padding-top: 14px;\n"
"    box-shadow: inset 0 0 10px rgba(0, 0, 0, 0.2); /* Shadow on press */\n"
"}\n"
""));
        cancel = new QPushButton(widget);
        cancel->setObjectName("cancel");
        cancel->setGeometry(QRect(771, 452, 192, 51));
        cancel->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(spread:pad, \n"
"                                x1:0, y1:0, x2:1, y2:1, \n"
"                                stop:0 rgba(255, 0, 0, 255), \n"
"                                stop:0.41 rgba(195, 22, 58, 255), \n"
"                                stop:1 rgba(255, 117, 0, 255));\n"
"    color: white;\n"
"    border: 2px solid #990000;\n"
"    border-radius: 10px;\n"
"    padding: 12px 24px;\n"
"    font: bold 14pt \"Segoe UI\";\n"
"    min-width: 140px;\n"
"    cursor: pointer;\n"
"    transition: all 0.3s ease; /* Transition fluide */\n"
"}\n"
"\n"
"/* Hover effect */\n"
"QPushButton:hover {\n"
"    background: qlineargradient(spread:pad, \n"
"                                x1:0.25, y1:0, x2:0.75, y2:1, \n"
"                                stop:0 rgba(0, 255, 254, 255),     \n"
"                                stop:0.26 rgba(38, 170, 196, 255), \n"
"                                stop:0.67 rgba(89, 85, 131, 255),\n"
"                                stop:1 rgb"
                        "a(0, 238, 255, 255));\n"
"    border: 2px solid #ff0004; /* Border change on hover */\n"
"    color: #ffffff;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* Pressed effect */\n"
"QPushButton:pressed {\n"
"    background-color: #cc0000;\n"
"    border: 2px solid #990000;\n"
"    color: white;\n"
"    padding-left: 14px;\n"
"    padding-top: 14px;\n"
"    box-shadow: inset 0 0 10px rgba(0, 0, 0, 0.2); /* Shadow on press */\n"
"}\n"
""));

        retranslateUi(stadiumupdateform);

        QMetaObject::connectSlotsByName(stadiumupdateform);
    } // setupUi

    void retranslateUi(QWidget *stadiumupdateform)
    {
        stadiumupdateform->setWindowTitle(QCoreApplication::translate("stadiumupdateform", "Form", nullptr));
        stadiumid->setText(QCoreApplication::translate("stadiumupdateform", "ID", nullptr));
        name->setText(QCoreApplication::translate("stadiumupdateform", "Name", nullptr));
        adress->setText(QCoreApplication::translate("stadiumupdateform", "Adress", nullptr));
        capacity->setText(QCoreApplication::translate("stadiumupdateform", "Capacity", nullptr));
        status->setText(QCoreApplication::translate("stadiumupdateform", "Status", nullptr));
        lineEdit->setText(QCoreApplication::translate("stadiumupdateform", "Name :", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("stadiumupdateform", "Adress :", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("stadiumupdateform", "Capacity :", nullptr));
        lineEdit_4->setText(QCoreApplication::translate("stadiumupdateform", "Status : ", nullptr));
        save->setText(QCoreApplication::translate("stadiumupdateform", "Update", nullptr));
        cancel->setText(QCoreApplication::translate("stadiumupdateform", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class stadiumupdateform: public Ui_stadiumupdateform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STADIUMUPDATEFORM_H
