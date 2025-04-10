#include "match.h"
#include "qheaderview.h"
#include "qsqlerror.h"
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>





Match::Match( int team1ID, int team2ID, QDate date, QString sc, int stadiumID)
{
    this->team1ID = team1ID;
    this->team2ID = team2ID;
    this->datematch = date;
    this->score = sc;
    this->stadiumID = stadiumID;
}

bool Match::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO MATCHES (TEAM1ID, TEAM2ID, MATCHDATE, SCORE, STADIUMID) "
                  "VALUES ( :team1ID, :team2ID, TO_DATE(:datematch, 'YYYY-MM-DD'), :score, :stadiumID)");

    // Création des variables liées
    query.bindValue(":team1ID", team1ID);
    query.bindValue(":team2ID", team2ID);
    query.bindValue(":datematch", datematch.toString("yyyy-MM-dd"));
    query.bindValue(":score", score);
    query.bindValue(":stadiumID", stadiumID);

    // exec() envoie la requête pour l'exécuter
    return query.exec();
}

QSqlQueryModel* Match::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM MATCHES");
    return model;
}

bool Match::supprimer(int matchID)
{
    QSqlQuery query;
    query.prepare("DELETE FROM MATCHES WHERE MATCHID = :matchID");
    query.bindValue(":matchID", matchID);
    return query.exec();
}

void Match::listMatchesInTable(QTableWidget* table)
{
    table->clearContents();  // Clear previous contents
    table->setRowCount(0);    // Reset row count
    table->verticalHeader()->setVisible(false);  // Hide vertical header

    // Modified query to join MATCHES and TEAMS to get team names
    QString queryStr = "SELECT M.MATCHID, T1.NAME AS TEAM1NAME, T2.NAME AS TEAM2NAME, M.MATCHDATE, M.SCORE, S.NAME AS STADIUMNAME "
                       "FROM MATCHES M "
                       "JOIN TEAMS T1 ON M.TEAM1ID = T1.TEAMID "
                       "JOIN TEAMS T2 ON M.TEAM2ID = T2.TEAMID "
                       "JOIN STADIUM S ON M.STADIUMID = S.STADIUMID";


    QSqlQuery query;

    if (query.exec(queryStr)) {
        int row = 0;
        while (query.next()) {
            table->insertRow(row);  // Add a new row for each match

            // Insert data into respective columns
            //table->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));  // MATCHID
            table->setItem(row, 0, new QTableWidgetItem(query.value(1).toString()));  // TEAM1NAME
            table->setItem(row, 1, new QTableWidgetItem(query.value(2).toString()));  // TEAM2NAME
            table->setItem(row, 2, new QTableWidgetItem(query.value(3).toDate().toString("yyyy-MM-dd")));  // MATCHDATE
            table->setItem(row, 3, new QTableWidgetItem(query.value(4).toString()));  // SCORE
            table->setItem(row, 4, new QTableWidgetItem(query.value(5).toString()));  // STADIUMID
            table->item(row, 0)->setData(Qt::UserRole, query.value(0).toInt());  // Store MATCHID in Team1's cell

            ++row;  // Move to the next row
        }
    } else {
        qDebug() << "Failed to fetch data: " << query.lastError();  // Log any query error
    }
}
void Match::searchMatches(const QString &searchText, const QList<QString> &filters, QTableWidget *matchsTable)
{
    // Exécuter la requête de recherche d'équipes avec les filtres
    QSqlQuery query;
    QString queryStr = "SELECT M.MATCHID, T1.NAME AS TEAM1NAME, T2.NAME AS TEAM2NAME, M.MATCHDATE, M.SCORE, S.NAME AS STADIUMNAME "
                       "FROM MATCHES M "
                       "JOIN TEAMS T1 ON M.TEAM1ID = T1.TEAMID "
                       "JOIN TEAMS T2 ON M.TEAM2ID = T2.TEAMID "
                       "JOIN STADIUM S ON M.STADIUMID = S.STADIUMID "
                       "WHERE (UPPER(T1.NAME) LIKE UPPER(:searchText) OR UPPER(T2.NAME) LIKE UPPER(:searchText))";

    // Appliquer les filtres ici (vous pouvez ajouter des conditions sur la date, le stade, etc.)
    if (!filters[0].isEmpty()) {
        queryStr += " AND M.MATCHDATE >= :startDate";
    }
    if (!filters[1].isEmpty()) {
        queryStr += " AND M.MATCHDATE <= :endDate";
    }
    if (!filters[2].isEmpty()) {
        queryStr += " AND S.NAME LIKE :stadium";
    }

    query.prepare(queryStr);
    query.bindValue(":searchText", "%" + searchText + "%");

    // Appliquer les filtres
    if (!filters[0].isEmpty()) {
        query.bindValue(":startDate", filters[0]);
    }
    if (!filters[1].isEmpty()) {
        query.bindValue(":endDate", filters[1]);
    }
    if (!filters[2].isEmpty()) {
        query.bindValue(":stadium", "%" + filters[2] + "%");
    }

    if (!query.exec()) {
        qDebug() << "Search query failed: " << query.lastError().text();
        return;
    }

    matchsTable->clearContents();
    matchsTable->setRowCount(0);

    int row = 0;
    while (query.next()) {
        matchsTable->insertRow(row);

        matchsTable->setItem(row, 0, new QTableWidgetItem(query.value(1).toString()));
        matchsTable->setItem(row, 1, new QTableWidgetItem(query.value(2).toString()));
        matchsTable->setItem(row, 2, new QTableWidgetItem(query.value(3).toDate().toString("yyyy-MM-dd")));
        matchsTable->setItem(row, 3, new QTableWidgetItem(query.value(4).toString()));
        matchsTable->setItem(row, 4, new QTableWidgetItem(query.value(5).toString()));

        matchsTable->item(row, 0)->setData(Qt::UserRole, query.value(0).toInt());

        ++row;
    }

    matchsTable->sortItems(2, Qt::AscendingOrder);  // Trier par date
}

void Match::displayTeamGoalStats()
{
    QSqlQuery query;

    // Préparer la requête SQL pour récupérer les matchs et les scores
    query.prepare("SELECT MATCHID, TEAM1ID, TEAM2ID, SCORE "
                  "FROM MATCHES "
                  "ORDER BY MATCHDATE");

    // Exécuter la requête
    if (!query.exec()) {
        qDebug() << "Erreur de récupération des statistiques de match : " << query.lastError().text();
        return;
    }

    // Créer une série de barres empilées
    QBarSeries *series = new QBarSeries();

    // Créer des ensembles de barres pour les scores et les matchs
    QBarSet *teamMatches = new QBarSet("Nombre de matchs");
    QBarSet *teamScores = new QBarSet("but total");

    // Créer des compteurs pour le nombre de matchs et les scores
    QMap<int, int> teamMatchCount;  // Nombre de matchs pour chaque équipe
    QMap<int, int> teamTotalScore;  // Score total pour chaque équipe
    QMap<int, QString> teamNames;   // Noms des équipes par ID

    // Analyser les résultats de la requête pour récupérer les équipes
    while (query.next()) {
        int team1Id = query.value("TEAM1ID").toInt();  // Récupérer TEAM1ID
        int team2Id = query.value("TEAM2ID").toInt();  // Récupérer TEAM2ID
        QString score = query.value("SCORE").toString();  // Récupérer SCORE

        // Diviser le score en deux parties (score de Team 1 et de Team 2)
        QStringList scoreParts = score.split('-');
        int team1Score = scoreParts[0].toInt();
        int team2Score = scoreParts[1].toInt();

        // Récupérer les noms des équipes
        if (!teamNames.contains(team1Id)) {
            QSqlQuery teamQuery;
            teamQuery.prepare("SELECT NAME FROM TEAMS WHERE TEAMID = ?");
            teamQuery.addBindValue(team1Id);
            if (teamQuery.exec() && teamQuery.next()) {
                teamNames[team1Id] = teamQuery.value(0).toString();
            }
        }
        if (!teamNames.contains(team2Id)) {
            QSqlQuery teamQuery;
            teamQuery.prepare("SELECT NAME FROM TEAMS WHERE TEAMID = ?");
            teamQuery.addBindValue(team2Id);
            if (teamQuery.exec() && teamQuery.next()) {
                teamNames[team2Id] = teamQuery.value(0).toString();
            }
        }

        // Mettre à jour les compteurs de matchs et de scores pour chaque équipe
        teamMatchCount[team1Id]++;
        teamMatchCount[team2Id]++;
        teamTotalScore[team1Id] += team1Score;
        teamTotalScore[team2Id] += team2Score;
    }

    // Créer une liste des équipes et remplir les ensembles de barres
    QStringList teamLabels;
    for (auto teamId : teamMatchCount.keys()) {
        teamLabels << teamNames[teamId];  // Ajouter le nom de l'équipe depuis le QMap

        // Ajouter les valeurs pour chaque équipe (matchs et score total)
        *teamMatches << static_cast<qreal>(teamMatchCount[teamId]);  // Nombre de matchs
        *teamScores << static_cast<qreal>(teamTotalScore[teamId]);   // Score total
    }

    // Ajouter les ensembles à la série
    series->append(teamMatches);
    series->append(teamScores);

    // Créer le graphique et ajouter la série
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Nombre total de matchs et but total par équipe");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    // Personnalisation du fond du graphique
    chart->setBackgroundBrush(QBrush(QColor(255, 255, 255)));  // Fond blanc
    chart->setMargins(QMargins(20, 20, 20, 20));  // Marges autour du graphique

    // Axe X pour les labels des équipes
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(teamLabels);  // Les labels afficheront les vrais noms des équipes
    axisX->setLabelsAngle(45);  // Incliner les labels pour les rendre plus lisibles
    axisX->setTitleText("Équipes");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // Axe Y pour les scores et les matchs
    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Nombre de matchs / But total");
    axisY->setLabelFormat("%d");  // Format des étiquettes
    axisY->setTickInterval(1);  // Intervalle de ticks
    axisY->setMinorTickCount(0);  // Désactiver les ticks mineurs
    axisY->setLabelsFont(QFont("Arial", 10));  // Police de l'étiquette
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // Personnalisation des barres
    teamMatches->setColor(QColor(0, 128, 255));  // Bleu pour le nombre de matchs
    teamScores->setColor(QColor(255, 0, 0));   // Rouge pour le score total

    // Ajouter des annotations pour les valeurs
    for (int i = 0; i < teamMatchCount.size(); ++i) {
        if (i < teamMatches->count() && i < teamScores->count()) {
            // Ajouter des annotations de texte pour les barres
            QString matchCountLabel = QString::number(teamMatchCount.values().at(i));
            QString scoreLabel = QString::number(teamTotalScore.values().at(i));

            // Debugger pour vérifier les valeurs
            qDebug() << "Index : " << i << " Nombre de matchs : " << matchCountLabel << " but total : " << scoreLabel;

            // Vérification si la scène existe
            if (chart->scene()) {
                QGraphicsTextItem *matchCountAnnotation = chart->scene()->addText(matchCountLabel);
                matchCountAnnotation->setPos(teamMatches->at(i) - 0.2, teamMatches->at(i) + 20);  // Positionner l'annotation

                QGraphicsTextItem *scoreAnnotation = chart->scene()->addText(scoreLabel);
                scoreAnnotation->setPos(teamScores->at(i) - 0.2, teamScores->at(i) + 20);  // Positionner l'annotation
            } else {
                qDebug() << "Erreur : Scene n'existe pas.";
            }
        }
    }

    // Créer la vue du graphique
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setRenderHint(QPainter::SmoothPixmapTransform);
    chartView->resize(800, 600);
    chartView->setMinimumSize(800, 600);  // Taille minimale
    chartView->show();
}
