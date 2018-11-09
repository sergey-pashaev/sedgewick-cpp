// ex.3.71

// en: Modify Program 3.18 to take the number of vertices as a
// command-line argument, then dynamically allocate the adjacency
// matrix.

// ru: Измените программу 3.18 таким образом, чтобы она принимала
// количество вершин в качестве аргумента командной строки, а затем
// динамически выделяла память под матрицу смежности.

#include <iostream>

#include <psv/array.h>

int usage(const char* bin) {
    std::cout << "Usage: " << bin << " <positive int V>\n";
    return 1;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        return usage(argv[0]);
    }

    const int V = std::atoi(argv[1]);
    if (V <= 0) {
        return usage(argv[0]);
    }

    auto adj = psv::Array2D<int>(V, V);
    int i, j;

    for (i = 0; i < V; ++i) {
        for (j = 0; j < V; ++j) {
            adj.data[i][j] = 0;
        }
    }

    for (i = 0; i < V; ++i) adj.data[i][i] = 1;

    while (std::cin >> i >> j) {
        adj.data[i][j] = 1;
        adj.data[j][i] = 1;
    }

    for (i = 0; i < V; ++i) {
        for (j = 0; j < V; ++j) {
            std::cout << adj.data[i][j] << (j + 1 < V ? ' ' : '\n');
        }
    }
}
