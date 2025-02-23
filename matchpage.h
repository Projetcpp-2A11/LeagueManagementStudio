#ifndef MATCHPAGE_H
#define MATCHPAGE_H

#include <QWidget>

namespace Ui {
class matchPage;
}

class matchpage : public QWidget
{
    Q_OBJECT

public:
    explicit matchpage(QWidget *parent = nullptr);
    ~matchpage();

private slots:


private:
    Ui::matchPage *ui;
};

#endif // MATCHPAGE_H
