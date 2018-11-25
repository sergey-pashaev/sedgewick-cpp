// ex.3.22

// en: Modify Program 3.8 to perform the same computation in
// d dimensions.

// ru: Измените программу 3.8 для выполнения тех же вычислений в
// d-мерном пространстве.

#include <cassert>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

struct Point {
    explicit Point(int n) : d(n, 0.0) {}

    std::vector<float> d;
};

float Distance(const Point& a, const Point& b) {
    assert(a.d.size() == b.d.size());
    float sum = 0.0;
    for (size_t s = 0; s < a.d.size(); ++s) {
        sum += (a.d[s] - b.d[s]) * (a.d[s] - b.d[s]);
    }
    return std::sqrt(sum);
}

float RandomFloat() { return 1.0 * std::rand() / RAND_MAX; }

int usage(const char* bin) {
    std::cout << "Usage: " << bin
              << " <positive int N> <float radius R> <positive int D>\n";
    return 1;
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        return usage(argv[0]);
    }

    int N = std::atoi(argv[1]);
    float R = std::atof(argv[2]);
    int D = std::atoi(argv[3]);
    if (N <= 0 || D <= 0 || R <= 0.0) {
        return usage(argv[0]);
    }

    std::srand(std::time(nullptr));
    std::vector<Point> a(N, Point(D));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < D; ++j) {
            a[i].d[j] = RandomFloat();
        }
    }

    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N - 1; ++j) {
            if (Distance(a[i], a[j]) < R) cnt++;
        }
    }

    std::cout << cnt << " pairs inside radius " << R << '\n';

    return 0;
}
