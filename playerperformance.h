#ifndef PLAYERPERFORMANCE_H
#define PLAYERPERFORMANCE_H

#include "ui_playerperformance.h"
#include <QWidget>
#include <QDialog>

// Remove the forward declaration of Ui::PlayerPerformance
// namespace Ui {
// class PlayerPerformance;
// }

class PlayerPerformance : public QDialog
{
    Q_OBJECT

public:
    explicit PlayerPerformance(QWidget *parent = nullptr);
    ~PlayerPerformance();
    void setPlayer(const QString &fname, const QString &lname);

private slots:
   // void on_closeButton_clicked();
    void on_exitButton_clicked();

private:
    Ui::playerperformance *ui;  // This is the pointer to the generated UI class
};

#endif // PLAYERPERFORMANCE_H
