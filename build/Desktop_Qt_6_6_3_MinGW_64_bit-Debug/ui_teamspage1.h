/********************************************************************************
** Form generated from reading UI file 'teamspage1.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEAMSPAGE1_H
#define UI_TEAMSPAGE1_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_teamsPage
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *contentArea;
    QTabWidget *tabWidgetTeams;
    QWidget *tab;
    QLineEdit *searchTeamsInput;
    QPushButton *searchButton;
    QPushButton *exportListButton;
    QPushButton *nextPageTable;
    QPushButton *prevPageTable;
    QTableWidget *listTeams;
    QPushButton *refreshButton;
    QComboBox *filtreTeams;
    QWidget *tab_2;
    QPushButton *addTeamsButton;
    QLineEdit *teamsName;
    QLineEdit *teamsNationality;
    QSpinBox *teamsMP;
    QSpinBox *teamsNbf;
    QLineEdit *teamsKit;
    QLineEdit *teamsLogo;
    QLabel *label;
    QLabel *label_2;
    QLabel *errerName;
    QLabel *errerCountry;
    QLabel *errerLogo;
    QLabel *errerKit;
    QPushButton *addLogoButton;
    QPushButton *addKitButton;
    QWidget *Stats;
    QWidget *chartContainer;
    QWidget *sidebar;
    QPushButton *exitButton;
    QPushButton *homeButton;
    QPushButton *aboutButton;
    QPushButton *notifButton;

    void setupUi(QWidget *teamsPage)
    {
        if (teamsPage->objectName().isEmpty())
            teamsPage->setObjectName("teamsPage");
        teamsPage->resize(1050, 681);
        horizontalLayout = new QHBoxLayout(teamsPage);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        contentArea = new QWidget(teamsPage);
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
        tabWidgetTeams = new QTabWidget(contentArea);
        tabWidgetTeams->setObjectName("tabWidgetTeams");
        tabWidgetTeams->setGeometry(QRect(120, 0, 941, 681));
        QFont font;
        font.setBold(true);
        tabWidgetTeams->setFont(font);
        tabWidgetTeams->setCursor(QCursor(Qt::PointingHandCursor));
        tabWidgetTeams->setStyleSheet(QString::fromUtf8("QTabBar::tab {\n"
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
        searchTeamsInput = new QLineEdit(tab);
        searchTeamsInput->setObjectName("searchTeamsInput");
        searchTeamsInput->setGeometry(QRect(120, 70, 191, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        searchTeamsInput->setFont(font1);
        searchTeamsInput->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        searchButton->setCursor(QCursor(Qt::PointingHandCursor));
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
        icon.addFile(QString::fromUtf8("textures/searchIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        searchButton->setIcon(icon);
        exportListButton = new QPushButton(tab);
        exportListButton->setObjectName("exportListButton");
        exportListButton->setGeometry(QRect(130, 570, 191, 41));
        QFont font2;
        font2.setPointSize(18);
        exportListButton->setFont(font2);
        exportListButton->setCursor(QCursor(Qt::PointingHandCursor));
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
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("textures/exportIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        exportListButton->setIcon(icon1);
        exportListButton->setIconSize(QSize(40, 50));
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
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("textures/prevIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        nextPageTable->setIcon(icon2);
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
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("textures/nextIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        prevPageTable->setIcon(icon3);
        listTeams = new QTableWidget(tab);
        if (listTeams->columnCount() < 8)
            listTeams->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        listTeams->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        listTeams->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        listTeams->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        listTeams->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        listTeams->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        listTeams->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        listTeams->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        listTeams->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        listTeams->setObjectName("listTeams");
        listTeams->setGeometry(QRect(10, 140, 911, 401));
        listTeams->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
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
""));
        listTeams->horizontalHeader()->setStretchLastSection(true);
        refreshButton = new QPushButton(tab);
        refreshButton->setObjectName("refreshButton");
        refreshButton->setGeometry(QRect(830, 90, 51, 41));
        refreshButton->setCursor(QCursor(Qt::PointingHandCursor));
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
        QIcon icon4(QIcon::fromTheme(QString::fromUtf8("QIcon::ThemeIcon::ViewRefresh")));
        refreshButton->setIcon(icon4);
        filtreTeams = new QComboBox(tab);
        filtreTeams->addItem(QString());
        filtreTeams->addItem(QString());
        filtreTeams->addItem(QString());
        filtreTeams->addItem(QString());
        filtreTeams->addItem(QString());
        filtreTeams->addItem(QString());
        filtreTeams->addItem(QString());
        filtreTeams->addItem(QString());
        filtreTeams->setObjectName("filtreTeams");
        filtreTeams->setGeometry(QRect(470, 67, 201, 31));
        tabWidgetTeams->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        addTeamsButton = new QPushButton(tab_2);
        addTeamsButton->setObjectName("addTeamsButton");
        addTeamsButton->setGeometry(QRect(320, 490, 221, 61));
        addTeamsButton->setFont(font2);
        addTeamsButton->setCursor(QCursor(Qt::PointingHandCursor));
        addTeamsButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("textures/addIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        addTeamsButton->setIcon(icon5);
        addTeamsButton->setIconSize(QSize(50, 50));
        teamsName = new QLineEdit(tab_2);
        teamsName->setObjectName("teamsName");
        teamsName->setGeometry(QRect(80, 90, 301, 31));
        teamsName->setFont(font1);
        teamsName->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: white;\n"
"    border: 2px solid #C51D34;\n"
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
        teamsNationality = new QLineEdit(tab_2);
        teamsNationality->setObjectName("teamsNationality");
        teamsNationality->setGeometry(QRect(500, 90, 321, 31));
        teamsNationality->setFont(font1);
        teamsNationality->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: white;\n"
"    border: 2px solid #C51D34;\n"
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
        teamsMP = new QSpinBox(tab_2);
        teamsMP->setObjectName("teamsMP");
        teamsMP->setGeometry(QRect(500, 260, 321, 31));
        teamsMP->setStyleSheet(QString::fromUtf8("QSpinBox {\n"
"    background-color: white;\n"
"    border: 2px solid #C51D34;\n"
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
"QSpinBox:focus {\n"
"    border-color: #ff0004;\n"
"    box-shadow: none; /* Qt stylesheets do not support box-shadow */\n"
"}"));
        teamsNbf = new QSpinBox(tab_2);
        teamsNbf->setObjectName("teamsNbf");
        teamsNbf->setGeometry(QRect(90, 261, 321, 31));
        teamsNbf->setStyleSheet(QString::fromUtf8("QSpinBox {\n"
"    background-color: white;\n"
"    border: 2px solid #C51D34;\n"
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
"QSpinBox:focus {\n"
"    border-color: #ff0004;\n"
"    box-shadow: none; /* Qt stylesheets do not support box-shadow */\n"
"}"));
        teamsKit = new QLineEdit(tab_2);
        teamsKit->setObjectName("teamsKit");
        teamsKit->setGeometry(QRect(500, 390, 321, 31));
        teamsKit->setFont(font1);
        teamsKit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: white;\n"
"    border: 2px solid #C51D34;\n"
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
        teamsLogo = new QLineEdit(tab_2);
        teamsLogo->setObjectName("teamsLogo");
        teamsLogo->setGeometry(QRect(90, 390, 321, 31));
        teamsLogo->setFont(font1);
        teamsLogo->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: white;\n"
"    border: 2px solid #C51D34;\n"
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
        label = new QLabel(tab_2);
        label->setObjectName("label");
        label->setGeometry(QRect(110, 180, 271, 51));
        label->setStyleSheet(QString::fromUtf8("background:transparent;"));
        label_2 = new QLabel(tab_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(510, 180, 281, 51));
        label_2->setStyleSheet(QString::fromUtf8("background:transparent;"));
        errerName = new QLabel(tab_2);
        errerName->setObjectName("errerName");
        errerName->setGeometry(QRect(90, 130, 281, 31));
        errerName->setStyleSheet(QString::fromUtf8("color :red;\n"
""));
        errerCountry = new QLabel(tab_2);
        errerCountry->setObjectName("errerCountry");
        errerCountry->setGeometry(QRect(510, 130, 301, 31));
        errerCountry->setStyleSheet(QString::fromUtf8("color:red;"));
        errerLogo = new QLabel(tab_2);
        errerLogo->setObjectName("errerLogo");
        errerLogo->setGeometry(QRect(90, 440, 301, 31));
        errerKit = new QLabel(tab_2);
        errerKit->setObjectName("errerKit");
        errerKit->setGeometry(QRect(500, 440, 301, 31));
        addLogoButton = new QPushButton(tab_2);
        addLogoButton->setObjectName("addLogoButton");
        addLogoButton->setGeometry(QRect(140, 320, 221, 61));
        addLogoButton->setFont(font2);
        addLogoButton->setCursor(QCursor(Qt::PointingHandCursor));
        addLogoButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        addLogoButton->setIcon(icon5);
        addLogoButton->setIconSize(QSize(50, 50));
        addKitButton = new QPushButton(tab_2);
        addKitButton->setObjectName("addKitButton");
        addKitButton->setGeometry(QRect(520, 320, 221, 61));
        addKitButton->setFont(font2);
        addKitButton->setCursor(QCursor(Qt::PointingHandCursor));
        addKitButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        addKitButton->setIcon(icon5);
        addKitButton->setIconSize(QSize(50, 50));
        tabWidgetTeams->addTab(tab_2, QString());
        Stats = new QWidget();
        Stats->setObjectName("Stats");
        chartContainer = new QWidget(Stats);
        chartContainer->setObjectName("chartContainer");
        chartContainer->setGeometry(QRect(20, 20, 891, 611));
        tabWidgetTeams->addTab(Stats, QString());
        sidebar = new QWidget(contentArea);
        sidebar->setObjectName("sidebar");
        sidebar->setGeometry(QRect(-30, 0, 151, 311));
        sidebar->setStyleSheet(QString::fromUtf8("background:gray;"));
        exitButton = new QPushButton(sidebar);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(53, 240, 71, 71));
        exitButton->setCursor(QCursor(Qt::PointingHandCursor));
        exitButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border:none;\n"
"\n"
"\n"
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: red;\n"
"    box-shadow: 0px 0px 10px rgba(255, 0, 0, 0.5);\n"
"	border-radius:15px;\n"
"}"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("textures/exitIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        exitButton->setIcon(icon6);
        exitButton->setIconSize(QSize(50, 50));
        homeButton = new QPushButton(sidebar);
        homeButton->setObjectName("homeButton");
        homeButton->setGeometry(QRect(50, 10, 75, 61));
        homeButton->setCursor(QCursor(Qt::PointingHandCursor));
        homeButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border:none;\n"
"\n"
"\n"
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: white;\n"
"    box-shadow: 0px 0px 10px rgba(255, 0, 0, 0.5);\n"
"	border-radius:15px;\n"
"}"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8("textures/homeIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        homeButton->setIcon(icon7);
        homeButton->setIconSize(QSize(50, 50));
        aboutButton = new QPushButton(sidebar);
        aboutButton->setObjectName("aboutButton");
        aboutButton->setGeometry(QRect(50, 170, 71, 61));
        aboutButton->setCursor(QCursor(Qt::PointingHandCursor));
        aboutButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border:none;\n"
"\n"
"\n"
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: lime;\n"
"    box-shadow: 0px 0px 10px rgba(255, 0, 0, 0.5);\n"
"	border-radius:15px;\n"
"}"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8("textures/aboutIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        aboutButton->setIcon(icon8);
        aboutButton->setIconSize(QSize(50, 50));
        notifButton = new QPushButton(sidebar);
        notifButton->setObjectName("notifButton");
        notifButton->setGeometry(QRect(50, 90, 75, 71));
        notifButton->setCursor(QCursor(Qt::PointingHandCursor));
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
        QIcon icon9;
        icon9.addFile(QString::fromUtf8("textures/notifsIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        notifButton->setIcon(icon9);
        notifButton->setIconSize(QSize(50, 50));

        horizontalLayout->addWidget(contentArea);


        retranslateUi(teamsPage);

        tabWidgetTeams->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(teamsPage);
    } // setupUi

    void retranslateUi(QWidget *teamsPage)
    {
        teamsPage->setWindowTitle(QCoreApplication::translate("teamsPage", "Form", nullptr));
        searchTeamsInput->setPlaceholderText(QCoreApplication::translate("teamsPage", "Search Teams", nullptr));
        searchButton->setText(QString());
        exportListButton->setText(QCoreApplication::translate("teamsPage", "Export List", nullptr));
        nextPageTable->setText(QString());
        prevPageTable->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = listTeams->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("teamsPage", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = listTeams->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("teamsPage", "Team Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = listTeams->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("teamsPage", "Country", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = listTeams->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("teamsPage", "Logo", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = listTeams->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("teamsPage", "Num Fans", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = listTeams->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("teamsPage", "Kit", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = listTeams->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("teamsPage", "Matches Played", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = listTeams->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("teamsPage", "Actions", nullptr));
        refreshButton->setText(QString());
        filtreTeams->setItemText(0, QCoreApplication::translate("teamsPage", "Filter Here", nullptr));
        filtreTeams->setItemText(1, QCoreApplication::translate("teamsPage", "Trie de A-Z", nullptr));
        filtreTeams->setItemText(2, QCoreApplication::translate("teamsPage", "Trie de Z-A", nullptr));
        filtreTeams->setItemText(3, QCoreApplication::translate("teamsPage", "Trie par match croissente", nullptr));
        filtreTeams->setItemText(4, QCoreApplication::translate("teamsPage", "Trie par match decroissente", nullptr));
        filtreTeams->setItemText(5, QCoreApplication::translate("teamsPage", "Trie par Num Fans croissente", nullptr));
        filtreTeams->setItemText(6, QCoreApplication::translate("teamsPage", "Trie par Num Fans decroissente", nullptr));
        filtreTeams->setItemText(7, QCoreApplication::translate("teamsPage", "Trie par id croissate", nullptr));

        tabWidgetTeams->setTabText(tabWidgetTeams->indexOf(tab), QCoreApplication::translate("teamsPage", "Teams List", nullptr));
        addTeamsButton->setText(QCoreApplication::translate("teamsPage", "Add Team", nullptr));
        teamsName->setText(QString());
        teamsName->setPlaceholderText(QCoreApplication::translate("teamsPage", "Team Name", nullptr));
        teamsNationality->setPlaceholderText(QCoreApplication::translate("teamsPage", "Nationality", nullptr));
        teamsKit->setPlaceholderText(QCoreApplication::translate("teamsPage", "Path to the kits", nullptr));
        teamsLogo->setPlaceholderText(QCoreApplication::translate("teamsPage", "Path to the logo", nullptr));
        label->setText(QCoreApplication::translate("teamsPage", "Number Of Subcribers of the team", nullptr));
        label_2->setText(QCoreApplication::translate("teamsPage", "Number of matches palyed by the team", nullptr));
        errerName->setText(QString());
        errerCountry->setText(QString());
        errerLogo->setText(QString());
        errerKit->setText(QString());
        addLogoButton->setText(QCoreApplication::translate("teamsPage", "Add Logo", nullptr));
        addKitButton->setText(QCoreApplication::translate("teamsPage", "Add Kits", nullptr));
        tabWidgetTeams->setTabText(tabWidgetTeams->indexOf(tab_2), QCoreApplication::translate("teamsPage", "Add Teams", nullptr));
        tabWidgetTeams->setTabText(tabWidgetTeams->indexOf(Stats), QCoreApplication::translate("teamsPage", "Teams Statistics", nullptr));
        exitButton->setText(QString());
        homeButton->setText(QString());
        aboutButton->setText(QString());
        notifButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class teamsPage: public Ui_teamsPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEAMSPAGE1_H
