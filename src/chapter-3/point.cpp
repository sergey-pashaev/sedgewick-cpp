#include "point.h"

#include <cassert>
#include <cmath>
#include <ostream>

std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << '(' << p.x << ", " << p.y << ')';
    return os;
}

float distance(Point a, Point b) {
    float dx = a.x - b.x;
    float dy = a.y - b.y;
    return std::sqrt(dx * dx + dy * dy);
}

bool is_collinear(Point p1, Point p2, Point p3, float epsilon) {
    assert(std::abs(p1.x) <= 1.0 && std::abs(p1.y) <= 1.0);
    assert(std::abs(p2.x) <= 1.0 && std::abs(p2.y) <= 1.0);
    assert(std::abs(p3.x) <= 1.0 && std::abs(p3.y) <= 1.0);

    // equation of line:
    // Ax + By + C = 0
    // (y1 - y2)x + (x2 - x1)y + (x1*y2 - x2*y1)
    const float A = p1.y - p2.y;
    const float B = p2.x - p1.x;
    const float C = p1.x * p2.y - p2.x * p1.y;

    // distance from point to line:
    // dist = abs(A * x0 + B * y1 + C) / sqrt(A^2 + B^2)
    float dist = std::abs(A * p3.x + B * p3.y + C) / std::sqrt(A * A + B * B);
    return dist < epsilon;
}
