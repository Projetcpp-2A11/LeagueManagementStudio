#ifndef EMPLOYEEPAGE_H
#define EMPLOYEEPAGE_H

#include <QWidget>

namespace Ui {
class employeePage;
}

class employeePage : public QWidget
{
    Q_OBJECT

public:
    explicit employeePage(QWidget *parent = nullptr);
    ~employeePage();

private slots:


private:
    Ui::employeePage *ui;
};

#endif // EMPLOYEEPAGE_H
