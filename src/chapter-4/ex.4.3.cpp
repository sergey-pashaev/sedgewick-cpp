// ex.4.3

// en: Modify the point ADT implementation in Program 4.3 to represent
// points with polar coordinates.

// ru: В программе 4.3 модифицируйте реализацию АТД точки таким
// образом, чтобы точки были представлены полярными координатами.

#include <iostream>

#include <psv/point.h>

int main() {
    auto p = psv::PolarPoint<float>(psv::Point<float>(4.0, 3.0));
    std::cout << "D = " << p.distance() << '\n';
    return 0;
}
