#include "teams.h"
#include "connection.h"
#include "qbarcategoryaxis.h"
#include "qbarseries.h"
#include "qbarset.h"
#include "qboxlayout.h"
#include "qchart.h"
#include "qchartview.h"
#include "qcontainerfwd.h"
#include "qheaderview.h"
#include "qlabel.h"
#include "qsplitter.h"
#include "qsqlerror.h"
#include "qvalueaxis.h"
#include <QSignalMapper>
#include <QFileInfo>
#include <QFileDialog>
#include <QMessageBox>

// Getters and Setters
int teams::getTeamID() const
{
    return teamID;
}

void teams::setTeamID(int newTeamID)
{
    teamID = newTeamID;
}

QString teams::getName() const
{
    return name;
}

void teams::setName(const QString &newName)
{
    name = newName;
}

QString teams::getContry() const
{
    return contry;
}

void teams::setContry(const QString &newContry)
{
    contry = newContry;
}

QString teams::getLogo() const
{
    return logo;
}

void teams::setLogo(const QString &newLogo)
{
    logo = newLogo;
}

int teams::getNbsubscribers() const
{
    return nbsubscribers;
}

void teams::setNbsubscribers(const int &newNbsubscribers)
{
    nbsubscribers = newNbsubscribers;
}

QString teams::getKit() const
{
    return kit;
}

void teams::setKit(const QString &newKit)
{
    kit = newKit;
}

int teams::getMatchesPlayed() const
{
    return matchesplayed;
}

void teams::setMatchesPlayed(const int &newMatchesPlayed)
{
    matchesplayed = newMatchesPlayed;
}

teams::teams() {}

teams::teams(const QString &name, const QString &contry, const QString &logo, const int &nbsubscribers, const QString &kit, const int &matchesplayed)
    : name(name), contry(contry), logo(logo), nbsubscribers(nbsubscribers), kit(kit), matchesplayed(matchesplayed)
{}


// CRUD Methods
int generateTeamID() {
    QSqlQuery query("SELECT MAX(TEAMID) FROM teams");
    if (query.next()) {
        int maxTeamID = query.value(0).toInt();
        return maxTeamID + 1;
    }
    return 1;
}

bool teams::addTeams() {

    int teamID = generateTeamID();

    QSqlQuery query;
    query.prepare("INSERT INTO teams (TEAMID, NAME, COUNTRY, LOGO, NBSUBSCRIBERS, KIT, MATCHESPLAYED) "
                  "VALUES (:teamID, :name, :country, :logo, :subscribers, :kit, :matchesPlayed)");

    query.bindValue(":teamID", teamID);
    query.bindValue(":name", name);
    query.bindValue(":country", contry);
    query.bindValue(":logo", logo);
    query.bindValue(":subscribers", nbsubscribers);
    query.bindValue(":kit", kit);
    query.bindValue(":matchesPlayed", matchesplayed);

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Failed to add team:" << query.lastError().text();
        qDebug() << "Query:" << query.lastQuery();
        return false;
    }
    return true;
}

void teams::listTeams(QTableWidget* table)
{
    this->tableWidget = table;
    table->setRowCount(0);
    table->verticalHeader()->setVisible(false);

    table->setIconSize(QSize(50, 50));

    QString queryStr = "SELECT TEAMID, NAME, COUNTRY, LOGO, NBSUBSCRIBERS, KIT, MATCHESPLAYED FROM TEAMS";
    QSqlQuery query;

    if (query.exec(queryStr)) {
        int row = 0;
        while (query.next()) {
            table->insertRow(row);

            table->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));

            table->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));

            table->setItem(row, 2, new QTableWidgetItem(query.value(2).toString()));

            QString logoPath = query.value(3).toString();
            QPixmap logoPixmap(logoPath);
            if (!logoPixmap.isNull()) {
                QTableWidgetItem* logoItem = new QTableWidgetItem();
                logoItem->setData(Qt::DecorationRole, logoPixmap.scaledToHeight(50, Qt::SmoothTransformation));
                table->setItem(row, 3, logoItem);
            } else {
                table->setItem(row, 3, new QTableWidgetItem("No Image"));
            }
            table->setItem(row, 4, new QTableWidgetItem(query.value(4).toString()));

            QString kitPath = query.value(5).toString();
            QPixmap kitPixmap(kitPath);
            if (!kitPixmap.isNull()) {
                QTableWidgetItem* kitItem = new QTableWidgetItem();
                kitItem->setData(Qt::DecorationRole, kitPixmap.scaledToHeight(50, Qt::SmoothTransformation));
                table->setItem(row, 5, kitItem);
            } else {
                table->setItem(row, 5, new QTableWidgetItem("No Image"));
            }

            table->setItem(row, 6, new QTableWidgetItem(query.value(6).toString()));

            table->setRowHeight(row, 100);

            ++row;
        }
        table->setColumnHidden(0, true);
    } else {
        qDebug() << "Failed to fetch data: " << query.lastError();
    }
}


bool teams::updateTeamsUsingTeamId(int teamID, const QString& name, const QString& country, const QString& logo, int subscribers, const QString& kit, int matchesPlayed)
{
    QSqlQuery query;
    query.prepare("UPDATE TEAMS SET NAME = :name, COUNTRY = :country, NBSUBSCRIBERS = :subscribers, MATCHESPLAYED = :matchesPlayed WHERE TEAMID = :teamID");

    // Bind values
    query.bindValue(":name", name);
    query.bindValue(":country", country);
    query.bindValue(":subscribers", subscribers);
    query.bindValue(":matchesPlayed", matchesPlayed);
    query.bindValue(":teamID", teamID);

    // Execute the query
    if (query.exec()) {
        qDebug() << "Team with TEAMID:" << teamID << "updated successfully!";
        return true;
    } else {
        qDebug() << "Error updating team:" << query.lastError().text();
        return false;
    }
}

bool teams::deleteTeamsUsingTeamID(int teamID)
{
    QSqlQuery query;
    query.prepare("DELETE FROM TEAMS WHERE TEAMID = :teamid");
    query.bindValue(":teamid", teamID);

    if (query.exec()) {
        qDebug() << "Team with TEAMID" << teamID << "deleted successfully.";
        return true;
    } else {
        qDebug() << "Failed to delete team with TEAMID" << teamID << ":" << query.lastError();
        return false;
    }
}

void teams::displayTeamStats(QWidget *statsWidget) {
    qDebug() << "displayTeamStats called for widget:" << statsWidget->objectName();

    QWidget* chartContainer = statsWidget->findChild<QWidget*>("chartContainer");

    if (!chartContainer) {
        qDebug() << "Creating new chartContainer";
        chartContainer = new QWidget(statsWidget);
        chartContainer->setObjectName("chartContainer");

        chartContainer->setMinimumSize(400, 400);
        chartContainer->setStyleSheet("background-color: white;");

        if (!statsWidget->layout()) {
            qDebug() << "Creating new layout for statsWidget";
            QVBoxLayout* statsLayout = new QVBoxLayout(statsWidget);
            statsWidget->setLayout(statsLayout);
        }

        statsWidget->layout()->addWidget(chartContainer);
        qDebug() << "Added chartContainer to layout";
    } else {
        qDebug() << "Found existing chartContainer";
    }

    if (chartContainer->layout()) {
        qDebug() << "Clearing existing layout in chartContainer";
        QLayout* oldLayout = chartContainer->layout();
        QLayoutItem* item;
        while ((item = oldLayout->takeAt(0)) != nullptr) {
            if (item->widget()) {
                item->widget()->deleteLater();
            }
            delete item;
        }
        delete oldLayout;
    }

    QVBoxLayout *chartLayout = new QVBoxLayout(chartContainer);
    chartContainer->setLayout(chartLayout);

    QSqlQuery queryMatches;
    queryMatches.prepare(R"(
        SELECT NAME, MATCHESPLAYED, NBSUBSCRIBERS
        FROM (
            SELECT NAME, MATCHESPLAYED, NBSUBSCRIBERS
            FROM TEAMS
            ORDER BY MATCHESPLAYED DESC
        )
        WHERE ROWNUM <= 3
    )");

    if (!queryMatches.exec()) {
        qDebug() << "Error fetching top teams by matches played: " << queryMatches.lastError().text();
        // Add a label to show the error in the UI
        QLabel* errorLabel = new QLabel("Error fetching data: " + queryMatches.lastError().text(), chartContainer);
        chartLayout->addWidget(errorLabel);
        return;
    }

    // Check if we have data
    if (!queryMatches.next()) {
        qDebug() << "No data returned for matches query";
        QLabel* noDataLabel = new QLabel("No team data available", chartContainer);
        chartLayout->addWidget(noDataLabel);
        return;
    }

    queryMatches.previous();

    QStringList teamNamesMatches;
    QVector<int> matchesData;
    QVector<int> subscribersDataMatches;

    while (queryMatches.next()) {
        QString name = queryMatches.value("NAME").toString();
        int matches = queryMatches.value("MATCHESPLAYED").toInt();
        int subs = queryMatches.value("NBSUBSCRIBERS").toInt();

        //qDebug() << "Team data:" << name << matches << subs;

        teamNamesMatches << name;
        matchesData << matches;
        subscribersDataMatches << subs;
    }

    QSqlQuery querySubscribers;
    querySubscribers.prepare(R"(
        SELECT NAME, MATCHESPLAYED, NBSUBSCRIBERS
        FROM (
            SELECT NAME, MATCHESPLAYED, NBSUBSCRIBERS
            FROM TEAMS
            ORDER BY NBSUBSCRIBERS DESC
        )
        WHERE ROWNUM <= 3
    )");

    if (!querySubscribers.exec()) {
        qDebug() << "Error fetching top teams by subscribers: " << querySubscribers.lastError().text();
        return;
    }

    QStringList teamNamesSubs;
    QVector<int> subscribersData;

    while (querySubscribers.next()) {
        teamNamesSubs << querySubscribers.value("NAME").toString();
        subscribersData << querySubscribers.value("NBSUBSCRIBERS").toInt();
    }

    QBarSet *matchesSet = new QBarSet("Matches Played");
    for (int value : matchesData) {
        *matchesSet << value;
    }

    QBarSeries *matchesSeries = new QBarSeries();
    matchesSeries->append(matchesSet);
    matchesSet->setColor(QColor(70, 130, 180));

    QChart *matchesChart = new QChart();
    matchesChart->addSeries(matchesSeries);
    matchesChart->setTitle("Top 3 Teams by Matches Played");
    matchesChart->setAnimationOptions(QChart::SeriesAnimations);
    matchesChart->legend()->setVisible(true);
    matchesChart->legend()->setAlignment(Qt::AlignBottom);

    QBarCategoryAxis *matchesAxisX = new QBarCategoryAxis();
    matchesAxisX->append(teamNamesMatches);
    matchesChart->addAxis(matchesAxisX, Qt::AlignBottom);
    matchesSeries->attachAxis(matchesAxisX);

    QValueAxis *matchesAxisY = new QValueAxis();
    matchesAxisY->setTitleText("Number of Matches");
    matchesAxisY->setMin(0);
    matchesChart->addAxis(matchesAxisY, Qt::AlignLeft);
    matchesSeries->attachAxis(matchesAxisY);

    QChartView *matchesChartView = new QChartView(matchesChart);
    matchesChartView->setRenderHint(QPainter::Antialiasing);
    matchesChartView->setMinimumHeight(200);

    QBarSet *subsSet = new QBarSet("Subscribers");
    for (int value : subscribersData) {
        *subsSet << value;
    }

    QBarSeries *subsSeries = new QBarSeries();
    subsSeries->append(subsSet);
    subsSet->setColor(QColor(220, 20, 60));

    QChart *subsChart = new QChart();
    subsChart->addSeries(subsSeries);
    subsChart->setTitle("Top 3 Teams by Subscribers");
    subsChart->setAnimationOptions(QChart::SeriesAnimations);
    subsChart->legend()->setVisible(true);
    subsChart->legend()->setAlignment(Qt::AlignBottom);

    QBarCategoryAxis *subsAxisX = new QBarCategoryAxis();
    subsAxisX->append(teamNamesSubs);
    subsChart->addAxis(subsAxisX, Qt::AlignBottom);
    subsSeries->attachAxis(subsAxisX);

    QValueAxis *subsAxisY = new QValueAxis();
    subsAxisY->setTitleText("Number of Subscribers");
    subsAxisY->setMin(0);
    subsChart->addAxis(subsAxisY, Qt::AlignLeft);
    subsSeries->attachAxis(subsAxisY);

    QChartView *subsChartView = new QChartView(subsChart);
    subsChartView->setRenderHint(QPainter::Antialiasing);
    subsChartView->setMinimumHeight(200);

    QSplitter *splitter = new QSplitter(Qt::Vertical);
    splitter->addWidget(matchesChartView);
    splitter->addWidget(subsChartView);
    chartLayout->addWidget(splitter);

    chartContainer->show();

    qDebug() << "Charts added to container";
}
