#ifndef LMSVAR_H
#define LMSVAR_H

#include "arduino.h"

class LMSVAR : public arduino
{
    Q_OBJECT

public:
    explicit LMSVAR(QObject *parent = nullptr)
        : arduino()
    {
        this->setParent(parent);
    }


    int connect() { return connect_arduino(QSerialPort::Baud115200); }

signals:
    void varSignal(QString payload);

private slots:
    void onRaw(QByteArray raw) {
        QString s = QString::fromUtf8(raw).trimmed();
        if (s == "A")
            emit varSignal("A");

        if (s=="B")
            emit varSignal("B");

    }

public :
    int begin() {
        int r = connect();
        if (r==0) QObject::connect(this, &arduino::dataReceived, this, &LMSVAR::onRaw);
        return r;
    }

};

#endif // LMSVAR_H
