#ifndef CHATBOT_H
#define CHATBOT_H

#include <QString>
#include "connection.h"

class Chatbot {
public:
    Chatbot(Connection* conn);
    ~Chatbot();

    QString getAnswer(const QString &question);
    QString handleGenericQuestions(const QString &question);

private:
    Connection* connection;
};

#endif // CHATBOT_H
