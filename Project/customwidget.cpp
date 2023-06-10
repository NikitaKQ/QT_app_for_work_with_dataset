#include "customwidget.h"

CustomWidget::CustomWidget(QWidget* parent)
    : QWidget(parent)
{
    // Set the background color
    QPalette pal = palette();
    pal.setColor(QPalette::Window, Qt::blue);
    setAutoFillBackground(true);
    setPalette(pal);
}

void CustomWidget::paintEvent(QPaintEvent* event)
{
    QWidget::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    // Set the pen for drawing
    QPen pen(Qt::white, 3);
    painter.setPen(pen);

    // Calculate the center of the widget
    int centerX = width() / 2;
    int centerY = height() / 2;

    // Draw the fork
    int forkLength = 80;
    int forkHeight = 10;
    int forkSpacing = 10;

    painter.drawLine(centerX - 25, centerY - forkLength / 2, centerX - 25, centerY + forkLength / 2);
    painter.drawLine(centerX - forkHeight - 25, centerY - forkLength / 2, centerX + forkHeight - 25, centerY - forkLength / 2);
    painter.drawLine(centerX - forkSpacing - 25, centerY - forkLength / 2, centerX - forkSpacing - 25, centerY - forkLength / 2 - forkHeight);
    painter.drawLine(centerX + forkSpacing - 25, centerY - forkLength / 2, centerX + forkSpacing - 25, centerY - forkLength / 2 - forkHeight);
    painter.drawLine(centerX - 25, centerY - forkLength / 2, centerX - 25, centerY - forkLength / 2 - forkHeight);

    // Draw the spoon
    int spoonLength = 80;
    int spoonHeight = 20;
    int spoonRadius = 15;

    painter.drawLine(centerX + 25, centerY - spoonLength / 2, centerX + 25, centerY + spoonLength / 2);
    painter.setBrush(Qt::GlobalColor::white);
    painter.drawEllipse(QPointF(centerX + 25, centerY - spoonLength / 2), spoonRadius - 2, spoonRadius);
    painter.setBrush(Qt::GlobalColor::gray);
    painter.drawEllipse(QPointF(centerX + 25, centerY - spoonLength / 2), spoonRadius - 2.5, spoonRadius - 0.5);
}


