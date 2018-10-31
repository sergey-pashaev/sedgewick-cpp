// program.1.1

// en: Quick-find solution to connectivity problem
// ru: Решение задачи связности методом быстрого поиска

#include <array>
#include <iostream>

static const int N = 1000;

int main() {
    std::array<int, N> id;
    for (int i = 0; i < N; ++i) id[i] = i;

    int p, q;
    while (std::cin >> p >> q) {
        int t = id[p];
        if (t == id[q]) continue;

        for (int i = 0; i < N; ++i)
            if (id[i] == t) id[i] = id[q];

        std::cout << ' ' << p << ' ' << q << '\n';
    }

    return 0;
}
