#ifndef CUSTOMTEXTINPUT_H
#define CUSTOMTEXTINPUT_H

#include <QLineEdit>

class CustomTextInput : public QLineEdit {
    Q_OBJECT

public:
    explicit CustomTextInput(QWidget *parent = nullptr);

protected:
    void focusInEvent(QFocusEvent *event) override;
    void focusOutEvent(QFocusEvent *event) override;

private:
    void updateStyleSheet(bool focused);
};

#endif // CUSTOMTEXTINPUT_H
