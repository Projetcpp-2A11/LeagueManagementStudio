/********************************************************************************
** Form generated from reading UI file 'employeeupdateform.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYEEUPDATEFORM_H
#define UI_EMPLOYEEUPDATEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_employeeUpdateForm
{
public:
    QWidget *area;
    QLabel *label;
    QLineEdit *firstName;
    QLineEdit *lastName;
    QLineEdit *address;
    QLineEdit *phoneNum;
    QComboBox *department;
    QLineEdit *face;
    QLineEdit *voice;
    QPushButton *save_exit;
    QPushButton *cancel;
    QLabel *userIDLabel;
    QLineEdit *position;

    void setupUi(QWidget *employeeUpdateForm)
    {
        if (employeeUpdateForm->objectName().isEmpty())
            employeeUpdateForm->setObjectName("employeeUpdateForm");
        employeeUpdateForm->resize(576, 455);
        area = new QWidget(employeeUpdateForm);
        area->setObjectName("area");
        area->setGeometry(QRect(-20, 0, 621, 481));
        area->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, \n"
"                                x1:0, y1:0, x2:0, y2:1, \n"
"                                stop:0 rgba(6, 6, 6, 255), \n"
"                                stop:0.41 rgba(56, 50, 52, 255), \n"
"                                stop:1 rgba(34, 33, 33, 255));;\n"
""));
        label = new QLabel(area);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 10, 341, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("Azonix")});
        font.setPointSize(22);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("background:transparent;"));
        firstName = new QLineEdit(area);
        firstName->setObjectName("firstName");
        firstName->setGeometry(QRect(50, 100, 151, 41));
        firstName->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        lastName = new QLineEdit(area);
        lastName->setObjectName("lastName");
        lastName->setGeometry(QRect(50, 160, 151, 41));
        lastName->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        address = new QLineEdit(area);
        address->setObjectName("address");
        address->setGeometry(QRect(50, 240, 151, 31));
        address->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        phoneNum = new QLineEdit(area);
        phoneNum->setObjectName("phoneNum");
        phoneNum->setGeometry(QRect(250, 100, 191, 31));
        phoneNum->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        department = new QComboBox(area);
        department->addItem(QString());
        department->addItem(QString());
        department->addItem(QString());
        department->setObjectName("department");
        department->setGeometry(QRect(250, 160, 191, 41));
        department->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
        face = new QLineEdit(area);
        face->setObjectName("face");
        face->setGeometry(QRect(250, 320, 191, 31));
        face->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        voice = new QLineEdit(area);
        voice->setObjectName("voice");
        voice->setGeometry(QRect(50, 320, 161, 31));
        voice->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        save_exit = new QPushButton(area);
        save_exit->setObjectName("save_exit");
        save_exit->setGeometry(QRect(240, 380, 111, 41));
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
        cancel->setGeometry(QRect(370, 380, 111, 41));
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
        userIDLabel = new QLabel(area);
        userIDLabel->setObjectName("userIDLabel");
        userIDLabel->setGeometry(QRect(385, 12, 321, 61));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Azonix")});
        font1.setPointSize(20);
        userIDLabel->setFont(font1);
        userIDLabel->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"color:yellow;\n"
""));
        position = new QLineEdit(area);
        position->setObjectName("position");
        position->setGeometry(QRect(250, 240, 191, 31));
        position->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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

        retranslateUi(employeeUpdateForm);

        QMetaObject::connectSlotsByName(employeeUpdateForm);
    } // setupUi

    void retranslateUi(QWidget *employeeUpdateForm)
    {
        employeeUpdateForm->setWindowTitle(QCoreApplication::translate("employeeUpdateForm", "Form", nullptr));
        label->setText(QCoreApplication::translate("employeeUpdateForm", "Update Employee :", nullptr));
        firstName->setPlaceholderText(QCoreApplication::translate("employeeUpdateForm", "First Name", nullptr));
        lastName->setPlaceholderText(QCoreApplication::translate("employeeUpdateForm", "Last Name", nullptr));
        address->setPlaceholderText(QCoreApplication::translate("employeeUpdateForm", "address", nullptr));
        phoneNum->setPlaceholderText(QCoreApplication::translate("employeeUpdateForm", "Phone Number", nullptr));
        department->setItemText(0, QCoreApplication::translate("employeeUpdateForm", "Human Resources", nullptr));
        department->setItemText(1, QCoreApplication::translate("employeeUpdateForm", "Federation", nullptr));
        department->setItemText(2, QCoreApplication::translate("employeeUpdateForm", "Municipality", nullptr));

        department->setPlaceholderText(QCoreApplication::translate("employeeUpdateForm", "Update Department", nullptr));
        face->setPlaceholderText(QCoreApplication::translate("employeeUpdateForm", "face id ", nullptr));
        voice->setPlaceholderText(QCoreApplication::translate("employeeUpdateForm", "voice id", nullptr));
        save_exit->setText(QCoreApplication::translate("employeeUpdateForm", "Save and Exit", nullptr));
        cancel->setText(QCoreApplication::translate("employeeUpdateForm", "Cancel Update", nullptr));
        userIDLabel->setText(QCoreApplication::translate("employeeUpdateForm", "label", nullptr));
        position->setPlaceholderText(QCoreApplication::translate("employeeUpdateForm", "position", nullptr));
    } // retranslateUi

};

namespace Ui {
    class employeeUpdateForm: public Ui_employeeUpdateForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYEEUPDATEFORM_H
