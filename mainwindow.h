#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "employee.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_login_clicked();


    void on_forgotPasswordClicked_clicked();

    void on_facialRecogButton_clicked();

    void on_vocalRecogButton_clicked();

    employee checkIdExistance(int userID);
    bool authenticateEmployee(employee emp);


private:
    Ui::MainWindow *ui;
    void startSpeechRecognition();

};
#endif // MAINWINDOW_H
