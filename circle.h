#ifndef CIRCLE_H
#define CIRCLE_H

#include <QGraphicsItem>
#include "point2f.h"

class GraphWidget;

class Circle : public QGraphicsItem
{
public:
    Circle(GraphWidget *graphWidget);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

public slots:
    void setCircle(const Point2f& p, float r);

private:
    GraphWidget *graph;
    Point2f center;
    float radius;

};

#endif // CIRCLE_H
