// program.3.8

// en: Closest-point computation

// ru: Вычисление ближайшей точки

#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "point.h"

float RandomFloat() { return 1.0 * std::rand() / RAND_MAX; }

int usage(const char* bin) {
    std::cout << "Usage: " << bin << " <positive int N> <float radius R>\n";
    return 1;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        return usage(argv[0]);
    }

    int N = std::atoi(argv[1]);
    if (N <= 0) {
        return usage(argv[0]);
    }

    std::srand(std::time(nullptr));

    float R = std::atof(argv[2]);
    Point* a = new Point[N];
    for (int i = 0; i < N; ++i) {
        a[i].x = RandomFloat();
        a[i].y = RandomFloat();
    }

    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (Distance(a[i], a[j]) < R) cnt++;
        }
    }

    std::cout << cnt << " pairs inside radius " << R << '\n';

    delete[] a;

    return 0;
}
