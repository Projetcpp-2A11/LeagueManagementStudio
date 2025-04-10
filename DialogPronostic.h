#ifndef DIALOGPRONOSTIC_H
#define DIALOGPRONOSTIC_H

#include <QObject>
#include <QDateTime>

class DialogPronostic
{
public:
    static void ComputeAndDebug(int matchID);

private:
    static QString getTeamName(int teamID);
    static QString calculateTeamForm(int teamID, const QDateTime& date);
    static void calculateOdds(const QString& form1, const QString& form2,
                              float& cote1, float& coteX, float& cote2);
};

#endif // DIALOGPRONOSTIC_H
