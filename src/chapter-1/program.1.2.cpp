// program.1.2

// en: Quick-union solution to connectivity problem
// ru: Решение задачи связности методом быстрого объединения

#include <array>
#include <iostream>

static const int N = 1000;

int main() {
    std::array<int, N> id;
    for (int i = 0; i < N; ++i) id[i] = i;

    int p, q;
    while (std::cin >> p >> q) {
        // find
        int i, j;
        for (i = p; i != id[i]; i = id[i])
            ;
        for (j = q; j != id[j]; j = id[j])
            ;
        if (i == j) continue;

        // quick union
        id[i] = j;

        std::cout << ' ' << p << ' ' << q << '\n';
    }

    return 0;
}
