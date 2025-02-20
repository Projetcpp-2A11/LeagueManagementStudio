#ifndef CUSTOMBUTTON_H
#define CUSTOMBUTTON_H

#include <QPushButton>
#include <QPixmap>
#include <QEnterEvent> // Include this for QEnterEvent

class CustomButton : public QPushButton {
    Q_OBJECT

public:
    explicit CustomButton(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void enterEvent(QEnterEvent *event) override; // Updated signature
    void leaveEvent(QEvent *event) override;

private:
    QPixmap normalTexture;   // Texture for normal state
    QPixmap hoverTexture;    // Texture for hover state
    QPixmap pressedTexture;  // Texture for pressed state
    QPixmap currentTexture;  // Current texture to display
};

#endif // CUSTOMBUTTON_H
