#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QWidget>
#include "employee.h"
namespace Ui {
class homepage;
}

class homepage : public QWidget
{
    Q_OBJECT

public:
    explicit homepage(QWidget *parent = nullptr , employee * loggedInEmployee = nullptr);
    ~homepage();
    void setupRoleAccess(employee *  emp);

private slots:
    void on_employeeButton_clicked();

    void on_matchsButton_clicked();

    void on_configureFidButton_clicked();

    void on_closeButton_clicked();

    void on_myAccountButton_clicked();

private:
    Ui::homepage *ui;
    employee *emp;
};

#endif // HOMEPAGE_H
