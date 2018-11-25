// program.3.4

// en: Point data type implementation

// ru: Реализация структуры данных point

#include <cmath>

#include "program.3.3.h"

float Distance(point a, point b) {
    float dx = a.x - b.x;
    float dy = a.y - b.y;
    return std::sqrt(dx * dx + dy * dy);
}
