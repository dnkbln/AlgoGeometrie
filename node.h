#ifndef NODE_H
#define NODE_H

#include <QGraphicsItem>

class GraphWidget;

class Node : public QGraphicsItem
{
public:
    Node(GraphWidget *graphWidget);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    GraphWidget *graph;
};


#endif // NODE_H
