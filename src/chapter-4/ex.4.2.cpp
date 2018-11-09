// ex.4.2

// en: Add a member function to the point class in Program 4.3 that
// returns the distance to the origin.

// ru: Добавьте в класс точки (программа 4.3) функцию-член, которая
// возвращает расстояние до начала координат.

#include <iostream>

#include <psv/point.h>

int main() {
    auto p = psv::Point<float>(4.0, 3.0);
    std::cout << "D = " << p.distance() << '\n';
    return 0;
}
