#include "lmstimer.h"
#include "qdebug.h"


void LMSTIMER::onRaw(const QByteArray raw) {

    QStringList lines = QString::fromUtf8(raw)
                            .trimmed()
                            .split('\n', Qt::SkipEmptyParts);

    for (const QString &line : lines) {
        // 2. Check that it starts with your prefix
        if (!line.startsWith("num:")) {
            qWarning() << "LMSTIMER: unexpected message:" << line;
            continue;
        }

        // 3. Extract the substring after "num:"
        QString numPart = line.mid(QStringLiteral("num:").length()).trimmed();

        // 4. Convert to int
        bool ok = false;
        int value = numPart.toInt(&ok);
        if (!ok) {
            qWarning() << "LMSTIMER: failed to convert number from:" << numPart;
            continue;
        }

        // 5. Emit the high-level signal
        emit timerSignal(value);
    }
}
