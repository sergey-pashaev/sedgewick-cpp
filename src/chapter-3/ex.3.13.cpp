// ex.3.13

// en: Use the sieve of Eratosthenes to draw a plot of N versus the
// number of primes less than N for N between 1 and 1000.

// ru: С помощью решета Эратосфена постройте график зависимост от N
// количества простых чисел, меньших N, для значений N от 1 до 1000

#include <cstdint>
#include <iomanip>
#include <iostream>
#include <vector>

#include "eratosthenes.h"

int usage(const char* bin) {
    std::cout
        << "Usage: " << bin
        << " <positive int N> <positive int MAX_X> <positive int MAX_Y>\n";
    return 1;
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        return usage(argv[0]);
    }

    int N = std::atoi(argv[1]);

    // chart size
    int max_x = std::atoi(argv[2]);
    int max_y = std::atoi(argv[3]);

    int* a = new int[N];
    for (int n = 1; n <= N; ++n) {
        a[n - 1] = prime_numbers_count(n);
    }

    for (int x = 1; x <= N; x += N / max_x) {
        std::cout << std::setw(4) << x - 1 << ' ';
        for (int y = 0; y <= a[x - 1]; y += a[N - 1] / max_y) {
            std::cout << '*';
        }
        std::cout << ' ' << a[x - 1] << '\n';
    }

    delete[] a;

    return 0;
}
