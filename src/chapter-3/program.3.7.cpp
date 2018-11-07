// program 3.7

// en: Coin-flipping simulation

// ru: Имитация подбрасывания монеты

#include <cstdlib>
#include <ctime>
#include <iostream>

int heads() { return std::rand() < RAND_MAX / 2; }

int usage(const char* bin) {
    std::cout << "Usage: " << bin << " <positive N> <positive M>\n";
    return 1;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        return usage(argv[0]);
    }

    int i, j, cnt;
    int N = std::atoi(argv[1]);
    int M = std::atoi(argv[2]);
    if (N <= 0 || M <= 0) {
        return usage(argv[0]);
    }

    std::srand(std::time(nullptr));

    int* f = new int[N + 1];
    for (j = 0; j <= N; ++j) f[j] = 0;

    for (i = 0; i < M; ++i, f[cnt]++)
        for (cnt = 0, j = 0; j <= N; ++j)
            if (heads()) ++cnt;

    for (j = 0; j <= N; ++j) {
        if (f[j] == 0) std::cout << '.';
        for (i = 0; i < f[j]; i += 10) std::cout << '*';
        std::cout << '\n';
    }

    delete[] f;

    return 0;
}
