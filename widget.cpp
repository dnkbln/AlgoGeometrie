#include "widget.h"

#include "point2f.h"
#include "graphwidget.h"

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGroupBox>
#include <QLayout>
#include <QDoubleValidator>

#include <QMessageBox>

PointCircle::PointCircle(QWidget *parent)
    : QWidget(parent)
{
    graphic = new GraphWidget;

    createPointInput();
    createButton();

    inputLayout = new QVBoxLayout;
    inputLayout->addWidget(pkt1);
    inputLayout->addWidget(pkt2);
    inputLayout->addWidget(pkt3);
    inputLayout->addLayout(buttonLayout);

    mainLayout = new QHBoxLayout;
    mainLayout->addWidget(graphic);
    mainLayout->addLayout(inputLayout);

    setLayout(mainLayout);
    setWindowTitle(tr("PointCircle"));
    resize(480, 240);
}

PointCircle::~PointCircle()
{
}

void PointCircle::calculate()
{
    Point2f p1(pkt1x->text().toFloat(), pkt1y->text().toFloat());
    Point2f p2(pkt2x->text().toFloat(), pkt2y->text().toFloat());
    Point2f p3(pkt3x->text().toFloat(), pkt3y->text().toFloat());

//    std::string s = "Point 1: "+p1.toString()+"\nPoint 2: "+p2.toString()+"\nPoint 3: "+p3.toString();
//    QMessageBox::information(this, QString("SLOT-calculate"), QString(s.c_str()),
//                             QMessageBox::Ok);

    graphic->setNodes(p1, p2, p3);

    Point2f circleCenter;
    float radius = calculateCircle(circleCenter, p1, p2, p3);

    graphic->setCircle(circleCenter, radius);

    std::string s = "Center: "+circleCenter.toString()+"\nRadius: ";
    QString qs(s.c_str());
    qs.append(QString("%1").arg(radius));
    QMessageBox::information(this, QString("SLOT-calculate"), qs,
                             QMessageBox::Ok);
}

void PointCircle::createPointInput()
{
    validator = new QDoubleValidator(-10000.0, 10000.0, 3);

    pkt1 = new QGroupBox(tr("Punkt 1"));
    labelPkt1x = new QLabel("x");
    labelPkt1y = new QLabel("y");
    pkt1x = new QLineEdit;
    pkt1x->setValidator(validator);
    pkt1y = new QLineEdit;
    pkt1y->setValidator(validator);

    layoutPkt1 = new QGridLayout;
    layoutPkt1->addWidget(labelPkt1x, 0, 0);
    layoutPkt1->addWidget(pkt1x, 1, 0);
    layoutPkt1->addWidget(labelPkt1y, 0, 1);
    layoutPkt1->addWidget(pkt1y, 1, 1);

    pkt1->setLayout(layoutPkt1);

    pkt2 = new QGroupBox(tr("Punkt 2"));
    labelPkt2x = new QLabel("x");
    labelPkt2y = new QLabel("y");
    pkt2x = new QLineEdit;
    pkt2x->setValidator(validator);
    pkt2y = new QLineEdit;
    pkt2y->setValidator(validator);

    layoutPkt2 = new QGridLayout;
    layoutPkt2->addWidget(labelPkt2x, 0, 0);
    layoutPkt2->addWidget(pkt2x, 1, 0);
    layoutPkt2->addWidget(labelPkt2y, 0, 1);
    layoutPkt2->addWidget(pkt2y, 1, 1);

    pkt2->setLayout(layoutPkt2);

    pkt3 = new QGroupBox(tr("Punkt 3"));
    labelPkt3x = new QLabel("x");
    labelPkt3y = new QLabel("y");
    pkt3x = new QLineEdit;
    pkt3x->setValidator(validator);
    pkt3y = new QLineEdit;
    pkt3y->setValidator(validator);

    layoutPkt3 = new QGridLayout;
    layoutPkt3->addWidget(labelPkt3x, 0, 0);
    layoutPkt3->addWidget(pkt3x, 1, 0);
    layoutPkt3->addWidget(labelPkt3y, 0, 1);
    layoutPkt3->addWidget(pkt3y, 1, 1);

    pkt3->setLayout(layoutPkt3);
}

void PointCircle::createButton()
{
    calc = new QPushButton(tr("Calculate"));
    calc->connect(calc, SIGNAL(clicked()), this, SLOT(calculate()));
    exit = new QPushButton("Quit");
    exit->connect(exit, SIGNAL(clicked()), this, SLOT(close()));

    buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(calc);
    buttonLayout->addWidget(exit);
}
