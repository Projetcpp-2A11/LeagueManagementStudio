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
    explicit employeePage(QWidget *parent = nullptr, employee * loggedInEmployee = nullptr);
    ~employeePage();

    void setupEmployeeTable(QString queryStr);
    void addButtonsToRows(QTableWidget *table);
    void refresh();
    QString defaultQueryStr="SELECT USERID, FIRSTNAME, LASTNAME, DEPNAME FROM Employees";

    void setupFilterGroupBox();
private slots:



    void on_exitButton_clicked();

    void on_homeButton_clicked();

    void on_notifButton_clicked();

    void on_aboutButton_clicked();

    void on_addEmployeeButton_clicked();

    void on_refreshButton_clicked();

    void on_delete_employee_clicked(int row);
    void on_update_employee_clicked(int row);
    bool empInsertionValidateInputs();



    void on_filterButton_clicked();

    void on_cancelFilter_clicked();

    void on_searchCriteriaBox_currentIndexChanged(int index);

private:
    Ui::employeePage *ui;
    employee emp;
    employee *loggedIneEmp;


};

#endif // EMPLOYEEPAGE_H
