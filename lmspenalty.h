#ifndef LMSPENALTY_H
#define LMSPENALTY_H

#include "arduino.h"
class LMSPENALTY : public arduino
{
    Q_OBJECT

public:
    explicit LMSPENALTY(QObject *parent = nullptr)
        : arduino()
    {
        this->setParent(parent);
    }


    int connect() { return connect_arduino(QSerialPort::Baud9600); }

signals:
    void penaltySignal(QString payload);

private slots:
    void onRaw(QByteArray raw);

public :
    int begin() {
        int r = connect();
        if (r==0) QObject::connect(this, &arduino::dataReceived, this, &LMSPENALTY::onRaw);
        return r;
    }

};

#endif // LMSPENALTY_H
