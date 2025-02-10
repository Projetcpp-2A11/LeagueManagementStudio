/********************************************************************************
** Form generated from reading UI file 'employeepage.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYEEPAGE_H
#define UI_EMPLOYEEPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_employeePage
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *sidebar;
    QPushButton *employeeButton;
    QPushButton *teamsButton;
    QPushButton *matchsButton;
    QPushButton *playersButton;
    QPushButton *stadiumsButton;
    QPushButton *partnersButton;
    QLabel *empIoyeeIcon;
    QLabel *teamsIcon;
    QLabel *matchsIcon;
    QLabel *playersIcon;
    QLabel *stadiumIcon;
    QLabel *partnersIcon;
    QWidget *contentArea;
    QLineEdit *searchEmployeeInput;
    QPushButton *searchButton;
    QPushButton *filterButton;
    QPushButton *addEmployeeButton;
    QPushButton *exportListButton;
    QPushButton *statsButton;
    QListWidget *listWidget;

    void setupUi(QWidget *employeePage)
    {
        if (employeePage->objectName().isEmpty())
            employeePage->setObjectName("employeePage");
        employeePage->resize(1057, 666);
        horizontalLayout = new QHBoxLayout(employeePage);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        sidebar = new QWidget(employeePage);
        sidebar->setObjectName("sidebar");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(sidebar->sizePolicy().hasHeightForWidth());
        sidebar->setSizePolicy(sizePolicy);
        sidebar->setMinimumSize(QSize(200, 0));
        sidebar->setStyleSheet(QString::fromUtf8("background-color:#434343;"));
        employeeButton = new QPushButton(sidebar);
        employeeButton->setObjectName("employeeButton");
        employeeButton->setGeometry(QRect(-10, 10, 181, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(16);
        employeeButton->setFont(font);
        employeeButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        employeeButton->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        employeeButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: red;             /* Red background */\n"
"    border-radius: 15px;               /* Rounded corners */\n"
"    color: white;                      /* White text */\n"
"    border: none;                      /* No border */\n"
"    padding: 10px 20px;                /* Padding inside the button */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: blue;           /* Blue background when hovered */\n"
"}\n"
"\n"
"QPushButton[selected=\"true\"] {\n"
"    background-color: blue;            /* Blue background when selected */\n"
"}"));
        teamsButton = new QPushButton(sidebar);
        teamsButton->setObjectName("teamsButton");
        teamsButton->setGeometry(QRect(-10, 100, 181, 61));
        teamsButton->setFont(font);
        teamsButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        teamsButton->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        teamsButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: red;             /* Red background */\n"
"    border-radius: 15px;               /* Rounded corners */\n"
"    color: white;                      /* White text */\n"
"    border: none;                      /* No border */\n"
"    padding: 10px 20px;                /* Padding inside the button */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: blue;           /* Blue background when hovered */\n"
"}\n"
"QPushButton:pressed, QPushButton:checked {\n"
"    background-color: blue;           /* Blue background when pressed or selected */\n"
"}"));
        matchsButton = new QPushButton(sidebar);
        matchsButton->setObjectName("matchsButton");
        matchsButton->setGeometry(QRect(-10, 210, 181, 61));
        matchsButton->setFont(font);
        matchsButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        matchsButton->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        matchsButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: red;             /* Red background */\n"
"    border-radius: 15px;               /* Rounded corners */\n"
"    color: white;                      /* White text */\n"
"    border: none;                      /* No border */\n"
"    padding: 10px 20px;                /* Padding inside the button */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: blue;           /* Blue background when hovered */\n"
"}\n"
"QPushButton:pressed, QPushButton:checked {\n"
"    background-color: blue;           /* Blue background when pressed or selected */\n"
"}"));
        playersButton = new QPushButton(sidebar);
        playersButton->setObjectName("playersButton");
        playersButton->setGeometry(QRect(-10, 330, 181, 61));
        playersButton->setFont(font);
        playersButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        playersButton->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        playersButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: red;             /* Red background */\n"
"    border-radius: 15px;               /* Rounded corners */\n"
"    color: white;                      /* White text */\n"
"    border: none;                      /* No border */\n"
"    padding: 10px 20px;                /* Padding inside the button */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: blue;           /* Blue background when hovered */\n"
"}\n"
"QPushButton:pressed, QPushButton:checked {\n"
"    background-color: blue;           /* Blue background when pressed or selected */\n"
"}"));
        stadiumsButton = new QPushButton(sidebar);
        stadiumsButton->setObjectName("stadiumsButton");
        stadiumsButton->setGeometry(QRect(-10, 460, 181, 61));
        stadiumsButton->setFont(font);
        stadiumsButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        stadiumsButton->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        stadiumsButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: red;             /* Red background */\n"
"    border-radius: 15px;               /* Rounded corners */\n"
"    color: white;                      /* White text */\n"
"    border: none;                      /* No border */\n"
"    padding: 10px 20px;                /* Padding inside the button */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: blue;           /* Blue background when hovered */\n"
"}\n"
"QPushButton:pressed, QPushButton:checked {\n"
"    background-color: blue;           /* Blue background when pressed or selected */\n"
"}"));
        partnersButton = new QPushButton(sidebar);
        partnersButton->setObjectName("partnersButton");
        partnersButton->setGeometry(QRect(-10, 570, 181, 61));
        partnersButton->setFont(font);
        partnersButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        partnersButton->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        partnersButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: red;             /* Red background */\n"
"    border-radius: 15px;               /* Rounded corners */\n"
"    color: white;                      /* White text */\n"
"    border: none;                      /* No border */\n"
"    padding: 10px 20px;                /* Padding inside the button */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: blue;           /* Blue background when hovered */\n"
"}\n"
"QPushButton:pressed, QPushButton:checked {\n"
"    background-color: blue;           /* Blue background when pressed or selected */\n"
"}"));
        empIoyeeIcon = new QLabel(sidebar);
        empIoyeeIcon->setObjectName("empIoyeeIcon");
        empIoyeeIcon->setGeometry(QRect(0, 20, 51, 41));
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(empIoyeeIcon->sizePolicy().hasHeightForWidth());
        empIoyeeIcon->setSizePolicy(sizePolicy1);
        empIoyeeIcon->setStyleSheet(QString::fromUtf8("background-color:none"));
        empIoyeeIcon->setPixmap(QPixmap(QString::fromUtf8(":/textures/textures/employeeIcon.png")));
        empIoyeeIcon->setScaledContents(true);
        teamsIcon = new QLabel(sidebar);
        teamsIcon->setObjectName("teamsIcon");
        teamsIcon->setGeometry(QRect(0, 100, 51, 61));
        teamsIcon->setStyleSheet(QString::fromUtf8("background-color:none"));
        teamsIcon->setPixmap(QPixmap(QString::fromUtf8(":/textures/textures/teamsIcon.png")));
        teamsIcon->setScaledContents(true);
        matchsIcon = new QLabel(sidebar);
        matchsIcon->setObjectName("matchsIcon");
        matchsIcon->setGeometry(QRect(0, 220, 51, 51));
        matchsIcon->setStyleSheet(QString::fromUtf8("background-color:none"));
        matchsIcon->setPixmap(QPixmap(QString::fromUtf8(":/textures/textures/matchsIcon.png")));
        matchsIcon->setScaledContents(true);
        playersIcon = new QLabel(sidebar);
        playersIcon->setObjectName("playersIcon");
        playersIcon->setGeometry(QRect(-20, 320, 91, 71));
        playersIcon->setStyleSheet(QString::fromUtf8("background-color:none"));
        playersIcon->setPixmap(QPixmap(QString::fromUtf8(":/textures/textures/playersIcon.png")));
        playersIcon->setScaledContents(true);
        stadiumIcon = new QLabel(sidebar);
        stadiumIcon->setObjectName("stadiumIcon");
        stadiumIcon->setGeometry(QRect(4, 473, 31, 31));
        stadiumIcon->setStyleSheet(QString::fromUtf8("background-color:none"));
        stadiumIcon->setPixmap(QPixmap(QString::fromUtf8(":/textures/textures/stadiumIcon.png")));
        stadiumIcon->setScaledContents(true);
        partnersIcon = new QLabel(sidebar);
        partnersIcon->setObjectName("partnersIcon");
        partnersIcon->setGeometry(QRect(-1, 585, 41, 31));
        partnersIcon->setStyleSheet(QString::fromUtf8("background-color:none"));
        partnersIcon->setPixmap(QPixmap(QString::fromUtf8(":/textures/textures/partnersIcon.png")));
        partnersIcon->setScaledContents(true);

        horizontalLayout->addWidget(sidebar);

        contentArea = new QWidget(employeePage);
        contentArea->setObjectName("contentArea");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(contentArea->sizePolicy().hasHeightForWidth());
        contentArea->setSizePolicy(sizePolicy2);
        contentArea->setStyleSheet(QString::fromUtf8("background-color:#858585;\n"
""));
        searchEmployeeInput = new QLineEdit(contentArea);
        searchEmployeeInput->setObjectName("searchEmployeeInput");
        searchEmployeeInput->setGeometry(QRect(80, 110, 181, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        searchEmployeeInput->setFont(font1);
        searchEmployeeInput->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"border:2px solid red;\n"
"border-color: rgb(255, 0, 4);\n"
"color:black;\n"
""));
        searchButton = new QPushButton(contentArea);
        searchButton->setObjectName("searchButton");
        searchButton->setGeometry(QRect(268, 110, 41, 31));
        searchButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        searchButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color:red;\n"
"\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: blue; \n"
"}"));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::SystemSearch));
        searchButton->setIcon(icon);
        filterButton = new QPushButton(contentArea);
        filterButton->setObjectName("filterButton");
        filterButton->setGeometry(QRect(317, 110, 41, 31));
        filterButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        filterButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color:red;\n"
"\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: blue; \n"
"}"));
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::AddressBookNew));
        filterButton->setIcon(icon1);
        addEmployeeButton = new QPushButton(contentArea);
        addEmployeeButton->setObjectName("addEmployeeButton");
        addEmployeeButton->setGeometry(QRect(599, 113, 161, 31));
        QFont font2;
        font2.setPointSize(18);
        addEmployeeButton->setFont(font2);
        addEmployeeButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        addEmployeeButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color:red;\n"
"border-radius:10px;\n"
"color:white;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: blue; \n"
"}"));
        exportListButton = new QPushButton(contentArea);
        exportListButton->setObjectName("exportListButton");
        exportListButton->setGeometry(QRect(80, 580, 161, 31));
        exportListButton->setFont(font2);
        exportListButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        exportListButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color:red;\n"
"border-radius:10px;\n"
"color:white;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: blue; \n"
"}"));
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::DocumentOpen));
        exportListButton->setIcon(icon2);
        statsButton = new QPushButton(contentArea);
        statsButton->setObjectName("statsButton");
        statsButton->setGeometry(QRect(600, 578, 161, 31));
        statsButton->setFont(font2);
        statsButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        statsButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color:red;\n"
"border-radius:10px;\n"
"color:white;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: blue; \n"
"}"));
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::HelpAbout));
        statsButton->setIcon(icon3);
        listWidget = new QListWidget(contentArea);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(80, 160, 681, 381));
        listWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(contentArea);


        retranslateUi(employeePage);

        QMetaObject::connectSlotsByName(employeePage);
    } // setupUi

    void retranslateUi(QWidget *employeePage)
    {
        employeePage->setWindowTitle(QCoreApplication::translate("employeePage", "Form", nullptr));
        employeeButton->setText(QCoreApplication::translate("employeePage", "      Employees", nullptr));
        teamsButton->setText(QCoreApplication::translate("employeePage", "Teams", nullptr));
        matchsButton->setText(QCoreApplication::translate("employeePage", "Matchs", nullptr));
        playersButton->setText(QCoreApplication::translate("employeePage", "Players", nullptr));
        stadiumsButton->setText(QCoreApplication::translate("employeePage", "Stadiums", nullptr));
        partnersButton->setText(QCoreApplication::translate("employeePage", "Partners", nullptr));
        empIoyeeIcon->setText(QString());
        teamsIcon->setText(QString());
        matchsIcon->setText(QString());
        playersIcon->setText(QString());
        stadiumIcon->setText(QString());
        partnersIcon->setText(QString());
        searchEmployeeInput->setPlaceholderText(QCoreApplication::translate("employeePage", "search employee", nullptr));
        searchButton->setText(QString());
        filterButton->setText(QString());
        addEmployeeButton->setText(QCoreApplication::translate("employeePage", "Add Employee", nullptr));
        exportListButton->setText(QCoreApplication::translate("employeePage", "Export List", nullptr));
        statsButton->setText(QCoreApplication::translate("employeePage", "Statistics", nullptr));
    } // retranslateUi

};

namespace Ui {
    class employeePage: public Ui_employeePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYEEPAGE_H
