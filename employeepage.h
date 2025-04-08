#ifndef EMPLOYEEPAGE_H
#define EMPLOYEEPAGE_H

#include "employee.h"
#include <QWidget>
#include <homepage.h>

namespace Ui {
class employeePage;
}

class employeePage : public QWidget
{
    Q_OBJECT

public:
    explicit employeePage(QWidget *parent = nullptr);
    ~employeePage();

    void setupEmployeeTable();
    void addButtonsToRows(QTableWidget *table);
    void refresh();
private slots:



    void on_exitButton_clicked();

    void on_homeButton_clicked();

    void on_notifButton_clicked();

    void on_aboutButton_clicked();

    void on_addEmployeeButton_clicked();

    void on_refreshButton_clicked();

    void on_delete_employee_clicked(int row);
    void on_update_employee_clicked(int row);


    void on_employeeTableWidget_cellActivated(int row, int column);

private:
    Ui::employeePage *ui;
    employee emp;
};

#endif // EMPLOYEEPAGE_H
