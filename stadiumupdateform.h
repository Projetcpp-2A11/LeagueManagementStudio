#ifndef STADIUMUPDATEFORM_H
#define STADIUMUPDATEFORM_H

#include <QWidget>
#include <QMessageBox>
#include "stadium.h"

namespace Ui {
class stadiumupdateform;
}

class stadiumupdateform : public QWidget
{
    Q_OBJECT

public:
    explicit stadiumupdateform(QWidget *parent = nullptr, int stadiumID = 0);
    ~stadiumupdateform();

private slots :
    void on_save_clicked();
    void on_cancel_clicked();
    bool validateInputs();

private:
    Ui::stadiumupdateform *ui;
    Stadium stadiumToBeUpdated;
};

#endif // STADIUMUPDATEFORM_H
