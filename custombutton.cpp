#include "custombutton.h"
#include <QPainter>
#include <QMouseEvent>
#include <QEnterEvent> // Include this for QEnterEvent

CustomButton::CustomButton(QWidget *parent) : QPushButton(parent) {




    // Load textures for different button states
    normalTexture = QPixmap(":/textures/textures/button_normal.png");
    hoverTexture = QPixmap(":/textures/textures/button_hover.png");
    pressedTexture = QPixmap(":/textures/textures/button_pressed.png");

    if (normalTexture.isNull()) qDebug() << "Failed to load normal texture!";
    if (hoverTexture.isNull()) qDebug() << "Failed to load hover texture!";
    if (pressedTexture.isNull()) qDebug() << "Failed to load pressed texture!";

    // Ensure the button is initially in the normal state
    currentTexture = normalTexture;

    // Enable mouse tracking for hover effects
    setMouseTracking(true);
}

void CustomButton::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);

    QPainter painter(this);
    painter.drawPixmap(rect(), currentTexture);
}

void CustomButton::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        currentTexture = pressedTexture;
        update(); // Trigger a repaint
    }
    QPushButton::mousePressEvent(event);
}

void CustomButton::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        if (rect().contains(event->pos())) {
            currentTexture = hoverTexture; // Change to hover state when released
        } else {
            currentTexture = normalTexture; // Change to normal state if released outside
        }
        update(); // Trigger a repaint
    }
    QPushButton::mouseReleaseEvent(event);
}

void CustomButton::enterEvent(QEnterEvent *event) { // Updated signature
    Q_UNUSED(event);
    currentTexture = hoverTexture;
    update(); // Trigger a repaint
}

void CustomButton::leaveEvent(QEvent *event) {
    Q_UNUSED(event);
    currentTexture = normalTexture;
    update(); // Trigger a repaint
}
