// ex.4.4

// en: Write a client program that takes an integer N from the command
// line, and fills an array with N points, no two of which are
// equal. Use the overloaded == operator described in the text to test
// equality.

// ru: Напишите клиентскую программ, которая считывает из командной
// строк целое число N и заполняет массив N точками, среди которых нет
// двух равных друг другу. Для проверки равенства или неравенства
// точек используйте перегруженную операцию ==, описанную в тексте
// настоящей главы.

#include <iostream>

#include <catch.hpp>

#include <psv/point.h>

int usage(const char* bin) {
    std::cout << "Usage: " << bin << " <positive int N>\n";
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

    auto a = std::vector<psv::Point<float>>();

    for (int i = 0; i < N; ++i) {
        a.push_back(psv::Point<float>::random());

        for (int j = 0; j < i; ++j) {
            if (a[i] == a[j]) {
                a[i] = psv::Point<float>::random();
                j = 0;  // start from beginning
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        std::cout << a[i] << (i + 1 < N ? ' ' : '\n');
    }

    return 0;
}
