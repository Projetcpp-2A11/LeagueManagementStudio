#ifndef STADUIMPAGE_H
#define STADUIMPAGE_H

#include <QWidget>
#include "employee.h"
#include "ui_Staduimpage.h"
#include "stadium.h"
#include <QWidget>
#include <QSqlQuery>
#include <QSqlError>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

namespace Ui {
class Staduimpage;
}

class stadiumPage : public QWidget
{
    Q_OBJECT

public:
    explicit stadiumPage(QWidget *parent = nullptr,employee * loggedInEmployee = nullptr);
    ~stadiumPage();
    void addButtonsToRows(QTableWidget *table);



private slots:


    void on_AddStadium_clicked();
    void on_delete_stadium_clicked(int row);
    void on_update_stadium_clicked(int row);
    void on_refresh_clicked();
    void on_homeButton_clicked();
    void on_notifButton_clicked();
    void on_aboutButton_clicked();
    void on_exitButton_clicked();
    void on_searchButton_clicked();
    void on_exportListButton_clicked();
    void on_filter_currentIndexChanged(int index);
    void on_showChartButton_clicked();
    void on_showTopStadiumsButton_clicked();
    void on_checkButton_clicked();
    void on_checkSeatsButton_clicked();
    //void checkMatchAndShowSeats();
    //void generateSeatsGrid(int rows, int cols, int totalSeats, int occupiedSeats, QWidget *targetWidget);

public slots:
    void refreshStadiumList();


private:
    Ui::Staduimpage *ui;
    Stadium stadium;
    employee *loggedIneEmp;

};

#endif // STADUIMPAGE_H
