// ex.3.21

// en: Modify Program 3.8 to print out the coordinates of the closest
// pair of points.

// ru: Измените программу 3.8 для вывода координат пары ближайших
// точек.

#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <limits>

#include "point.h"

float RandomFloat() { return 1.0 * std::rand() / RAND_MAX; }

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

    std::srand(std::time(nullptr));

    Point* a = new Point[N];
    for (int i = 0; i < N; ++i) {
        a[i].x = RandomFloat();
        a[i].y = RandomFloat();
    }

    int min_i = -1;
    int min_j = -1;
    float min_d = std::numeric_limits<float>::max();
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N - 1; ++j) {
            float d = Distance(a[i], a[j]);
            if (d < min_d) {
                min_d = d;
                min_i = i;
                min_j = j;
            }
        }
    }

    std::cout << a[min_i].x << ' ' << a[min_i].y << ", ";
    std::cout << a[min_j].x << ' ' << a[min_j].y << '\n';

    delete[] a;

    return 0;
}
