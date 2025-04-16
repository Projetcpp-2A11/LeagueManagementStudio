#ifndef CHATBOTDIALOG_H
#define CHATBOTDIALOG_H

#include <QDialog>
#include <QLabel>

class QTextEdit;
class QLineEdit;
class QPushButton;
class Chatbot;
class Connection;
class QVBoxLayout;
class QScrollArea;
class QWidget;

class ChatbotDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChatbotDialog(QWidget *parent = nullptr);
    ~ChatbotDialog();

private:
    QWidget* chatWidget;
    QVBoxLayout* chatLayout;
    QScrollArea* scrollArea;
    QLineEdit* questionInput;
    QPushButton* sendButton;
    QLabel* typingLabel;
    Chatbot* chatbot;

    void scrollToBottom();
    void sendMessage();
    QWidget* addMessageBubble(const QString& message, bool isUser); // ✅ Corrigé ici
};

#endif // CHATBOTDIALOG_H
