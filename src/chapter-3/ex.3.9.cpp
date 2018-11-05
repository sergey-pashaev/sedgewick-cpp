// ex.3.9

// en: Define a data type for triangles in the unit square, including
// a function that computes the area of a triangle. Then write a
// client program that generates random triples of pairs of floats
// between 0 and 1 and computes the average area of the triangles
// generated.

// ru: Определите тип данных для треугольников, находящихся в
// единичном квадрате, включая функцию вычисления площади
// треугольника. Затем напишите клиентскую программу, которая
// генерирует случайные тройки пар чисел с плавающей точкой от 0 до 1
// и вычисляет среднюю площадь сгенерированных треугольников.

#include <iostream>
#include <random>

#include "triangle.h"

int usage(const char* bin) {
    std::cout << "Usage: " << bin << " <positive number N>\n";
    return 1;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        return usage(argv[0]);
    }

    int N = std::atoi(argv[1]);
    if (N <= 0) {
        return usage(argv[0]);
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dist(0, 1.0);
    float avg = 0;
    for (int i = 0; i < N; ++i) {
        Triangle t = {{dist(gen), dist(gen)},
                      {dist(gen), dist(gen)},
                      {dist(gen), dist(gen)}};
        std::cout << t << " area: " << t.Area() << '\n';
        avg += t.Area() / N;
    }

    std::cout << "average area: " << avg << '\n';
    return 0;
}
