#ifndef TEAMSPAGE_H
#define TEAMSPAGE_H

#include <QWidget>

namespace Ui {
class teamsPage;
}

class teamsPage : public QWidget
{
    Q_OBJECT

public:
    explicit teamsPage(QWidget *parent = nullptr);
    ~teamsPage();

private:
    Ui::teamsPage *ui;
};

#endif // TEAMSPAGE_H
