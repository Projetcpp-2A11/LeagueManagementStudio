#include "match.h"
#include "connection.h"

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

}

void Match::displayTeamGoalStats()
{
    QSqlQuery query;

    query.prepare("SELECT MATCHID, TEAM1ID, TEAM2ID, SCORE "
                  "FROM MATCHES "
                  "ORDER BY MATCHDATE");

    if (!query.exec()) {
        qDebug() << "Erreur de récupération des statistiques de match : " << query.lastError().text();
        return;
    }

    QBarSeries *series = new QBarSeries();
    QBarSet *teamMatches = new QBarSet("Nombre de matchs");
    QBarSet *teamScores = new QBarSet("But total");

    QMap<int, int> teamMatchCount;
    QMap<int, int> teamTotalScore;
    QMap<int, QString> teamNames;

    while (query.next()) {
        int team1Id = query.value("TEAM1ID").toInt();
        int team2Id = query.value("TEAM2ID").toInt();
        QString score = query.value("SCORE").toString().trimmed();

        QStringList scoreParts = score.split('-');
        if (scoreParts.size() != 2) {
            qDebug() << "Score mal formé ignoré :" << score;
            continue;
        }

        bool ok1 = false, ok2 = false;
        int team1Score = scoreParts[0].toInt(&ok1);
        int team2Score = scoreParts[1].toInt(&ok2);
        if (!ok1 || !ok2) {
            qDebug() << "Score non numérique ignoré :" << score;
            continue;
        }

        // Get names for both teams
        for (int teamId : {team1Id, team2Id}) {
            if (!teamNames.contains(teamId)) {
                QSqlQuery teamQuery;
                teamQuery.prepare("SELECT NAME FROM TEAMS WHERE TEAMID = ?");
                teamQuery.addBindValue(teamId);
                if (teamQuery.exec() && teamQuery.next()) {
                    teamNames[teamId] = teamQuery.value(0).toString();
                } else {
                    qDebug() << "Équipe introuvable pour TEAMID:" << teamId << ", match ignoré.";
                    continue;  // Skip match entirely if a team is missing
                }
            }
        }

        // Only process match if both teams are known
        if (!teamNames.contains(team1Id) || !teamNames.contains(team2Id)) {
            continue;
        }

        teamMatchCount[team1Id]++;
        teamMatchCount[team2Id]++;
        teamTotalScore[team1Id] += team1Score;
        teamTotalScore[team2Id] += team2Score;

    }

    QStringList teamLabels;
    QVector<qreal> matchData;
    QVector<qreal> scoreData;

    qDebug() << "Résumé des équipes :";
    for (int teamId : teamMatchCount.keys()) {
        QString name = teamNames.value(teamId);
        int matches = teamMatchCount[teamId];
        int goals = teamTotalScore[teamId];

        qDebug() << "ID:" << teamId << "Nom:" << name << "Matchs:" << matches << "Buts:" << goals;

        teamLabels << name;
        *teamMatches << matches;
        *teamScores << goals;
        matchData << matches;
        scoreData << goals;
    }

    series->append(teamMatches);
    series->append(teamScores);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Nombre total de matchs et but total par équipe");
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->setBackgroundBrush(QBrush(QColor(255, 255, 255)));
    chart->setMargins(QMargins(20, 20, 20, 20));

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(teamLabels);
    axisX->setLabelsAngle(45);
    axisX->setTitleText("Équipes");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Nombre de matchs / But total");
    axisY->setLabelFormat("%d");
    axisY->setTickInterval(1);
    axisY->setMinorTickCount(0);
    axisY->setLabelsFont(QFont("Arial", 10));
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    teamMatches->setColor(QColor(0, 128, 255));  // Bleu
    teamScores->setColor(QColor(255, 0, 0));     // Rouge

    if (chart->scene()) {
        for (int i = 0; i < matchData.size(); ++i) {
            QString matchLabel = QString::number(matchData[i]);
            QString scoreLabel = QString::number(scoreData[i]);

            QGraphicsTextItem *matchText = chart->scene()->addText(matchLabel);
            matchText->setPos(i * 40 + 10, chart->size().height() - matchData[i] * 10 - 50);

            QGraphicsTextItem *scoreText = chart->scene()->addText(scoreLabel);
            scoreText->setPos(i * 40 + 25, chart->size().height() - scoreData[i] * 10 - 50);
        }
    }

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setRenderHint(QPainter::SmoothPixmapTransform);
    chartView->resize(800, 600);
    chartView->setMinimumSize(800, 600);
    chartView->show();
}
// Définition de la fonction fetchMatchData dans match.cpp
bool Match::fetchMatchData(int matchId, QString& team1, QString& team2, QString& score)
{
    // Créer une instance de la classe Connection pour établir une connexion à la base de données
    connection conn;

    // Si la connexion à la base de données échoue, retourner false
    if (!conn.createconnect()) {  // Assure-toi que tu appelles 'createConnection' avec une majuscule
        qDebug() << "Erreur de connexion à la base de données";
        return false;
    }

    // Préparer et exécuter la requête SQL
    QSqlQuery query;
    query.prepare(
        "SELECT T1.NAME, T2.NAME, M.SCORE "
        "FROM MATCHES M "
        "JOIN TEAMS T1 ON M.TEAM1ID = T1.TEAMID "
        "JOIN TEAMS T2 ON M.TEAM2ID = T2.TEAMID "
        "WHERE M.MATCHID = :matchId"
        );
    query.bindValue(":matchId", matchId);

    // Si la requête s'exécute et qu'une ligne est retournée, récupérer les données
    if (query.exec() && query.next()) {
        team1 = query.value(0).toString();  // Nom de la première équipe
        team2 = query.value(1).toString();  // Nom de la deuxième équipe
        score = query.value(2).toString();  // Score du match
        //conn.closeConnection();  // Fermer la connexion à la base de données
        return true;  // Les données ont été récupérées avec succès
    }

    // En cas d'erreur dans la requête, afficher un message d'erreur
    qDebug() << "Erreur SQL:" << query.lastError().text();
    //conn.closeConnection();  // Fermer la connexion à la base de données
    return false;  // Échec de la récupération des données
}

bool Match::updateMatchScore(int matchID, QString newScore)
{
    QSqlQuery query;
    query.prepare("UPDATE MATCHES SET SCORE = :newScore WHERE MATCHID = :matchID");
    query.bindValue(":newScore",newScore);
    query.bindValue(":matchID",matchID);

    if(!query.exec()) {
        qDebug() << "Failed to update match Score";
        return false;
    } else {

        qDebug() << "Successfully updated match score for match" << matchID;
        return true;
    }




}


void Match::updateAdditonalTime(int matchId, int additionalTime)
{
    QSqlQuery query;
    query.prepare("UPDATE MATCHES SET ADDITIONALTIME = :additionalTime WHERE MATCHID = :matchId");
    query.bindValue(":additionalTime", additionalTime);
    query.bindValue(":matchId", matchId);

    if (!query.exec()) {
        qDebug() << "Failed to update additional time:" << query.lastError().text();
    } else {
        qDebug() << "Successfully updated additional time for match" << matchId;
    }
}


Match* Match::findMatchById(int id)
{
    QSqlQuery query;
    query.prepare("SELECT MATCHID, SCORE, MATCHDATE, STADIUMID, TEAM1ID, TEAM2ID FROM MATCHES WHERE MATCHID = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        Match* match = new Match();
        match->matchID = query.value("MATCHID").toInt();
        match->score = query.value("SCORE").toString();
        match->datematch = query.value("MATCHDATE").toDate();
        match->stadiumID = query.value("STADIUMID").toInt();
        match->team1ID = query.value("TEAM1ID").toInt();
        match->team2ID = query.value("TEAM2ID").toInt();
        return match;
    } else {
        qDebug() << "No match found with id:" << id;
        return nullptr;
    }
}

