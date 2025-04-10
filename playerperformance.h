#ifndef PLAYERPERFORMANCE_H
#define PLAYERPERFORMANCE_H

#include <QWidget>
#include "ui_playerperformance.h" // This includes the auto-generated UI class
#include <QDialog>
namespace Ui {
class PlayerPerformance;
}

class PlayerPerformance : public QDialog  // Change QWidget to QDialog
{
    Q_OBJECT

public:
    explicit PlayerPerformance(QWidget *parent = nullptr);
    ~PlayerPerformance();
    void setPlayer(const QString &fname, const QString &lname);

private slots:
    void on_closeButton_clicked();

    void on_exitButton_clicked();

private:
    Ui::playerperformance *ui;
};

#endif // PLAYERPERFORMANCE_H
