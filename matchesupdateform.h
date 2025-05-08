#ifndef MATCHESUPDATEFORM_H
#define MATCHESUPDATEFORM_H

#include <QWidget>

namespace Ui {
class matchesUpdateForm;
}

class matchesUpdateForm : public QWidget
{
    Q_OBJECT

public:
    explicit matchesUpdateForm(QWidget *parent = nullptr, int matchID=0);
    ~matchesUpdateForm();

private slots:
    void on_save_exit_clicked();

    void on_cancel_clicked();

private:
    Ui::matchesUpdateForm *ui;
};

#endif // MATCHESUPDATEFORM_H
