#ifndef EMPLOYEEPAGE_H
#define EMPLOYEEPAGE_H

#include "employee.h"
#include <QWidget>
#include <homepage.h>
#include <QFile>
#include <QFileDialog>

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
    QString currentQueryStr;

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

    QSqlQuery on_applyFilter_clicked();

    void on_searchButton_clicked();
    bool exportTableToCSV(QTableWidget * table);

    void on_exportListButton_clicked();

private:
    Ui::employeePage *ui;
    employee emp;
    employee *loggedIneEmp;



};

#endif // EMPLOYEEPAGE_H
