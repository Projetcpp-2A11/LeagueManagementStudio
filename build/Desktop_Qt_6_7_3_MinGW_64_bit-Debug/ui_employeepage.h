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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_employeePage
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *contentArea;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLineEdit *searchEmployeeInput;
    QPushButton *searchButton;
    QPushButton *filterButton;
    QPushButton *exportListButton;
    QTableWidget *employeeTableWidget;
    QPushButton *nextPageTable;
    QPushButton *prevPageTable;
    QPushButton *refreshButton;
    QGroupBox *filterGroupBox;
    QPushButton *applyFilter;
    QComboBox *searchCriteriaBox;
    QLabel *label;
    QLabel *label_2;
    QComboBox *sortCriteriaBox_2;
    QPushButton *cancelFilter;
    QComboBox *depFilterBox;
    QWidget *tab_2;
    QLineEdit *firstName;
    QLineEdit *lastName;
    QLineEdit *adress;
    QLineEdit *numTlf;
    QComboBox *department;
    QLineEdit *poste;
    QPushButton *addEmployeeButton;
    QLabel *fNameErrorMSG;
    QLabel *lNameErrorMSG;
    QLabel *adressErrorMSG;
    QLabel *phoneNumErrorMSG;
    QLabel *positionErrorMSG;
    QLabel *depErrorMSG;
    QWidget *tab_3;
    QWidget *chartContainer;
    QLabel *totalCountLabel;
    QLabel *hrCountLabel;
    QLabel *leagueCountLabel;
    QLabel *commerceCountLabel;
    QLabel *municipalityCountLabel;
    QLabel *federationCountLabel;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QWidget *sidebar;
    QPushButton *exitButton;
    QPushButton *homeButton;
    QPushButton *aboutButton;
    QPushButton *notifButton;

    void setupUi(QWidget *employeePage)
    {
        if (employeePage->objectName().isEmpty())
            employeePage->setObjectName("employeePage");
        employeePage->resize(1050, 681);
        horizontalLayout = new QHBoxLayout(employeePage);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        contentArea = new QWidget(employeePage);
        contentArea->setObjectName("contentArea");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(contentArea->sizePolicy().hasHeightForWidth());
        contentArea->setSizePolicy(sizePolicy);
        contentArea->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, \n"
"                                x1:0, y1:0, x2:0, y2:1, \n"
"                                stop:0 rgba(6, 6, 6, 255), \n"
"                                stop:0.41 rgba(56, 50, 52, 255), \n"
"                                stop:1 rgba(34, 33, 33, 255));;\n"
""));
        tabWidget = new QTabWidget(contentArea);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(120, 0, 941, 681));
        QFont font;
        font.setBold(true);
        tabWidget->setFont(font);
        tabWidget->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        tabWidget->setStyleSheet(QString::fromUtf8("QTabBar::tab {\n"
"    background: qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));;  ;  \n"
"    color: white;\n"
"    border: 2px solid black;\n"
"    padding: 10px;\n"
"	width: 263%\n"
"	\n"
"   \n"
"}\n"
"\n"
"\n"
"QTabBar::tab:selected {\n"
"    background:qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(0, 213, 246, 255), \n"
"                            stop:0.18 rgba(100, 100, 138, 255), \n"
"                            stop:1 rgba(0, 212, 255, 255));;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QTabBar::tab:hover {\n"
"    background: lightblue;\n"
"    color: black;\n"
"}\n"
"\n"
""));
        tab = new QWidget();
        tab->setObjectName("tab");
        searchEmployeeInput = new QLineEdit(tab);
        searchEmployeeInput->setObjectName("searchEmployeeInput");
        searchEmployeeInput->setGeometry(QRect(120, 70, 181, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        searchEmployeeInput->setFont(font1);
        searchEmployeeInput->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: white;\n"
"    border: 2px solid qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, \n"
"                                stop: 0 rgba(255, 255, 255, 255), \n"
"                                stop: 1 rgba(240, 240, 240, 255));;\n"
"    border-radius: 8px;\n"
"    padding: 5px;\n"
"    color: black;\n"
"    font-size: 16px;\n"
"}\n"
"\n"
"/* Hover effect */\n"
"QLineEdit:hover {\n"
"    border-color: #ff3347;\n"
"}\n"
"\n"
"/* Focus effect */\n"
"QLineEdit:focus {\n"
"    border-color: #ff0004;\n"
"    box-shadow: none; /* Qt stylesheets do not support box-shadow */\n"
"}\n"
""));
        searchButton = new QPushButton(tab);
        searchButton->setObjectName("searchButton");
        searchButton->setGeometry(QRect(320, 70, 41, 31));
        searchButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        searchButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color:qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));;  ;  \n"
"\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: qlineargradient(x1: 0.25, y1: 0, x2: 0.75, y2: 1, \n"
"                            stop: 0 rgba(0, 255, 254, 255),     \n"
"                            stop: 0.26 rgba(38, 170, 196, 255), \n"
"                            stop: 0.67 rgba(89, 85, 131, 255),\n"
"                            stop: 1 rgba(0, 238, 255, 255));  ; \n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/textures/textures/searchIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        searchButton->setIcon(icon);
        filterButton = new QPushButton(tab);
        filterButton->setObjectName("filterButton");
        filterButton->setGeometry(QRect(380, 70, 41, 31));
        filterButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        filterButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color:qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));;  ;  \n"
"\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: qlineargradient(x1: 0.25, y1: 0, x2: 0.75, y2: 1, \n"
"                            stop: 0 rgba(0, 255, 254, 255),     \n"
"                            stop: 0.26 rgba(38, 170, 196, 255), \n"
"                            stop: 0.67 rgba(89, 85, 131, 255),\n"
"                            stop: 1 rgba(0, 238, 255, 255));  ; \n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/textures/textures/filterIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        filterButton->setIcon(icon1);
        exportListButton = new QPushButton(tab);
        exportListButton->setObjectName("exportListButton");
        exportListButton->setGeometry(QRect(130, 570, 191, 41));
        QFont font2;
        font2.setPointSize(18);
        exportListButton->setFont(font2);
        exportListButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        exportListButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/textures/textures/exportIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        exportListButton->setIcon(icon2);
        exportListButton->setIconSize(QSize(40, 50));
        employeeTableWidget = new QTableWidget(tab);
        if (employeeTableWidget->columnCount() < 5)
            employeeTableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        employeeTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        employeeTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        employeeTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        employeeTableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        employeeTableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        employeeTableWidget->setObjectName("employeeTableWidget");
        employeeTableWidget->setGeometry(QRect(120, 110, 701, 451));
        employeeTableWidget->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CursorShape::CrossCursor)));
        employeeTableWidget->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"    background-color: #ecf0f1;\n"
"    border: 4px solid #2980b9; \n"
"    border-radius: 10px;\n"
"    gridline-color: #bdc3c7;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QTableWidget::item {\n"
"    padding: 10px;\n"
"    border-bottom: 1px solid #bdc3c7;\n"
"	color:black;\n"
"}\n"
"\n"
"QTableWidget::item:selected {\n"
"    background-color: #3498db;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QTableWidget::item:hover {\n"
"    background-color: #f1c40f;\n"
"    color: black;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #2980b9; /* Blue header */\n"
"    color: white;\n"
"    padding: 5px 5px; /* Increase horizontal padding */\n"
"    font-size: 15px;\n"
"    font-weight: bold;\n"
"    border: 1px solid #1c5986;\n"
"    min-width: 120px; /* Minimum width for each column */\n"
"}\n"
"\n"
"QTableCornerButton::section {\n"
"    background-color: #2980b9;\n"
"    border: 1px solid #1c5986;\n"
"}\n"
"\n"
"QTableWidget QWidget {\n"
"background:transparent;\n"
""
                        "\n"
"	}\n"
"QTableWidget QPushButton {\n"
"    background-color: qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));  \n"
"    border-radius: 10px;\n"
"    color: white;\n"
"    font-size: 12px;\n"
"min-width: 100px;  /* Ensure a minimum width */\n"
"    min-height: 40px;  /* Ensure a minimum height */\n"
"}\n"
"\n"
"QTableWidget QPushButton:hover {\n"
"    background-color: qlineargradient(x1: 0.25, y1: 0, x2: 0.75, y2: 1, \n"
"                            stop: 0 rgba(0, 255, 254, 255),     \n"
"                            stop: 0.26 rgba(38, 170, 196, 255), \n"
"                            stop: 0.67 rgba(89, 85, 131, 255),\n"
"                            stop: 1 rgba(0, 238, 255, 255));  \n"
"}\n"
"\n"
""));
        employeeTableWidget->horizontalHeader()->setStretchLastSection(true);
        nextPageTable = new QPushButton(tab);
        nextPageTable->setObjectName("nextPageTable");
        nextPageTable->setGeometry(QRect(740, 570, 31, 24));
        nextPageTable->setStyleSheet(QString::fromUtf8("QPushButton {background-color:qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));;  ;  \n"
"}\n"
"QPushButton:hover{\n"
"	background-color:qlineargradient(x1: 0.25, y1: 0, x2: 0.75, y2: 1, \n"
"                            stop: 0 rgba(0, 255, 254, 255),     \n"
"                            stop: 0.26 rgba(38, 170, 196, 255), \n"
"                            stop: 0.67 rgba(89, 85, 131, 255),\n"
"                            stop: 1 rgba(0, 238, 255, 255));  \n"
"\n"
"\n"
"\n"
"}\n"
"\n"
"\n"
""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/textures/textures/prevIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        nextPageTable->setIcon(icon3);
        prevPageTable = new QPushButton(tab);
        prevPageTable->setObjectName("prevPageTable");
        prevPageTable->setGeometry(QRect(780, 569, 31, 24));
        prevPageTable->setStyleSheet(QString::fromUtf8("QPushButton {background-color:qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));;  ;  \n"
"}\n"
"QPushButton:hover{\n"
"	background-color:qlineargradient(x1: 0.25, y1: 0, x2: 0.75, y2: 1, \n"
"                            stop: 0 rgba(0, 255, 254, 255),     \n"
"                            stop: 0.26 rgba(38, 170, 196, 255), \n"
"                            stop: 0.67 rgba(89, 85, 131, 255),\n"
"                            stop: 1 rgba(0, 238, 255, 255));  \n"
"\n"
"\n"
"\n"
"}\n"
"\n"
"\n"
""));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/textures/textures/nextIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        prevPageTable->setIcon(icon4);
        refreshButton = new QPushButton(tab);
        refreshButton->setObjectName("refreshButton");
        refreshButton->setGeometry(QRect(770, 70, 41, 31));
        refreshButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        refreshButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color:qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));;  ;  \n"
"\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: qlineargradient(x1: 0.25, y1: 0, x2: 0.75, y2: 1, \n"
"                            stop: 0 rgba(0, 255, 254, 255),     \n"
"                            stop: 0.26 rgba(38, 170, 196, 255), \n"
"                            stop: 0.67 rgba(89, 85, 131, 255),\n"
"                            stop: 1 rgba(0, 238, 255, 255));  ; \n"
"}"));
        QIcon icon5(QIcon::fromTheme(QIcon::ThemeIcon::ViewRefresh));
        refreshButton->setIcon(icon5);
        filterGroupBox = new QGroupBox(tab);
        filterGroupBox->setObjectName("filterGroupBox");
        filterGroupBox->setGeometry(QRect(120, 110, 701, 451));
        filterGroupBox->setStyleSheet(QString::fromUtf8(""));
        applyFilter = new QPushButton(filterGroupBox);
        applyFilter->setObjectName("applyFilter");
        applyFilter->setGeometry(QRect(470, 390, 101, 41));
        applyFilter->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        searchCriteriaBox = new QComboBox(filterGroupBox);
        searchCriteriaBox->addItem(QString());
        searchCriteriaBox->addItem(QString());
        searchCriteriaBox->addItem(QString());
        searchCriteriaBox->addItem(QString());
        searchCriteriaBox->addItem(QString());
        searchCriteriaBox->addItem(QString());
        searchCriteriaBox->setObjectName("searchCriteriaBox");
        searchCriteriaBox->setGeometry(QRect(220, 70, 201, 31));
        searchCriteriaBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
        label = new QLabel(filterGroupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 70, 231, 31));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Azonix")});
        font3.setPointSize(16);
        label->setFont(font3);
        label->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"color :     qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));;  ;  "));
        label_2 = new QLabel(filterGroupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 200, 171, 31));
        label_2->setFont(font3);
        label_2->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"color :     qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));;  ;  "));
        sortCriteriaBox_2 = new QComboBox(filterGroupBox);
        sortCriteriaBox_2->addItem(QString());
        sortCriteriaBox_2->addItem(QString());
        sortCriteriaBox_2->setObjectName("sortCriteriaBox_2");
        sortCriteriaBox_2->setGeometry(QRect(220, 200, 201, 31));
        sortCriteriaBox_2->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
        cancelFilter = new QPushButton(filterGroupBox);
        cancelFilter->setObjectName("cancelFilter");
        cancelFilter->setGeometry(QRect(580, 390, 101, 41));
        cancelFilter->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        depFilterBox = new QComboBox(filterGroupBox);
        depFilterBox->addItem(QString());
        depFilterBox->addItem(QString());
        depFilterBox->addItem(QString());
        depFilterBox->addItem(QString());
        depFilterBox->addItem(QString());
        depFilterBox->setObjectName("depFilterBox");
        depFilterBox->setGeometry(QRect(480, 70, 201, 31));
        depFilterBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        firstName = new QLineEdit(tab_2);
        firstName->setObjectName("firstName");
        firstName->setGeometry(QRect(80, 70, 301, 31));
        firstName->setFont(font1);
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
        lastName = new QLineEdit(tab_2);
        lastName->setObjectName("lastName");
        lastName->setGeometry(QRect(80, 122, 301, 31));
        lastName->setFont(font1);
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
        adress = new QLineEdit(tab_2);
        adress->setObjectName("adress");
        adress->setGeometry(QRect(80, 183, 301, 31));
        adress->setFont(font1);
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
"}\n"
""));
        numTlf = new QLineEdit(tab_2);
        numTlf->setObjectName("numTlf");
        numTlf->setGeometry(QRect(80, 248, 301, 31));
        numTlf->setFont(font1);
        numTlf->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        department = new QComboBox(tab_2);
        department->addItem(QString());
        department->addItem(QString());
        department->addItem(QString());
        department->addItem(QString());
        department->addItem(QString());
        department->addItem(QString());
        department->setObjectName("department");
        department->setGeometry(QRect(79, 376, 301, 31));
        department->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
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
        poste = new QLineEdit(tab_2);
        poste->setObjectName("poste");
        poste->setGeometry(QRect(80, 310, 301, 31));
        poste->setFont(font1);
        poste->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        addEmployeeButton = new QPushButton(tab_2);
        addEmployeeButton->setObjectName("addEmployeeButton");
        addEmployeeButton->setGeometry(QRect(350, 520, 221, 61));
        addEmployeeButton->setFont(font2);
        addEmployeeButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        addEmployeeButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/textures/textures/addIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        addEmployeeButton->setIcon(icon6);
        addEmployeeButton->setIconSize(QSize(50, 50));
        fNameErrorMSG = new QLabel(tab_2);
        fNameErrorMSG->setObjectName("fNameErrorMSG");
        fNameErrorMSG->setGeometry(QRect(395, 68, 291, 31));
        fNameErrorMSG->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"color:red;\n"
""));
        lNameErrorMSG = new QLabel(tab_2);
        lNameErrorMSG->setObjectName("lNameErrorMSG");
        lNameErrorMSG->setGeometry(QRect(400, 120, 291, 31));
        lNameErrorMSG->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"color:red;\n"
""));
        adressErrorMSG = new QLabel(tab_2);
        adressErrorMSG->setObjectName("adressErrorMSG");
        adressErrorMSG->setGeometry(QRect(400, 180, 291, 31));
        adressErrorMSG->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"color:red;\n"
""));
        phoneNumErrorMSG = new QLabel(tab_2);
        phoneNumErrorMSG->setObjectName("phoneNumErrorMSG");
        phoneNumErrorMSG->setGeometry(QRect(400, 250, 291, 31));
        phoneNumErrorMSG->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"color:red;\n"
""));
        positionErrorMSG = new QLabel(tab_2);
        positionErrorMSG->setObjectName("positionErrorMSG");
        positionErrorMSG->setGeometry(QRect(400, 310, 291, 31));
        positionErrorMSG->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"color:red;\n"
""));
        depErrorMSG = new QLabel(tab_2);
        depErrorMSG->setObjectName("depErrorMSG");
        depErrorMSG->setGeometry(QRect(390, 380, 291, 31));
        depErrorMSG->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"color:red;\n"
""));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        chartContainer = new QWidget(tab_3);
        chartContainer->setObjectName("chartContainer");
        chartContainer->setGeometry(QRect(10, 0, 400, 300));
        totalCountLabel = new QLabel(tab_3);
        totalCountLabel->setObjectName("totalCountLabel");
        totalCountLabel->setGeometry(QRect(790, 17, 31, 41));
        QFont font4;
        font4.setPointSize(20);
        totalCountLabel->setFont(font4);
        totalCountLabel->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: qlineargradient(spread: pad, \n"
"                        x1: 0, y1: 0, x2: 1, y2: 1, \n"
"                        stop: 0 rgba(0, 255, 0, 255), \n"
"                        stop: 0.5 rgba(0, 204, 0, 255), \n"
"                        stop: 1 rgba(0, 128, 0, 255));\n"
""));
        hrCountLabel = new QLabel(tab_3);
        hrCountLabel->setObjectName("hrCountLabel");
        hrCountLabel->setGeometry(QRect(680, 120, 41, 31));
        QFont font5;
        font5.setPointSize(16);
        hrCountLabel->setFont(font5);
        hrCountLabel->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: qlineargradient(spread: pad, \n"
"                        x1: 0, y1: 0, x2: 1, y2: 1, \n"
"                        stop: 0 rgba(0, 0, 255, 255), \n"
"                        stop: 0.5 rgba(0, 128, 255, 255), \n"
"                        stop: 1 rgba(0, 191, 255, 255));\n"
""));
        leagueCountLabel = new QLabel(tab_3);
        leagueCountLabel->setObjectName("leagueCountLabel");
        leagueCountLabel->setGeometry(QRect(680, 70, 41, 31));
        leagueCountLabel->setFont(font5);
        leagueCountLabel->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: qlineargradient(spread: pad, \n"
"                        x1: 0, y1: 0, x2: 1, y2: 1, \n"
"                        stop: 0 rgba(0, 0, 255, 255), \n"
"                        stop: 0.5 rgba(0, 128, 255, 255), \n"
"                        stop: 1 rgba(0, 191, 255, 255));\n"
""));
        commerceCountLabel = new QLabel(tab_3);
        commerceCountLabel->setObjectName("commerceCountLabel");
        commerceCountLabel->setGeometry(QRect(680, 170, 41, 31));
        commerceCountLabel->setFont(font5);
        commerceCountLabel->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: qlineargradient(spread: pad, \n"
"                        x1: 0, y1: 0, x2: 1, y2: 1, \n"
"                        stop: 0 rgba(0, 0, 255, 255), \n"
"                        stop: 0.5 rgba(0, 128, 255, 255), \n"
"                        stop: 1 rgba(0, 191, 255, 255));\n"
""));
        municipalityCountLabel = new QLabel(tab_3);
        municipalityCountLabel->setObjectName("municipalityCountLabel");
        municipalityCountLabel->setGeometry(QRect(680, 220, 41, 31));
        municipalityCountLabel->setFont(font5);
        municipalityCountLabel->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: qlineargradient(spread: pad, \n"
"                        x1: 0, y1: 0, x2: 1, y2: 1, \n"
"                        stop: 0 rgba(0, 0, 255, 255), \n"
"                        stop: 0.5 rgba(0, 128, 255, 255), \n"
"                        stop: 1 rgba(0, 191, 255, 255));\n"
""));
        federationCountLabel = new QLabel(tab_3);
        federationCountLabel->setObjectName("federationCountLabel");
        federationCountLabel->setGeometry(QRect(680, 280, 41, 31));
        federationCountLabel->setFont(font5);
        federationCountLabel->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: qlineargradient(spread: pad, \n"
"                        x1: 0, y1: 0, x2: 1, y2: 1, \n"
"                        stop: 0 rgba(0, 0, 255, 255), \n"
"                        stop: 0.5 rgba(0, 128, 255, 255), \n"
"                        stop: 1 rgba(0, 191, 255, 255));\n"
""));
        label_3 = new QLabel(tab_3);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(420, 10, 351, 51));
        label_3->setFont(font4);
        label_3->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"color :     qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));;  ;  "));
        label_4 = new QLabel(tab_3);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(440, 60, 211, 41));
        label_4->setFont(font5);
        label_4->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"color :     qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));;  ;  "));
        label_5 = new QLabel(tab_3);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(440, 110, 141, 41));
        QFont font6;
        font6.setPointSize(14);
        label_5->setFont(font6);
        label_5->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"color :     qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));;  ;  "));
        label_6 = new QLabel(tab_3);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(440, 170, 221, 31));
        label_6->setFont(font6);
        label_6->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"color :     qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));;  ;  "));
        label_7 = new QLabel(tab_3);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(440, 217, 221, 41));
        label_7->setFont(font6);
        label_7->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"color :     qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));;  ;  "));
        label_8 = new QLabel(tab_3);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(440, 277, 211, 41));
        label_8->setFont(font6);
        label_8->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"color :     qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));;  ;  "));
        tabWidget->addTab(tab_3, QString());
        sidebar = new QWidget(contentArea);
        sidebar->setObjectName("sidebar");
        sidebar->setGeometry(QRect(-30, 0, 151, 311));
        sidebar->setStyleSheet(QString::fromUtf8("background:gray;"));
        exitButton = new QPushButton(sidebar);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(53, 240, 71, 71));
        exitButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        exitButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border:none;\n"
"\n"
"\n"
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: red;\n"
"	border-radius:15px;\n"
"}"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/textures/textures/exitIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        exitButton->setIcon(icon7);
        exitButton->setIconSize(QSize(50, 50));
        homeButton = new QPushButton(sidebar);
        homeButton->setObjectName("homeButton");
        homeButton->setGeometry(QRect(50, 10, 75, 61));
        homeButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        homeButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border:none;\n"
"\n"
"\n"
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: white;\n"
"	border-radius:15px;\n"
"}"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/textures/textures/homeIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        homeButton->setIcon(icon8);
        homeButton->setIconSize(QSize(50, 50));
        aboutButton = new QPushButton(sidebar);
        aboutButton->setObjectName("aboutButton");
        aboutButton->setGeometry(QRect(50, 170, 71, 61));
        aboutButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        aboutButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border:none;\n"
"\n"
"\n"
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: lime;\n"
"	border-radius:15px;\n"
"}"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/textures/textures/aboutIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        aboutButton->setIcon(icon9);
        aboutButton->setIconSize(QSize(50, 50));
        notifButton = new QPushButton(sidebar);
        notifButton->setObjectName("notifButton");
        notifButton->setGeometry(QRect(50, 90, 75, 71));
        notifButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        notifButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border:none;\n"
"\n"
"\n"
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: yellow;\n"
"    box-shadow: 0px 0px 10px rgba(255, 0, 0, 0.5);\n"
"	border-radius:15px;\n"
"}"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/textures/textures/notifsIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        notifButton->setIcon(icon10);
        notifButton->setIconSize(QSize(50, 50));
        notifButton->raise();
        homeButton->raise();
        aboutButton->raise();
        exitButton->raise();

        horizontalLayout->addWidget(contentArea);


        retranslateUi(employeePage);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(employeePage);
    } // setupUi

    void retranslateUi(QWidget *employeePage)
    {
        employeePage->setWindowTitle(QCoreApplication::translate("employeePage", "Form", nullptr));
        searchEmployeeInput->setPlaceholderText(QCoreApplication::translate("employeePage", "Search Employee", nullptr));
        searchButton->setText(QString());
        filterButton->setText(QString());
        exportListButton->setText(QCoreApplication::translate("employeePage", "Export List", nullptr));
        QTableWidgetItem *___qtablewidgetitem = employeeTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("employeePage", "USER ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = employeeTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("employeePage", "F Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = employeeTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("employeePage", "L Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = employeeTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("employeePage", "Department", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = employeeTableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("employeePage", "Actions", nullptr));
        nextPageTable->setText(QString());
        prevPageTable->setText(QString());
        refreshButton->setText(QString());
        filterGroupBox->setTitle(QCoreApplication::translate("employeePage", "Search and Sort settings", nullptr));
        applyFilter->setText(QCoreApplication::translate("employeePage", "Apply Filter", nullptr));
        searchCriteriaBox->setItemText(0, QCoreApplication::translate("employeePage", "Firstname", nullptr));
        searchCriteriaBox->setItemText(1, QCoreApplication::translate("employeePage", "Lastname", nullptr));
        searchCriteriaBox->setItemText(2, QCoreApplication::translate("employeePage", "Position", nullptr));
        searchCriteriaBox->setItemText(3, QCoreApplication::translate("employeePage", "Department", nullptr));
        searchCriteriaBox->setItemText(4, QCoreApplication::translate("employeePage", "Adress", nullptr));
        searchCriteriaBox->setItemText(5, QCoreApplication::translate("employeePage", "Default", nullptr));

        searchCriteriaBox->setPlaceholderText(QCoreApplication::translate("employeePage", "Choice", nullptr));
        label->setText(QCoreApplication::translate("employeePage", "Search By :", nullptr));
        label_2->setText(QCoreApplication::translate("employeePage", "Sort :", nullptr));
        sortCriteriaBox_2->setItemText(0, QCoreApplication::translate("employeePage", "Ascending", nullptr));
        sortCriteriaBox_2->setItemText(1, QCoreApplication::translate("employeePage", "Descending", nullptr));

        sortCriteriaBox_2->setPlaceholderText(QCoreApplication::translate("employeePage", "Choice", nullptr));
        cancelFilter->setText(QCoreApplication::translate("employeePage", "Cancel", nullptr));
        depFilterBox->setItemText(0, QCoreApplication::translate("employeePage", "HR", nullptr));
        depFilterBox->setItemText(1, QCoreApplication::translate("employeePage", "League", nullptr));
        depFilterBox->setItemText(2, QCoreApplication::translate("employeePage", "Commerce", nullptr));
        depFilterBox->setItemText(3, QCoreApplication::translate("employeePage", "Municipality", nullptr));
        depFilterBox->setItemText(4, QCoreApplication::translate("employeePage", "Federation", nullptr));

        depFilterBox->setPlaceholderText(QCoreApplication::translate("employeePage", "Department", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("employeePage", "Employee List", nullptr));
        firstName->setText(QString());
        firstName->setPlaceholderText(QCoreApplication::translate("employeePage", "First Name", nullptr));
        lastName->setPlaceholderText(QCoreApplication::translate("employeePage", "Last Name", nullptr));
        adress->setPlaceholderText(QCoreApplication::translate("employeePage", "Address", nullptr));
        numTlf->setPlaceholderText(QCoreApplication::translate("employeePage", "Phone Number", nullptr));
        department->setItemText(0, QCoreApplication::translate("employeePage", "HR", nullptr));
        department->setItemText(1, QCoreApplication::translate("employeePage", "League", nullptr));
        department->setItemText(2, QCoreApplication::translate("employeePage", "Commerce", nullptr));
        department->setItemText(3, QCoreApplication::translate("employeePage", "Federation", nullptr));
        department->setItemText(4, QCoreApplication::translate("employeePage", "Municipality", nullptr));
        department->setItemText(5, QString());

        department->setPlaceholderText(QCoreApplication::translate("employeePage", "Select Department", nullptr));
        poste->setPlaceholderText(QCoreApplication::translate("employeePage", "Position", nullptr));
        addEmployeeButton->setText(QCoreApplication::translate("employeePage", "Add Employee", nullptr));
        fNameErrorMSG->setText(QString());
        lNameErrorMSG->setText(QString());
        adressErrorMSG->setText(QString());
        phoneNumErrorMSG->setText(QString());
        positionErrorMSG->setText(QString());
        depErrorMSG->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("employeePage", "Add Employe", nullptr));
        totalCountLabel->setText(QCoreApplication::translate("employeePage", "0", nullptr));
        hrCountLabel->setText(QCoreApplication::translate("employeePage", "0", nullptr));
        leagueCountLabel->setText(QCoreApplication::translate("employeePage", "0", nullptr));
        commerceCountLabel->setText(QCoreApplication::translate("employeePage", "0", nullptr));
        municipalityCountLabel->setText(QCoreApplication::translate("employeePage", "0", nullptr));
        federationCountLabel->setText(QCoreApplication::translate("employeePage", "0", nullptr));
        label_3->setText(QCoreApplication::translate("employeePage", "Total Number of Employees :", nullptr));
        label_4->setText(QCoreApplication::translate("employeePage", "League Department :", nullptr));
        label_5->setText(QCoreApplication::translate("employeePage", "HR Department :", nullptr));
        label_6->setText(QCoreApplication::translate("employeePage", "Commerce  Department :", nullptr));
        label_7->setText(QCoreApplication::translate("employeePage", "Municipality Department :", nullptr));
        label_8->setText(QCoreApplication::translate("employeePage", "Federation  Department :", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("employeePage", "Statistics", nullptr));
        exitButton->setText(QString());
        homeButton->setText(QString());
        aboutButton->setText(QString());
        notifButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class employeePage: public Ui_employeePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYEEPAGE_H
