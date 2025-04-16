#ifndef TEAMSPAGE1_H
#define TEAMSPAGE1_H

#include "qtablewidget.h"
#include "teams.h"
#include <QWidget>
#include <QMap>
#include <QLabel>

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
private slots:
    void on_exitButton_clicked();
    void on_homeButton_clicked();
    void on_notifButton_clicked();
    void on_aboutButton_clicked();
    void on_addTeamsButton_clicked();
    void on_refreshButton_clicked();
    void on_delete_team_clicked(int row);
    void on_update_team_clicked(int row);

    // void on_addTeamsLogoButton_clicked();


    void on_addKitButton_clicked();

    void on_addLogoButton_clicked();

    void on_searchButton_clicked();

    void on_filtreTeams_currentIndexChanged(int index);

    void on_exportListButton_clicked();


    void on_prevPageTable_clicked();

    void on_TeamType_clicked();

private:
    Ui::teamsPage *ui;
    teams team;
    void clearInputFields();
    void searchTeams(const QString& searchTerm);
    void on_cellClicked(int row, int column);
    QMap<QString, QLabel*> playerFaceLabels;

};

#endif // TEAMSPAGE1_H
