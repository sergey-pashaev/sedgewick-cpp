// ex.3.13

// en: Use the sieve of Eratosthenes to draw a plot of N versus the
// number of primes less than N for N between 1 and 1000.

// ru: С помощью решета Эратосфена постройте график зависимост от N
// количества простых чисел, меньших N, для значений N от 1 до 1000

#include <cstdint>
#include <iomanip>
#include <iostream>
#include <vector>

#include <psv/cli_graph.h>

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

    psv::DrawCLIGraph(1, N, PrimeNumbersCount, 0, PrimeNumbersCount(N), max_x,
                      max_y, "N", "primes");

    return 0;
}
