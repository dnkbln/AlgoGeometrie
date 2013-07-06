#include "circle.h"

#include "graphwidget.h"

Circle::Circle(GraphWidget* graphWidget) : graph(graphWidget)
{
}

QRectF Circle::boundingRect() const
{
    QRect bounding(-5, -5, 10, 10);
    return bounding;
}

void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::black, 0));
    painter->drawEllipse(-1, -1, 2, 2);
}

