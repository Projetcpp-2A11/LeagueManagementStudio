#include "lmsvar.h"
#include "qdebug.h"


void LMSVAR::onRaw(QByteArray raw) {
    QString s = QString::fromUtf8(raw).trimmed();
    if (s == "A")
        emit varSignal("A");

    if (s=="B")
        emit varSignal("B");

    if (s.startsWith("SCORES ")) {
        QStringList parts = s.mid(7).split(" ");
        if (parts.size() == 2) {
            bool ok1, ok2;
            int teamAScore = parts[0].toInt(&ok1);
            int teamBScore = parts[1].toInt(&ok2);

            if (ok1 && ok2) {
                qDebug() << "Received Scores: A =" << teamAScore << ", B =" << teamBScore;
                emit scoresReceived(teamAScore,teamBScore);

            }
        }
    }

}
