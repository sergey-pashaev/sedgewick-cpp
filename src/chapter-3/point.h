#ifndef POINT_H
#define POINT_H

#include <cmath>
#include <ostream>

struct Point {
    float x;
    float y;

    friend std::ostream& operator<<(std::ostream&, const Point&);
};

std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << '(' << p.x << ", " << p.y << ')';
    return os;
}

float distance(Point a, Point b) {
    float dx = a.x - b.x;
    float dy = a.y - b.y;
    return std::sqrt(dx * dx + dy * dy);
}

#endif /* POINT_H */
