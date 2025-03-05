#ifndef EMPLOYEEPAGE_H
#define EMPLOYEEPAGE_H

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
private slots:



    void on_exitButton_clicked();

    void on_homeButton_clicked();

    void on_notifButton_clicked();

    void on_aboutButton_clicked();

    void on_addEmployeeButton_clicked();

private:
    Ui::employeePage *ui;
};

#endif // EMPLOYEEPAGE_H
