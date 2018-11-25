// program.3.2

// en: Types of numbers

// ru: Типы чисел

#include <cmath>
#include <cstdlib>
#include <iostream>

typedef int Number;

Number RandNum() { return rand(); }

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

    float m1 = 0.0;
    float m2 = 0.0;

    for (int i = 0; i < N; ++i) {
        Number x = RandNum();
        m1 += ((float)x) / N;
        m2 += ((float)x * x) / N;
    }

    std::cout << "   avg: " << m1 << '\n';
    std::cout << "stddev: " << std::sqrt(m2 - m1 * m1) << '\n';
    return 0;
}
