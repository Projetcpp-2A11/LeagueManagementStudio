#ifndef DIALOGPRONOSTIC_H
#define DIALOGPRONOSTIC_H

#include <QObject>
#include <QDateTime>
#include <QWidget>

class DialogPronostic
{
public:
    static void ShowPronostic(int matchID, QWidget *parent = nullptr);

private:
    static QString getStadiumName(int stadiumID); // Nouvelle méthode

    static QString getTeamName(int teamID);
    static QString calculateTeamForm(int teamID, const QDateTime& date);
    static void calculateOdds(const QString& form1, const QString& form2,
                              float& cote1, float& coteX, float& cote2);
};

#endif // DIALOGPRONOSTIC_H
