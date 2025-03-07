#ifndef STADUIMPAGE_H
#define STADUIMPAGE_H

#include <QWidget>
#include "ui_Staduimpage.h"
#include "stadium.h"

namespace Ui {
class Staduimpage;
}

class stadiumPage : public QWidget
{
    Q_OBJECT

public:
    explicit stadiumPage(QWidget *parent = nullptr);
    ~stadiumPage();



    void addButtonsToRows(QTableWidget *table);
private slots:


    void on_AddStadium_clicked();
    void on_delete_stadium_clicked(int row);
    void on_update_stadium_clicked(int row);


public slots:
    void refreshStadiumList();


private:
    Ui::Staduimpage *ui;
    Stadium stadium;
};

#endif // STADUIMPAGE_H
