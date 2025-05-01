#include "lmspenalty.h"




void LMSPENALTY::onRaw(QByteArray raw) {
    QString s = QString::fromUtf8(raw).trimmed();
    if (s=="REDCARD")
        emit penaltySignal("REDCARD");

    if(s=="YELLOWCARD")
        emit penaltySignal("YELLOWCARD");


}
