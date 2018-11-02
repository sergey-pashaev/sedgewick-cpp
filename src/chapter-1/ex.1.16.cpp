// ex.1.16

// en: Show how to modify Program 1.3 to implement fullpath
// compression, where we complete each union operation by making every
// node that we touch point to the root of the new tree.

// ru: Покажите как необходимо изменить программу 1.3, чтобы
// реализовать полное сжатие пути, при котором после каждой операции
// объединение все обработанные узлы указывают на корень нового
// дерева.

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
        int root;
        if (sz[i] < sz[j]) {
            id[i] = j;
            sz[j] += sz[i];
            root = j;
        } else {
            id[j] = i;
            sz[i] += sz[j];
            root = i;
        }

        // path compression
        i = p;
        while (i != id[i]) {
            int parent = id[i];
            id[i] = root;
            i = parent;
        }

        j = q;
        while (j != id[j]) {
            int parent = id[j];
            id[j] = root;
            j = parent;
        }

        std::cout << ' ' << p << ' ' << q << '\n';
    }

    return 0;
}
