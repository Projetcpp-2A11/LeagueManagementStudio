#ifndef MATCHPAGE_H
#define MATCHPAGE_H

#include "match.h"
#include "qtablewidget.h"
#include <QWidget>


namespace Ui {
class MatchPage;  // Correction du nom de la classe
}

class MatchPage : public QWidget
{
    Q_OBJECT

public:
    explicit MatchPage(QWidget *parent = nullptr);
    ~MatchPage();
    void loadMatches();  // Mise à jour pour charger les matchs
    void connectFilterDialog();
    void updateFilteredMatches(const QList<QString> &filters);
    void loadTeamsIntoComboBox();
    void loadStadiumsIntoComboBox();
    void addButtonsToRows(QTableWidget *table);
    void refresh();
private slots:
    void on_addMatchButton_clicked();  // Mise à jour pour ajouter un match
    void on_delete_match_clicked(int row);
    void on_update_match_clicked(int row);
    void on_searchButton_clicked();


    void on_refresh_clicked();

    void on_filterButton_clicked();
     /*void on_pronosticButton_clicked();*/




    void on_exportListButton_clicked();

    void on_statButton_clicked();

private:
    Ui::MatchPage *ui;  // Correction du nom de la variable
    Match m;

};

#endif // MATCHPAGE_H
