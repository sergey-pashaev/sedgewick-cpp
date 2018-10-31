// program.1.3

// en: Weighted version of quick union
// ru: Взвешенная версия быстрого объединения

#include <array>
#include <iostream>

static const int N = 1000;

int main() {
    std::array<int, N> id;
    std::array<int, N> sz;
    for (int i = 0; i < N; ++i) {
        id[i] = i;
        sz[i] = 1;
    }

    int p, q;
    while (std::cin >> p >> q) {
        // find
        int i, j;
        for (i = p; i != id[i]; i = id[i])
            ;
        for (j = q; j != id[j]; j = id[j])
            ;
        if (i == j) continue;

        // check size of tree & join with smallest
        if (sz[i] < sz[j]) {
            id[i] = j;
            sz[j] += sz[i];
        } else {
            id[j] = i;
            sz[i] += sz[j];
        }

        std::cout << ' ' << p << ' ' << q << '\n';
    }

    return 0;
}
