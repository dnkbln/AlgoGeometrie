#ifndef POINT2F_H
#define POINT2F_H

#include <math.h>
#include <string>
#include <sstream>

class Point2f
{
public:

    Point2f() : x_(0.f), y_(0.f) {}
    Point2f(float x, float y) : x_(x), y_(y) {}

    float x() const {
        return x_;
    }

    float y() const {
        return y_;
    }

    float length() {
        return sqrt(x_*x_+y_*y_);
    }

    std::string toString() {
        std::stringstream s;
        s << "(" << x_ << "," << y_ << ")";
        return s.str();
    }

private:
    float x_;
    float y_;
};

/** Bestimmt aus 3 Punkten den Kreismittelpunkt und Radius der durch die
 *  3 Punkte verläuft.
 */
float calculateCircle(Point2f& circleCenter, const Point2f& p1, const Point2f& p2, const Point2f& p3);

#endif // POINT2F_H
