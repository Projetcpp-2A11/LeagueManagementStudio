#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QWidget>

namespace Ui {
class homepage;
}

class homepage : public QWidget
{
    Q_OBJECT

public:
    explicit homepage(QWidget *parent = nullptr);
    ~homepage();

private slots:
  //  void on_employeeButton_clicked();


    void on_matchsButton_clicked();

private:
    Ui::homepage *ui;
};

#endif // HOMEPAGE_H
