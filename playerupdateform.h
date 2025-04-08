#ifndef PLAYERUPDATEFORM_H
#define PLAYERUPDATEFORM_H

#include <QWidget>
#include "player.h"

namespace Ui {
class playerupdateform;
}

class playerupdateform : public QWidget
{
    Q_OBJECT

public:
    explicit playerupdateform(QWidget *parent = nullptr, int playerId=0);
    ~playerupdateform();
    void populateTeamDropdown();

private slots:
    void on_save_exit_clicked();
    void on_cancel_clicked();

private:
    Ui::playerupdateform *ui;
    Player playerToBeUpdated;
};

#endif // PLAYERUPDATEFORM_H
