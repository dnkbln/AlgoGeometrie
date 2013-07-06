#ifndef GRAPHWIDGET_H
#define GRAPHWIDGET_H

#include "point2f.h"

#include <QGraphicsView>

class Node;
class Circle;

class GraphWidget : public QGraphicsView
{
    Q_OBJECT

public:
    GraphWidget(QWidget *parent = 0);
    void setNodes( const Point2f& p1, const Point2f& p2, const Point2f& p3);
    void setCircle(const Point2f& p, float radius);

private:

    Node *node1;
    Node *node2;
    Node *node3;
    Node *center;
    Circle *circle;
};


#endif // GRAPHWIDGET_H
