#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "point.h"

struct Triangle {
    Point p1;
    Point p2;
    Point p3;

    float Area() const;

    friend std::ostream& operator<<(std::ostream&, const Triangle&);
};

#endif /* TRIANGLE_H */
