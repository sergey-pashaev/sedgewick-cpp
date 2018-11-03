// ex.3.7

// en: Write a client program that uses the data type in Programs 3.3
// and 3.4 for the following task: Read a sequence of points (pairs of
// floating-point numbers) from standard input, and find the one that
// is closest to the first.

// ru: Напишите клиентскую программу, которая использует типа данных
// из программ 3.3, и 3.4, для следующей задачи: чтение
// последовательности точек (пар чисел с плавающей точкой) из
// стандартного устройства ввода и поиск точки, ближайшей к первой.

#include <cmath>
#include <iostream>
#include <limits>

#include "point.h"

int main() {
    Point first;
    std::cin >> first.x >> first.y;
    float min_distance = std::numeric_limits<float>::max();

    Point cur;
    Point closest;
    while (std::cin >> cur.x >> cur.y) {
        if (distance(first, cur) < min_distance) {
            closest = cur;
        }
    }

    std::cout << distance(first, closest) << ' ' << closest.x << ' '
              << closest.y << '\n';

    return 0;
}
