#ifndef MATCHPAGE_H
#define MATCHPAGE_H

#include <QWidget>
#include "matchpage.h"
#include "ui_matchpage.h"

namespace Ui {
class MatchPage;
}

class employeePage : public QWidget
{
    Q_OBJECT

public:
    explicit employeePage(QWidget *parent = nullptr);
    ~employeePage();

private slots:



private:
    Ui::MatchPage *ui;
};

#endif // MATCHPAGE_H
