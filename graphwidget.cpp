#include "graphwidget.h"

#include "node.h"
#include "circle.h"

#include <QtGui>

GraphWidget::GraphWidget(QWidget *parent)
    : QGraphicsView(parent)
{
    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    scene->setSceneRect(-100, -100, 200, 200);
    setScene(scene);
    setCacheMode(CacheBackground);
    setViewportUpdateMode(BoundingRectViewportUpdate);
    setRenderHint(QPainter::Antialiasing);
    setTransformationAnchor(AnchorUnderMouse);
    setMinimumSize(200, 200);

    node1 = new Node(this);
    node2 = new Node(this);
    node3 = new Node(this);
    center = new Node(this);
    circle = new Circle(this);

    scene->addItem(node1);
    scene->addItem(node2);
    scene->addItem(node3);
    scene->addItem(center);
    scene->addItem(circle);
}

void GraphWidget::setNodes(const Point2f &p1, const Point2f &p2, const Point2f &p3)
{
    node1->setPos(p1.x(), -p1.y());
    node2->setPos(p2.x(), -p2.y());
    node3->setPos(p3.x(), -p3.y());
}

void GraphWidget::setCircle(const Point2f &p, float radius)
{
    center->setPos(p.x(), -p.y());
    circle->setScale(radius);
    circle->setPos(p.x(), -p.y());
}
