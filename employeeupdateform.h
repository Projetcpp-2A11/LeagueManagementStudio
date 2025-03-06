#ifndef EMPLOYEEUPDATEFORM_H
#define EMPLOYEEUPDATEFORM_H

#include "employee.h"
#include <QWidget>

namespace Ui {
class employeeUpdateForm;
}

class employeeUpdateForm : public QWidget
{
    Q_OBJECT

public:
    explicit employeeUpdateForm(QWidget *parent = nullptr , int UserID=0);
    ~employeeUpdateForm();

private slots:


    void on_save_exit_clicked();

    void on_cancel_clicked();

private:
    Ui::employeeUpdateForm *ui;
    employee employeeToBeUpdated;
};

#endif // EMPLOYEEUPDATEFORM_H
