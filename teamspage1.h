#ifndef TEAMSPAGE1_H
#define TEAMSPAGE1_H

#include "qtablewidget.h"
#include "teams.h"
#include <QWidget>
#include <QMap>
#include <QLabel>
#include <QtCharts>
#include <numeric>
#include "ui_teamspage1.h"


namespace Ui {
class teamsPage;
}

class teamsPage : public QWidget
{
    Q_OBJECT

public:
    explicit teamsPage(QWidget *parent = nullptr);
    ~teamsPage();
    void setupTeamsTable();
    void addButtonsToRows(QTableWidget* table);
    void sortTableByColumn(int column, Qt::SortOrder order);
    void refresh();

    // Statistical methods
    void setupStatsWidgets();  // Initialize UI elements for statistics
    void calculateTeamStats(); // Calculate statistics from team data
    void updateStatsDisplay(); // Update UI with calculated stats
    void createStatsChart();
    //void displayTeamStats();     // Create visual chart representation

private slots:
    void on_exitButton_clicked();
    void on_homeButton_clicked();
    void on_notifButton_clicked();
    void on_aboutButton_clicked();
    void on_addTeamsButton_clicked();
    void on_refreshButton_clicked();
    void on_delete_team_clicked(int row);
    void on_update_team_clicked(int row);
    void on_addKitButton_clicked();
    void on_addLogoButton_clicked();
    void on_searchButton_clicked();
    void on_filtreTeams_currentIndexChanged(int index);
    void on_exportListButton_clicked();
    void on_TeamType_clicked();
    void on_prevPageTable_clicked();

private:
    Ui::teamsPage *ui;
    teams team;

    QChartView *statsChartView;  // For displaying charts

    // Statistical data members
    double averagePlayers;
    int totalTeams;
    // Add more stats as needed

    void clearInputFields();
    void searchTeams(const QString& searchTerm);
    void on_cellClicked(int row, int column);
    QMap<QString, QLabel*> playerFaceLabels;


    double calculateAverage(const QVector<double>& data);
    double calculateStandardDeviation(const QVector<double>& data);
    QVector<double> extractTeamData(int column); // Extract data from table column

    QPushButton* m_showMatchesButton = nullptr;

    void resizeEvent(QResizeEvent* event) override;
    void displayTeamFormMatches(int teamId);
};

#endif // TEAMSPAGE1_H
