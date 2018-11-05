#include "triangle.h"

#include <cmath>

float Triangle::Area() const {
    // S = 1/2 * abs ((x1 - x3)(y2 - y3) - (x2 - x3)(y1 - y3))
    return 0.5 * std::abs((p1.x - p3.x) * (p2.y - p3.y) -
                          (p2.x - p3.x) * (p1.y - p3.y));
}

std::ostream& operator<<(std::ostream& os, const Triangle& t) {
    os << '[';
    os << t.p1 << ' ';
    os << t.p2 << ' ';
    os << t.p3;
    os << ']';
    return os;
}
