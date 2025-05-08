#ifndef CHATBOT_H
#define CHATBOT_H

#include <QString>
#include "connection.h"

class Chatbot {
public:
    Chatbot(connection* conn);
    ~Chatbot();

    QString getAnswer(const QString &question);
    QString handleGenericQuestions(const QString &question);

private:
    connection* dbConnection;  // Renamed to avoid conflict with 'connection'
};

#endif // CHATBOT_H
