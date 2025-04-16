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
#include "qpushbutton.h"
#include "qsplitter.h"
#include "qsqlerror.h"
#include "qvalueaxis.h"
#include <QSignalMapper>
#include <QFileInfo>
#include <QFileDialog>
#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QScrollArea>
#include <QLabel>
#include <QPushButton>
#include <QFrame>
#include <QFont>
#include <QPixmap>
#include <QDateTime>
#include <QMessageBox>
#include <QDebug>

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










// depararteur de travvvvvvv


void teams::displayTeamStats(QWidget *statsWidget) {
    qDebug() << "displayTeamStats called for widget:" << statsWidget->objectName();

    // Find or create a container widget for the charts
    QWidget* chartContainer = statsWidget->findChild<QWidget*>("chartContainer");

    if (!chartContainer) {
        qDebug() << "Creating new chartContainer";
        // Create a new container for charts if it doesn't exist
        chartContainer = new QWidget(statsWidget);
        chartContainer->setObjectName("chartContainer");

        // Make sure the container is visible and has a reasonable size
        chartContainer->setMinimumSize(400, 400);
        chartContainer->setStyleSheet("background-color: white;"); // Add background for visibility debugging

        // Add the container to the stats widget layout
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

    // Clear any existing content in the chart container
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

    // Create a new layout for the chart container
    QVBoxLayout *chartLayout = new QVBoxLayout(chartContainer);
    chartContainer->setLayout(chartLayout);

    // Query to get top 3 teams by matches played
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

    // Reset the query position
    queryMatches.previous();

    // Prepare data containers for matches played
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

    // Query to get top 3 teams by number of subscribers
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

    // Prepare data containers for subscribers
    QStringList teamNamesSubs;
    QVector<int> subscribersData;

    while (querySubscribers.next()) {
        teamNamesSubs << querySubscribers.value("NAME").toString();
        subscribersData << querySubscribers.value("NBSUBSCRIBERS").toInt();
    }

    // ---------------------------
    // 1. Matches Played Chart (Top 3)
    // ---------------------------
    QBarSet *matchesSet = new QBarSet("Matches Played");
    for (int value : matchesData) {
        *matchesSet << value;
    }

    QBarSeries *matchesSeries = new QBarSeries();
    matchesSeries->append(matchesSet);
    matchesSet->setColor(QColor(70, 130, 180));  // Steel blue

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
    matchesAxisY->setMin(0);  // Start from 0 for better visualization
    matchesChart->addAxis(matchesAxisY, Qt::AlignLeft);
    matchesSeries->attachAxis(matchesAxisY);

    QChartView *matchesChartView = new QChartView(matchesChart);
    matchesChartView->setRenderHint(QPainter::Antialiasing);
    matchesChartView->setMinimumHeight(200);  // Set minimum height

    // ---------------------------
    // 2. Subscribers Chart (Top 3)
    // ---------------------------
    QBarSet *subsSet = new QBarSet("Subscribers");
    for (int value : subscribersData) {
        *subsSet << value;
    }

    QBarSeries *subsSeries = new QBarSeries();
    subsSeries->append(subsSet);
    subsSet->setColor(QColor(220, 20, 60));  // Crimson red

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
    subsAxisY->setMin(0);  // Start from 0 for better visualization
    subsChart->addAxis(subsAxisY, Qt::AlignLeft);
    subsSeries->attachAxis(subsAxisY);

    QChartView *subsChartView = new QChartView(subsChart);
    subsChartView->setRenderHint(QPainter::Antialiasing);
    subsChartView->setMinimumHeight(200);  // Set minimum height

    // ---------------------------
    // Layout both charts vertically
    // ---------------------------
    QSplitter *splitter = new QSplitter(Qt::Vertical);
    splitter->addWidget(matchesChartView);
    splitter->addWidget(subsChartView);
    chartLayout->addWidget(splitter);

    // Make sure the container is visible
    chartContainer->show();

    qDebug() << "Charts added to container";
}




//equioe form

void teams::displayMatchesWithScores() {
    // Créer une nouvelle fenêtre
    QDialog *matchWindow = new QDialog();
    matchWindow->setWindowTitle("Détails des Matchs");
    matchWindow->setMinimumSize(1000, 700);

    // Créer un layout principal pour la fenêtre
    QVBoxLayout *mainLayout = new QVBoxLayout(matchWindow);

    // Créer un titre
    QLabel *titleLabel = new QLabel("Tous les Matchs Joués", matchWindow);
    QFont titleFont = titleLabel->font();
    titleFont.setPointSize(16);
    titleFont.setBold(true);
    titleLabel->setFont(titleFont);
    titleLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(titleLabel);

    // Créer un widget de défilement pour contenir tous les matchs
    QScrollArea *scrollArea = new QScrollArea(matchWindow);
    scrollArea->setWidgetResizable(true);
    QWidget *scrollContent = new QWidget();
    QVBoxLayout *scrollLayout = new QVBoxLayout(scrollContent);

    // Requête SQL pour récupérer les données des matchs
    QSqlQuery matchQuery;
    matchQuery.prepare(R"(
        SELECT m.MATCHID, m.SCORE, m.MATCHDATE,
               t1.TEAMID as TEAM1ID, t1.NAME as TEAM1_NAME, t1.LOGO as TEAM1_LOGO,
               t2.TEAMID as TEAM2ID, t2.NAME as TEAM2_NAME, t2.LOGO as TEAM2_LOGO
        FROM MATCHES m
        JOIN TEAMS t1 ON m.TEAM1ID = t1.TEAMID
        JOIN TEAMS t2 ON m.TEAM2ID = t2.TEAMID
        ORDER BY m.MATCHDATE DESC
    )");

    if (!matchQuery.exec()) {
        qDebug() << "Erreur lors de la récupération des matchs: " << matchQuery.lastError().text();
        QMessageBox::critical(matchWindow, "Erreur", "Impossible de récupérer les données des matchs: " + matchQuery.lastError().text());
        return;
    }

    // Initialiser un compteur pour les matchs
    int currentMatch = 0;

    // Parcourir les matchs
    while (matchQuery.next()) {
        // Ajouter un séparateur avant chaque match sauf le premier
        if (currentMatch > 0) {
            QFrame *line = new QFrame();
            line->setFrameShape(QFrame::HLine);
            line->setFrameShadow(QFrame::Sunken);
            scrollLayout->addWidget(line);
        }

        currentMatch++;

        int matchId = matchQuery.value("MATCHID").toInt();
        QString score = matchQuery.value("SCORE").toString();
        QDateTime matchDate = matchQuery.value("MATCHDATE").toDateTime();

        int team1Id = matchQuery.value("TEAM1ID").toInt();
        QString team1Name = matchQuery.value("TEAM1_NAME").toString();
        QString team1Logo = matchQuery.value("TEAM1_LOGO").toString();

        int team2Id = matchQuery.value("TEAM2ID").toInt();
        QString team2Name = matchQuery.value("TEAM2_NAME").toString();
        QString team2Logo = matchQuery.value("TEAM2_LOGO").toString();

        // Créer un widget pour ce match
        QWidget *matchWidget = new QWidget();
        QVBoxLayout *matchLayout = new QVBoxLayout(matchWidget);

        // Créer un cadre pour le match
        QFrame *matchFrame = new QFrame();
        matchFrame->setFrameShape(QFrame::StyledPanel);
        matchFrame->setFrameShadow(QFrame::Raised);
        matchFrame->setStyleSheet("QFrame { background-color: #f5f5f5; border-radius: 8px; padding: 10px; }");

        QVBoxLayout *frameLayout = new QVBoxLayout(matchFrame);

        // En-tête du match (date et ID)
        QLabel *matchHeader = new QLabel(QString("Match #%1 - %2")
                                             .arg(matchId)
                                             .arg(matchDate.toString("dd/MM/yyyy")));
        matchHeader->setAlignment(Qt::AlignCenter);
        QFont headerFont = matchHeader->font();
        headerFont.setBold(true);
        headerFont.setPointSize(12);
        matchHeader->setFont(headerFont);
        frameLayout->addWidget(matchHeader);

        // Widget pour les équipes et le score
        QWidget *teamsWidget = new QWidget();
        QHBoxLayout *teamsLayout = new QHBoxLayout(teamsWidget);

        // Équipe 1
        QWidget *team1Widget = new QWidget();
        QVBoxLayout *team1Layout = new QVBoxLayout(team1Widget);

        // Logo de l'équipe 1
        QLabel *team1LogoLabel = new QLabel();
        if (!team1Logo.isEmpty()) {
            QPixmap pixmap(team1Logo);
            if (!pixmap.isNull()) {
                team1LogoLabel->setPixmap(pixmap.scaled(100, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation));
            } else {
                team1LogoLabel->setText("Logo non disponible");
            }
        } else {
            team1LogoLabel->setText("Logo non disponible");
        }
        team1LogoLabel->setAlignment(Qt::AlignCenter);
        team1Layout->addWidget(team1LogoLabel);

        // Nom de l'équipe 1
        QLabel *team1NameLabel = new QLabel(team1Name);
        team1NameLabel->setAlignment(Qt::AlignCenter);
        QFont teamFont = team1NameLabel->font();
        teamFont.setBold(true);
        teamFont.setPointSize(11);
        team1NameLabel->setFont(teamFont);
        team1Layout->addWidget(team1NameLabel);

        teamsLayout->addWidget(team1Widget);

        // Score
        QLabel *scoreLabel = new QLabel(score);
        scoreLabel->setAlignment(Qt::AlignCenter);
        QFont scoreFont = scoreLabel->font();
        scoreFont.setBold(true);
        scoreFont.setPointSize(16);
        scoreLabel->setFont(scoreFont);
        scoreLabel->setStyleSheet("color: #d32f2f;");
        teamsLayout->addWidget(scoreLabel);

        // Équipe 2
        QWidget *team2Widget = new QWidget();
        QVBoxLayout *team2Layout = new QVBoxLayout(team2Widget);

        // Logo de l'équipe 2
        QLabel *team2LogoLabel = new QLabel();
        if (!team2Logo.isEmpty()) {
            QPixmap pixmap(team2Logo);
            if (!pixmap.isNull()) {
                team2LogoLabel->setPixmap(pixmap.scaled(100, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation));
            } else {
                team2LogoLabel->setText("Logo non disponible");
            }
        } else {
            team2LogoLabel->setText("Logo non disponible");
        }
        team2LogoLabel->setAlignment(Qt::AlignCenter);
        team2Layout->addWidget(team2LogoLabel);

        // Nom de l'équipe 2
        QLabel *team2NameLabel = new QLabel(team2Name);
        team2NameLabel->setAlignment(Qt::AlignCenter);
        team2NameLabel->setFont(teamFont);
        team2Layout->addWidget(team2NameLabel);

        teamsLayout->addWidget(team2Widget);

        frameLayout->addWidget(teamsWidget);

        // Récupérer les performances des équipes pour ce match
        QSqlQuery perfQuery;
        perfQuery.prepare(R"(
            SELECT tp.TEAMID, t.NAME, tp.POSSESSION, tp.RESULT, tp.NUMSHOT,
                   tp.CORNERS, tp.TEAMYELLOWCARDS, tp.TEAMREDCARDS
            FROM TEAMPERFORMANCE tp
            JOIN TEAMS t ON tp.TEAMID = t.TEAMID
            WHERE tp.MATCHID = :matchId
        )");
        perfQuery.bindValue(":matchId", matchId);

        if (!perfQuery.exec()) {
            qDebug() << "Erreur lors de la récupération des performances: " << perfQuery.lastError().text();
            continue;
        }

        // Tableau des statistiques
        QWidget *statsWidget = new QWidget();
        QGridLayout *statsLayout = new QGridLayout(statsWidget);

        // En-têtes du tableau
        QStringList headers = {"Équipe", "Possession", "Résultat", "Tirs", "Corners", "Cartons Jaunes", "Cartons Rouges"};
        for (int i = 0; i < headers.size(); ++i) {
            QLabel *headerLabel = new QLabel(headers[i]);
            headerLabel->setAlignment(Qt::AlignCenter);
            QFont font = headerLabel->font();
            font.setBold(true);
            headerLabel->setFont(font);
            statsLayout->addWidget(headerLabel, 0, i);
        }

        int row = 1;
        while (perfQuery.next()) {
            int teamId = perfQuery.value("TEAMID").toInt();
            QString teamName = perfQuery.value("NAME").toString();
            double possession = perfQuery.value("POSSESSION").toDouble();
            QString result = perfQuery.value("RESULT").toString();
            int numShot = perfQuery.value("NUMSHOT").toInt();
            int corners = perfQuery.value("CORNERS").toInt();
            int yellowCards = perfQuery.value("TEAMYELLOWCARDS").toInt();
            int redCards = perfQuery.value("TEAMREDCARDS").toInt();

            // Ajouter les données à la ligne
            QLabel *teamLabel = new QLabel(teamName);
            teamLabel->setAlignment(Qt::AlignCenter);
            statsLayout->addWidget(teamLabel, row, 0);

            QLabel *possessionLabel = new QLabel(QString::number(possession, 'f', 1) + "%");
            possessionLabel->setAlignment(Qt::AlignCenter);
            statsLayout->addWidget(possessionLabel, row, 1);

            QLabel *resultLabel = new QLabel(result);
            resultLabel->setAlignment(Qt::AlignCenter);
            if (result == "WIN") {
                resultLabel->setStyleSheet("color: green; font-weight: bold;");
            } else if (result == "LOSE") {
                resultLabel->setStyleSheet("color: red;");
            } else {
                resultLabel->setStyleSheet("color: orange;");
            }
            statsLayout->addWidget(resultLabel, row, 2);

            QLabel *numShotLabel = new QLabel(QString::number(numShot));
            numShotLabel->setAlignment(Qt::AlignCenter);
            statsLayout->addWidget(numShotLabel, row, 3);

            QLabel *cornersLabel = new QLabel(QString::number(corners));
            cornersLabel->setAlignment(Qt::AlignCenter);
            statsLayout->addWidget(cornersLabel, row, 4);

            QLabel *yellowCardsLabel = new QLabel(QString::number(yellowCards));
            yellowCardsLabel->setAlignment(Qt::AlignCenter);
            statsLayout->addWidget(yellowCardsLabel, row, 5);

            QLabel *redCardsLabel = new QLabel(QString::number(redCards));
            redCardsLabel->setAlignment(Qt::AlignCenter);
            statsLayout->addWidget(redCardsLabel, row, 6);

            row++;
        }

        frameLayout->addWidget(statsWidget);

        // Ajouter le cadre au layout du match
        matchLayout->addWidget(matchFrame);

        // Ajouter le widget du match au layout de défilement
        scrollLayout->addWidget(matchWidget);
    }

    // Ajouter un widget vide extensible à la fin pour pousser tout vers le haut
    scrollLayout->addStretch();

    // Configurer la zone de défilement
    scrollArea->setWidget(scrollContent);
    mainLayout->addWidget(scrollArea);

    // Ajouter un bouton pour fermer la fenêtre
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    QPushButton *closeButton = new QPushButton("Fermer", matchWindow);
    closeButton->setMinimumWidth(120);
    buttonLayout->addStretch();
    buttonLayout->addWidget(closeButton);
    buttonLayout->addStretch();
    mainLayout->addLayout(buttonLayout);

    // Connecter le bouton à la fermeture de la fenêtre
    connect(closeButton, &QPushButton::clicked, matchWindow, &QDialog::accept);

    // Afficher la fenêtre
    matchWindow->exec();

    // Nettoyer la mémoire après la fermeture
    delete matchWindow;
}
