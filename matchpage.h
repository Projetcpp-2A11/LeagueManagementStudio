#ifndef MATCHPAGE_H
#define MATCHPAGE_H

#include <QWidget>
#include "ui_matchs.h"

namespace Ui {
class matchPage;
}

class matchPage : public QWidget
{
    Q_OBJECT

public:
    explicit matchPage(QWidget *parent = nullptr);
    ~matchPage();

private slots:



    void on_homeButton_clicked();

private:
    Ui::matchPage *ui;
};

#endif // MATCHPAGE_H
