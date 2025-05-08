#ifndef LMSTIMER_H
#define LMSTIMER_H

#include "arduino.h"
class LMSTIMER : public arduino
{
    Q_OBJECT

public:
    explicit LMSTIMER(QObject *parent = nullptr)
        : arduino()
    {
        this->setParent(parent);
    }


    int connect() { return connect_arduino(QSerialPort::Baud9600); }

signals:
    void timerSignal(int value);

private slots:
   // void extracted();
    void onRaw(const QByteArray raw);

public :
    int begin() {
        int r = connect();
        if (r==0) QObject::connect(this, &arduino::dataReceived, this, &LMSTIMER::onRaw);
        return r;
    }

};

#endif // LMSTIMER_H
