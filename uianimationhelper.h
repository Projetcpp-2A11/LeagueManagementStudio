#ifndef UIANIMATIONHELPER_H
#define UIANIMATIONHELPER_H

#include "qwidget.h"
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>

class UiAnimationHelper
{
public:
    UiAnimationHelper();
    static void fadeInWidget(QWidget *widget, int durationMs);
    static void fadeOutWidget(QWidget *widget, int durationMs);
    static void bounceWidget(QWidget *widget, int durationMs, int bounceHeight = 20);
    static void slideInWidget(QWidget *widget, int durationMs, QPoint startOffset);
};

#endif // UIANIMATIONHELPER_H
