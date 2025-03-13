#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QWidget>
<<<<<<< HEAD
#include "employee.h"
=======

>>>>>>> d87739afc8594a1567a22d28d94f597f500e3067
namespace Ui {
class homepage;
}

class homepage : public QWidget
{
    Q_OBJECT

public:
<<<<<<< HEAD
    explicit homepage(QWidget *parent = nullptr , employee * loggedInEmployee = nullptr);
    ~homepage();

private slots:
    void on_employeeButton_clicked();

    void on_matchsButton_clicked();

private:
    Ui::homepage *ui;
    employee *emp;
=======
    explicit homepage(QWidget *parent = nullptr);
    ~homepage();

private slots:
    void on_stadiumsButton_clicked();

private:
    Ui::homepage *ui;
>>>>>>> d87739afc8594a1567a22d28d94f597f500e3067
};

#endif // HOMEPAGE_H
