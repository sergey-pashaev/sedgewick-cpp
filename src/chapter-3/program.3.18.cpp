// program.3.18

// en: Adjacency-matrix graph representation

// ru: Представление графа в виде матрицы смежности

#include <iostream>

int main() {
    const int V = 10;
    int i, j;
    int adj[V][V];

    for (i = 0; i < V; ++i) {
        for (j = 0; j < V; ++j) {
            adj[i][j] = 0;
        }
    }

    for (i = 0; i < V; ++i) adj[i][i] = 1;

    while (std::cin >> i >> j) {
        adj[i][j] = 1;
        adj[j][i] = 1;
    }

    for (i = 0; i < V; ++i) {
        for (j = 0; j < V; ++j) {
            std::cout << adj[i][j] << (j + 1 < V ? " " : "");
        }
        std::cout << '\n';
    }
}
