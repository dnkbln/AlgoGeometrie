#include "node.h"

#include "graphwidget.h"

#include <QPainter>

Node::Node(GraphWidget* graphWidget) : graph(graphWidget)
{
    setFlag(ItemIsMovable);
}

QRectF Node::boundingRect() const
{
    QRect bounding(-5, -5, 10, 10);
    return bounding;
}

void Node::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::black, 0));
    painter->drawEllipse(-4, -4, 8, 8);
}

