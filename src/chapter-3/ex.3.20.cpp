// ex.3.20

// en: Modify Program 3.7 to simulate a situation where the coin turns
// up heads with probability λ/N. Run 1000 trials for an experiment
// with 32 flips to get output that you can compare with Figure
// 3.2. This distribution is the classical Poissondistribution.

// ru: Измените программу 3.7 для имитации случая, когда решка
// выпадает с вероятностью λ/N. Выполните 1000 испытаний с 32
// подбрасываниями получения выходных данных, которые можно сравнить с
// рис.3.2. Получается классическое распределение Пуассона.

#include <cstdlib>
#include <ctime>
#include <iostream>

int Heads(int N, int lambda) { return std::rand() < (RAND_MAX / N) * lambda; }

int usage(const char* bin) {
    std::cout << "Usage: " << bin
              << " <positive int N> <positive int M> <positive int L>\n";
    return 1;
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        return usage(argv[0]);
    }

    int i, j, cnt;
    int N = std::atoi(argv[1]);
    int M = std::atoi(argv[2]);
    int L = std::atoi(argv[3]);
    if (N <= 0 || M <= 0 || L <= 0) {
        return usage(argv[0]);
    }

    std::srand(std::time(nullptr));

    int* f = new int[N + 1];
    for (j = 0; j <= N; ++j) f[j] = 0;

    for (i = 0; i < M; ++i, f[cnt]++)
        for (cnt = 0, j = 0; j <= N; ++j)
            if (Heads(N, L)) ++cnt;

    for (j = 0; j <= N; ++j) {
        if (f[j] == 0) std::cout << '.';
        for (i = 0; i < f[j]; i += 10) std::cout << '*';
        std::cout << '\n';
    }

    delete[] f;

    return 0;
}
