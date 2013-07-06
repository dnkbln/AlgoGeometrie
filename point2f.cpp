#include "point2f.h"

#include <vector>
#include <algorithm>
#include <ostream>

int solve( std::vector<std::vector<float> >& m, std::vector<float>& b)
{
    if (m.size() != b.size())
        return 1;

    int size = m.size();

    for (int i=0; i<size; ++i) {
        for (int j=i+1; j<size; ++j) {
            b[j] = b[j] - b[i] * m[j][i] / m[i][i];
            for (int k=size-1; k>=i; --k) {
                m[j][k] = m[j][k]-m[i][k]*m[j][i] / m[i][i];
            }
        }
    }

    for (int j=size-1; j>=0; --j) {
        float t=0.f;
        for (int k=j+1; k<size; ++k)
            t = t + m[j][k] * b[k];
        if (fabs(m[j][j]) < 0.0001)
            return 1;
        b[j] = (b[j] - t) / m[j][j];
    }

    return 0;
}

float calculateCircle(Point2f &circleCenter, const Point2f &p1, const Point2f &p2, const Point2f &p3)
{
    float radius = -1.f;

    std::vector< std::vector < float > > m;
    std::vector<float> b(3);

    b[0] = 1.f;
    b[1] = -2.f*p1.x();
    b[2] = -2.f*p1.y();
    m.push_back(b);
    b[1] = -2.f*p2.x();
    b[2] = -2.f*p2.y();
    m.push_back(b);
    b[1] = -2.f*p3.x();
    b[2] = -2.f*p3.y();
    m.push_back(b);

    b[0] = -(p1.x()*p1.x()+p1.y()*p1.y());
    b[1] = -(p2.x()*p2.x()+p2.y()*p2.y());
    b[2] = -(p3.x()*p3.x()+p3.y()*p3.y());

    if (solve(m, b) != 0)
        return radius;

    circleCenter = Point2f(b[1], b[2]);
    radius = sqrt(b[1]*b[1]+b[2]*b[2]-b[0]);

    return radius;
}
