#include "uianimationhelper.h"

UiAnimationHelper::UiAnimationHelper() {}

void UiAnimationHelper::fadeInWidget(QWidget *widget, int durationMs)
{
    if (!widget) return;
    widget->setVisible(true);

    QGraphicsOpacityEffect *opacityEffect = qobject_cast<QGraphicsOpacityEffect*>(widget->graphicsEffect());
    if (!opacityEffect) {
        opacityEffect = new QGraphicsOpacityEffect(widget);
        widget->setGraphicsEffect(opacityEffect);
    }

    QPropertyAnimation *animation = new QPropertyAnimation(opacityEffect, "opacity");
    animation->setDuration(durationMs);
    animation->setStartValue(0.0);
    animation->setEndValue(1.0);
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

void UiAnimationHelper::fadeOutWidget(QWidget *widget, int durationMs)
{


    if (!widget) return;

    QGraphicsOpacityEffect *opacityEffect = qobject_cast<QGraphicsOpacityEffect*>(widget->graphicsEffect());
    if (!opacityEffect) {
        opacityEffect = new QGraphicsOpacityEffect(widget);
        widget->setGraphicsEffect(opacityEffect);
    }

    QPropertyAnimation *animation = new QPropertyAnimation(opacityEffect, "opacity");
    animation->setDuration(durationMs);
    animation->setStartValue(1.0);
    animation->setEndValue(0.0);

    QObject::connect(animation, &QPropertyAnimation::finished, [widget]() {
        widget->setVisible(false);
    });

    animation->start(QAbstractAnimation::DeleteWhenStopped);


}

void UiAnimationHelper::bounceWidget(QWidget *widget, int durationMs, int bounceHeight)
{

    if (!widget) return;

    QPropertyAnimation *animation = new QPropertyAnimation(widget, "pos");
    animation->setDuration(durationMs);
    animation->setStartValue(widget->pos());
    animation->setKeyValueAt(0.5, widget->pos() - QPoint(0, bounceHeight));
    animation->setEndValue(widget->pos());
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start(QAbstractAnimation::DeleteWhenStopped);}

void UiAnimationHelper::slideInWidget(QWidget *widget, int durationMs, QPoint startOffset)
{
    if (!widget) return;

    QPoint finalPos = widget->pos();
    QPoint startPos = finalPos + startOffset;

    widget->move(startPos);
    widget->setVisible(true);

    QPropertyAnimation *animation = new QPropertyAnimation(widget, "pos");
    animation->setDuration(durationMs);
    animation->setStartValue(startPos);
    animation->setEndValue(finalPos);
    animation->setEasingCurve(QEasingCurve::OutCubic);
    animation->start(QAbstractAnimation::DeleteWhenStopped);


}
