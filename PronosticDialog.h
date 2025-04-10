#ifndef PRONOSTICDIALOG_H
#define PRONOSTICDIALOG_H

#include <QDialog>
#include <QDate>

namespace Ui {
class PronosticDialog; // ✔️ Doit correspondre au nom dans ui_PronosticDialog.h
}

class PronosticDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PronosticDialog(int matchId, QWidget *parent = nullptr);
    ~PronosticDialog();

private:
    Ui::PronosticDialog *ui; // Même nom que dans le namespace
    void loadMatchData(int matchId);
    void calculateAndDisplayOdds(int team1Id, int team2Id);
    QString getRecentTeamForm(int teamId);
    QString getTeamName(int teamId);
};

#endif // PRONOSTICDIALOG_H
