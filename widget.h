#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class QLabel;
class QLineEdit;
class QPushButton;
class QGroupBox;

class QDoubleValidator;

class QGridLayout;
class QHBoxLayout;
class QVBoxLayout;

class GraphWidget;

class PointCircle : public QWidget
{
    Q_OBJECT
    
public:
    PointCircle(QWidget *parent = 0);
    ~PointCircle();

private slots:
    void calculate();

private:

    void createPointInput();
    void createButton();

    GraphWidget *graphic;

    QDoubleValidator *validator;

    QGroupBox *pkt1;
    QGridLayout *layoutPkt1;
    QLabel *labelPkt1x;
    QLabel *labelPkt1y;
    QLineEdit *pkt1x;
    QLineEdit *pkt1y;

    QGroupBox *pkt2;
    QGridLayout *layoutPkt2;
    QLabel *labelPkt2x;
    QLabel *labelPkt2y;
    QLineEdit *pkt2x;
    QLineEdit *pkt2y;

    QGroupBox *pkt3;
    QGridLayout *layoutPkt3;
    QLabel *labelPkt3x;
    QLabel *labelPkt3y;
    QLineEdit *pkt3x;
    QLineEdit *pkt3y;

    QPushButton *exit;
    QPushButton *calc;

    QHBoxLayout *mainLayout;
    QVBoxLayout *inputLayout;
    QHBoxLayout *buttonLayout;
};

#endif // WIDGET_H
