#include "chatbotdialog.h"
#include "chatbot.h"
#include "connection.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QScrollArea>
#include <QLabel>
#include <QDateTime>
#include <QTextEdit>
#include <QTimer>
#include <QScrollBar>
#include <QGraphicsDropShadowEffect>
#include <QPropertyAnimation>
#include <QEasingCurve>
#include <QIcon>

ChatbotDialog::ChatbotDialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("ChatGPT Assistant");
    setStyleSheet("background-color: #FFFFFF;");

    Connection* connection = new Connection();
    chatbot = new Chatbot(connection);

    scrollArea = new QScrollArea(this);
    scrollArea->setStyleSheet("background-color: #FFFFFF; border-radius: 15px;");
    chatWidget = new QWidget(this);
    chatLayout = new QVBoxLayout(chatWidget);
    chatLayout->setAlignment(Qt::AlignTop);
    chatLayout->setContentsMargins(20, 20, 20, 20);
    chatLayout->setSpacing(15);
    chatWidget->setLayout(chatLayout);

    scrollArea->setWidget(chatWidget);
    scrollArea->setWidgetResizable(true);
    scrollArea->setMinimumHeight(400);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    questionInput = new QLineEdit(this);
    questionInput->setPlaceholderText("Tapez votre message...");
    questionInput->setStyleSheet(R"(
        QLineEdit {
            background: #FFFFFF;
            border: 2px solid #FF4C4C;
            border-radius: 25px;
            padding: 12px 20px;
            font-size: 16px;
            color: #333333;
        }
        QLineEdit:focus {
            border-color: #FF4C4C;
        }
    )");

    sendButton = new QPushButton(QIcon(":/textures/send_icon.png"), "Envoyer", this);
    sendButton->setStyleSheet(R"(
        QPushButton {
            background-color: #FF4C4C;
            color: white;
            border: none;
            border-radius: 25px;
            padding: 12px 24px;
            font-weight: bold;
            min-width: 80px;
        }
        QPushButton:hover {
            background-color: #D43F3F;
        }
    )");
    sendButton->setCursor(Qt::PointingHandCursor);

    QHBoxLayout* inputLayout = new QHBoxLayout();
    inputLayout->addWidget(questionInput);
    inputLayout->addWidget(sendButton);
    inputLayout->setSpacing(10);
    inputLayout->setContentsMargins(0, 15, 0, 0);

    QHBoxLayout* headerLayout = new QHBoxLayout();
    QLabel* logoLabel = new QLabel();
    QPixmap logoPixmap(":/textures/app_icon.png");
    logoPixmap = logoPixmap.scaled(40, 40, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    logoLabel->setPixmap(logoPixmap);

    QLabel* titleLabel = new QLabel("FlamBot – Your Footy Assistant");
    titleLabel->setStyleSheet("font-size: 22px; font-weight: bold; color: #FF4C4C;");
    headerLayout->addWidget(logoLabel);
    headerLayout->addWidget(titleLabel);
    headerLayout->setSpacing(12);
    headerLayout->setAlignment(Qt::AlignLeft);

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(headerLayout);
    mainLayout->addWidget(scrollArea);
    mainLayout->addLayout(inputLayout);
    mainLayout->setContentsMargins(20, 20, 20, 20);
    mainLayout->setSpacing(15);

    setLayout(mainLayout);
    resize(800, 600);

    connect(sendButton, &QPushButton::clicked, this, &ChatbotDialog::sendMessage);
    connect(questionInput, &QLineEdit::returnPressed, this, &ChatbotDialog::sendMessage);
}

ChatbotDialog::~ChatbotDialog()
{
    delete chatbot;
}

void ChatbotDialog::sendMessage()
{
    QString question = questionInput->text().trimmed();
    if (question.isEmpty()) return;

    addMessageBubble(question, true);
    questionInput->clear();

    QWidget* typingWidget = addMessageBubble("...", false);

    QTimer::singleShot(600, [=]() {
        QString response = chatbot->getAnswer(question);
        typingWidget->deleteLater();
        addMessageBubble(response, false);
        scrollToBottom();
    });
}

QWidget* ChatbotDialog::addMessageBubble(const QString& message, bool isUser)
{
    QWidget* messageContainer = new QWidget();
    QVBoxLayout* containerLayout = new QVBoxLayout(messageContainer);
    containerLayout->setContentsMargins(0, 0, 0, 0);
    containerLayout->setSpacing(5);

    if (!isUser) {
        QLabel* nameLabel = new QLabel("FlamBot");
        nameLabel->setStyleSheet("font-weight: bold; font-size: 13px; color: #FF4C4C;");
        containerLayout->addWidget(nameLabel, 0, Qt::AlignLeft);
    }

    QLabel* bubble = new QLabel(message);
    bubble->setWordWrap(true);  // Permet de couper les lignes automatiquement
    bubble->setTextInteractionFlags(Qt::TextSelectableByMouse);
    bubble->setContentsMargins(12, 12, 12, 12);
    bubble->setAlignment(Qt::AlignLeft | Qt::AlignTop);  // Pour que le texte commence en haut à gauche

    if (isUser) {
        bubble->setStyleSheet(R"(
            QLabel {
                background-color: #FF4C4C;
                color: white;
                font-size: 15px;
                border-radius: 18px;
                padding: 12px;
                border: none;
                min-width: 250px;
                max-width: 500px;
            }
        )");
    } else {
        bubble->setStyleSheet(R"(
            QLabel {
                background-color: #F1F1F1;
                color: black;
                font-size: 15px;
                border-radius: 18px;
                padding: 12px;
                border: none;
                min-width: 250px;
                max-width: 500px;
            }
        )");
    }

    QGraphicsDropShadowEffect* shadow = new QGraphicsDropShadowEffect();
    shadow->setBlurRadius(15);
    shadow->setColor(QColor(0, 0, 0, 25));
    shadow->setOffset(0, 3);
    bubble->setGraphicsEffect(shadow);

    QLabel* timestamp = new QLabel(QDateTime::currentDateTime().toString("hh:mm AP"));
    timestamp->setStyleSheet("color: #888888; font-size: 10px;");
    timestamp->setAlignment(isUser ? Qt::AlignRight : Qt::AlignLeft);

    containerLayout->addWidget(bubble, 0, isUser ? Qt::AlignRight : Qt::AlignLeft);
    containerLayout->addWidget(timestamp, 0, isUser ? Qt::AlignRight : Qt::AlignLeft);

    QHBoxLayout* messageLayout = new QHBoxLayout();
    messageLayout->setContentsMargins(0, 0, 0, 0);

    if (isUser) {
        messageLayout->addStretch();
        messageLayout->addWidget(messageContainer);
    } else {
        messageLayout->addWidget(messageContainer);
        messageLayout->addStretch();
    }

    chatLayout->addLayout(messageLayout);
    scrollToBottom();

    return messageContainer; // <-- RETURN pour pouvoir le supprimer plus tard
}
void ChatbotDialog::scrollToBottom()
{
    QTimer::singleShot(50, [=]() {
        QScrollBar* scrollBar = scrollArea->verticalScrollBar();
        QPropertyAnimation* animation = new QPropertyAnimation(scrollBar, "value");
        animation->setDuration(300);
        animation->setStartValue(scrollBar->value());
        animation->setEndValue(scrollBar->maximum());
        animation->setEasingCurve(QEasingCurve::OutQuad);
        animation->start(QAbstractAnimation::DeleteWhenStopped);
    });
}
