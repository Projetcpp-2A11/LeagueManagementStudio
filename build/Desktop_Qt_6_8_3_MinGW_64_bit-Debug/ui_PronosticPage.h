/********************************************************************************
** Form generated from reading UI file 'PronosticPage.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRONOSTICPAGE_H
#define UI_PRONOSTICPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *area;
    QPushButton *cancelpronosticButton;
    QLabel *lblForme;
    QLabel *lblCote1;
    QLabel *lblFormeE1;
    QLabel *lblTitreteam1;
    QLabel *logoteam2;
    QLabel *lblCote2;
    QLabel *lblDate;
    QLabel *lblCotes;
    QLabel *lblCoteX;
    QLabel *label;
    QLabel *logoteam1;
    QLabel *lblFormeE2;
    QLabel *lblTitreteam2;
    QLineEdit *lineEdit;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(1161, 782);
        area = new QWidget(Dialog);
        area->setObjectName("area");
        area->setGeometry(QRect(70, -10, 1091, 791));
        area->setAutoFillBackground(false);
        area->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, \n"
"                                x1:0, y1:0, x2:0, y2:1, \n"
"                                stop:0 rgba(6, 6, 6, 255), \n"
"                                stop:0.41 rgba(56, 50, 52, 255), \n"
"                                stop:1 rgba(34, 33, 33, 255));;\n"
""));
        cancelpronosticButton = new QPushButton(area);
        cancelpronosticButton->setObjectName("cancelpronosticButton");
        cancelpronosticButton->setGeometry(QRect(380, 720, 271, 51));
        QFont font;
        font.setPointSize(18);
        cancelpronosticButton->setFont(font);
        cancelpronosticButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        cancelpronosticButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color:qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));;  ;  \n"
"border-radius:10px;\n"
"color:white;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: qlineargradient(x1: 0.25, y1: 0, x2: 0.75, y2: 1, \n"
"                            stop: 0 rgba(0, 255, 254, 255),     \n"
"                            stop: 0.26 rgba(38, 170, 196, 255), \n"
"                            stop: 0.67 rgba(89, 85, 131, 255),\n"
"                            stop: 1 rgba(0, 238, 255, 255));  ; \n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("textures/addIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        cancelpronosticButton->setIcon(icon);
        cancelpronosticButton->setIconSize(QSize(50, 50));
        lblForme = new QLabel(area);
        lblForme->setObjectName("lblForme");
        lblForme->setGeometry(QRect(0, 550, 121, 41));
        lblForme->setStyleSheet(QString::fromUtf8("font-size: 18px;\n"
"font-weight: bold;\n"
"color: red;\n"
""));
        lblForme->setFrameShape(QFrame::Shape::StyledPanel);
        lblCote1 = new QLabel(area);
        lblCote1->setObjectName("lblCote1");
        lblCote1->setGeometry(QRect(90, 450, 211, 41));
        lblCote1->setStyleSheet(QString::fromUtf8("font-size: 16px;\n"
"color: #333;\n"
""));
        lblCote1->setFrameShape(QFrame::Shape::StyledPanel);
        lblFormeE1 = new QLabel(area);
        lblFormeE1->setObjectName("lblFormeE1");
        lblFormeE1->setGeometry(QRect(320, 620, 161, 41));
        lblFormeE1->setStyleSheet(QString::fromUtf8("font-size: 16px;\n"
"color: #333;\n"
""));
        lblFormeE1->setFrameShape(QFrame::Shape::StyledPanel);
        lblTitreteam1 = new QLabel(area);
        lblTitreteam1->setObjectName("lblTitreteam1");
        lblTitreteam1->setGeometry(QRect(270, 290, 121, 31));
        lblTitreteam1->setStyleSheet(QString::fromUtf8("font-size: 18px;\n"
"font-weight: bold;\n"
"color: white;\n"
""));
        lblTitreteam1->setFrameShape(QFrame::Shape::StyledPanel);
        logoteam2 = new QLabel(area);
        logoteam2->setObjectName("logoteam2");
        logoteam2->setGeometry(QRect(250, 150, 141, 121));
        logoteam2->setStyleSheet(QString::fromUtf8("border: 1px solid #333;\n"
"border-radius: 5px;\n"
"max-width: 200px;\n"
"max-height: 200px;\n"
""));
        logoteam2->setFrameShape(QFrame::Shape::StyledPanel);
        lblCote2 = new QLabel(area);
        lblCote2->setObjectName("lblCote2");
        lblCote2->setGeometry(QRect(680, 450, 211, 41));
        lblCote2->setStyleSheet(QString::fromUtf8("font-size: 16px;\n"
"color: #333;\n"
""));
        lblCote2->setFrameShape(QFrame::Shape::StyledPanel);
        lblDate = new QLabel(area);
        lblDate->setObjectName("lblDate");
        lblDate->setGeometry(QRect(440, 90, 171, 41));
        lblDate->setStyleSheet(QString::fromUtf8("font-size: 16px;\n"
"color: #333;\n"
""));
        lblDate->setFrameShape(QFrame::Shape::StyledPanel);
        lblCotes = new QLabel(area);
        lblCotes->setObjectName("lblCotes");
        lblCotes->setGeometry(QRect(0, 350, 121, 41));
        lblCotes->setStyleSheet(QString::fromUtf8("font-size: 18px;\n"
"font-weight: bold;\n"
"color: red;\n"
""));
        lblCotes->setFrameShape(QFrame::Shape::StyledPanel);
        lblCoteX = new QLabel(area);
        lblCoteX->setObjectName("lblCoteX");
        lblCoteX->setGeometry(QRect(390, 450, 211, 41));
        lblCoteX->setStyleSheet(QString::fromUtf8("font-size: 16px;\n"
"color: #333;\n"
""));
        lblCoteX->setFrameShape(QFrame::Shape::StyledPanel);
        lblCoteX->setLineWidth(1);
        lblCoteX->setMidLineWidth(0);
        label = new QLabel(area);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 40, 341, 61));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Azonix")});
        font1.setPointSize(22);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("background:transparent;"));
        logoteam1 = new QLabel(area);
        logoteam1->setObjectName("logoteam1");
        logoteam1->setGeometry(QRect(670, 150, 151, 121));
        logoteam1->setStyleSheet(QString::fromUtf8("border: 1px solid #333;\n"
"border-radius: 5px;\n"
"max-width: 200px;\n"
"max-height: 200px;\n"
""));
        logoteam1->setFrameShape(QFrame::Shape::StyledPanel);
        lblFormeE2 = new QLabel(area);
        lblFormeE2->setObjectName("lblFormeE2");
        lblFormeE2->setGeometry(QRect(570, 620, 161, 41));
        lblFormeE2->setStyleSheet(QString::fromUtf8("font-size: 16px;\n"
"color: #333;\n"
""));
        lblFormeE2->setFrameShape(QFrame::Shape::StyledPanel);
        lblTitreteam2 = new QLabel(area);
        lblTitreteam2->setObjectName("lblTitreteam2");
        lblTitreteam2->setGeometry(QRect(670, 290, 121, 31));
        lblTitreteam2->setStyleSheet(QString::fromUtf8("font-size: 20px;\n"
"font-weight: bold;\n"
"color:white;\n"
""));
        lblTitreteam2->setFrameShape(QFrame::Shape::StyledPanel);
        lineEdit = new QLineEdit(area);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(470, 160, 113, 101));
        lineEdit->setAutoFillBackground(false);
        lineEdit->setStyleSheet(QString::fromUtf8("font-size: 40px;  /* Ajuste la taille de la police selon tes besoins */\n"
"font-weight: bold;\n"
"color: red;\n"
"background-color: transparent;\n"
""));
        lineEdit->setFrame(false);

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        cancelpronosticButton->setText(QCoreApplication::translate("Dialog", "cancel pronostic", nullptr));
        lblForme->setText(QCoreApplication::translate("Dialog", "       Forme", nullptr));
        lblCote1->setText(QCoreApplication::translate("Dialog", "TextLabel", nullptr));
        lblFormeE1->setText(QCoreApplication::translate("Dialog", "TextLabel", nullptr));
        lblTitreteam1->setText(QCoreApplication::translate("Dialog", "TextLabel", nullptr));
        logoteam2->setText(QCoreApplication::translate("Dialog", "TextLabel", nullptr));
        lblCote2->setText(QCoreApplication::translate("Dialog", "TextLabel", nullptr));
        lblDate->setText(QCoreApplication::translate("Dialog", "TextLabel", nullptr));
        lblCotes->setText(QCoreApplication::translate("Dialog", "       Cotes", nullptr));
        lblCoteX->setText(QCoreApplication::translate("Dialog", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "Pronostic Match :", nullptr));
        logoteam1->setText(QCoreApplication::translate("Dialog", "TextLabel", nullptr));
        lblFormeE2->setText(QCoreApplication::translate("Dialog", "TextLabel", nullptr));
        lblTitreteam2->setText(QCoreApplication::translate("Dialog", "TextLabel", nullptr));
#if QT_CONFIG(accessibility)
        lineEdit->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
        lineEdit->setText(QCoreApplication::translate("Dialog", "   vs", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRONOSTICPAGE_H
