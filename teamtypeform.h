#ifndef TEAMSTYPEFORM_H
#define TEAMSTYPEFORM_H

#include <QWidget>
#include <QDialog>
#include <QLabel>

namespace Ui {
class Form; // This must match the class name in your UI file
}

class TeamstypeForm : public QDialog
{
    Q_OBJECT

public:
    explicit TeamstypeForm(QWidget *parent = nullptr);
    ~TeamstypeForm();

    // Methods to set player names
    void setGK(const QString &name);
    void setLB(const QString &name);
    void setCB1(const QString &name);
    void setCB2(const QString &name);
    void setRB(const QString &name);
    void setCM1(const QString &name);
    void setCM2(const QString &name);
    void setCAM(const QString &name);
    void setLW(const QString &name);
    void setST(const QString &name);
    void setRW(const QString &name);

private:
    Ui::Form *ui;
};

#endif // TEAMSTYPEFORM_H
