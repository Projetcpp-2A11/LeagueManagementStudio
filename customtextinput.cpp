#include "customtextinput.h"
#include <QFocusEvent>

CustomTextInput::CustomTextInput(QWidget *parent) : QLineEdit(parent) {
    // Set initial stylesheet
    updateStyleSheet(false);
}

void CustomTextInput::focusInEvent(QFocusEvent *event) {
    updateStyleSheet(true); // Apply focused style
    QLineEdit::focusInEvent(event);
}

void CustomTextInput::focusOutEvent(QFocusEvent *event) {
    updateStyleSheet(false); // Apply unfocused style
    QLineEdit::focusOutEvent(event);
}

void CustomTextInput::updateStyleSheet(bool focused) {
    QString styleSheet =
        "QLineEdit {"
        "   background-color: red;" // Light green background
        "   color: white;"                   // Red text
        "   border: 2px solid gray;"       // Default border
        "   border-radius: 10px;"          // Rounded corners
        "   padding: 5px;"                 // Padding for text
        "}";

    if (focused) {
        styleSheet +=
            "QLineEdit:focus {"
            "   border: 2px solid blue;"   // Blue border when focused
            "}";
    }

    setStyleSheet(styleSheet);
}
