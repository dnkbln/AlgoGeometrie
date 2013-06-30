#include "widget.h"

PointCircle::PointCircle(QWidget *parent)
    : QWidget(parent)
{
    graphic = new QLabel(tr("Hier kommt später die Graphic hin"));
    graphic->setAlignment(Qt::AlignCenter);
    graphic->setMinimumSize(240, 160);

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
}

void PointCircle::createPointInput()
{
    pkt1 = new QGroupBox(tr("Punkt 1"));
    labelPkt1x = new QLabel("x");
    labelPkt1y = new QLabel("y");
    pkt1x = new QLineEdit;
    pkt1y = new QLineEdit;

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
    pkt2y = new QLineEdit;

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
    pkt3y = new QLineEdit;

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
