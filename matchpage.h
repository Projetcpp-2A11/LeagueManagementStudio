#ifndef MATCHPAGE_H
#define MATCHPAGE_H

#include <QWidget>

namespace Ui {
class matchPage;
}

class employeePage : public QWidget
{
    Q_OBJECT

public:
    explicit employeePage(QWidget *parent = nullptr);
    ~employeePage();

private slots:


private:
    Ui::matchPage *ui;
};

#endif // MATCHPAGE_H
