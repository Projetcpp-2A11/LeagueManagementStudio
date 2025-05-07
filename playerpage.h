#ifndef PLAYERPAGE_H
#define PLAYERPAGE_H

#include "player.h"
#include "qchartview.h"
#include <QWidget>

namespace Ui {
class playerPage;
}

class playerPage : public QWidget
{
    Q_OBJECT

public:
    explicit playerPage(QWidget *parent = nullptr);
    ~playerPage();

    //void populateTeamDropdown();  // Declaration of the dropdown population function
    void populateTeamDropdown();
    //void refresh();
    void addButtonsToRows(QTableWidget *table);
     bool deletePlayerUsingTeamID(const QString &firstName, const QString &lastName);  // Declaration here
      void displayPerformanceStats();
     void exportPlayerListPDF();


private slots:
     void on_exitButton_clicked();

     void on_homeButton_clicked();

     void on_notifButton_clicked();

     //void on_aboutButton_clicked();
    void on_addPlayerButton_clicked();
    void setupPlayerTable();
    void on_refreshButton_clicked();
    void on_delete_player_clicked(int row);
    void on_update_player_clicked(int row);
    void on_player_performance_clicked(int row);
    void on_sortButton_clicked();
    //void on_searchButton_clicked();
    void refresh();
    void on_searchLineEdit_cursorPositionChanged( int arg2);
    //void on_position_cursorPositionChanged(int arg1, int arg2);

    void on_statistiqueButton_clicked();
      void on_exportButton_clicked();



      void browseImage();

      void on_BrowseImageButton_clicked();
       void on_suspension_clicked(int row);


  private:
    Ui::playerPage *ui;
    Player player;
    QChartView *chartView;


};

#endif // PLAYERPAGE_H
