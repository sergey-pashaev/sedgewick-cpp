// ex.3.30

// en: Use Program 3.9 to plot the Josephus function versus N for M =
// 10 and N from 2 to 1000.

// ru: Используйте программу 3.9, чтобы построить график зависимости
// функции Иосифа от N для M = 10 и N от 2 до 1000.

#include <cstdlib>

#include <psv/cli_graph.h>

#include "josephus.h"

const int M = 10;
const int N_MIN = 2;
const int N_MAX = 1000;

int usage(const char* bin) {
    std::cout << "Usage: " << bin
              << " <positive int ROWS> <positive int COLS>\n";
    return 1;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        return usage(argv[0]);
    }

    // chart size
    int rows = std::atoi(argv[1]);
    int cols = std::atoi(argv[2]);

    psv::DrawCLIGraph(N_MIN, N_MAX, [](int n) { return josephus(n, M); }, 0,
                      N_MAX, rows, cols, "N", "Node number");

    return 0;
}
