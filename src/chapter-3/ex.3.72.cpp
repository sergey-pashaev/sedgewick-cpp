// ex.3.72

// en: Modify Program 3.19 to take the number of vertices as a
// command-line argument, then dynamically allocate the array of
// lists.

// ru: Измените программу 3.19 таким образом, чтобы она принимала
// количество вершин в качестве аргумента командной строки, а затем
// динамически выделяла память под массив списков.

#include <iostream>

struct Node {
    int v;
    Node* next;

    Node(int v, Node* next) : v(v), next(next) {}
};

typedef Node* Link;

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

    int i, j;
    auto adj = new Link[V];
    for (i = 0; i < V; ++i) {
        adj[i] = 0;
    }

    while (std::cin >> i >> j) {
        adj[j] = new Node(i, adj[j]);
        adj[i] = new Node(j, adj[i]);
    }

    for (i = 0; i < V; ++i) {
        for (Link cur = adj[i]; cur; cur = cur->next) {
            std::cout << i << '-' << cur->v << (cur->next ? ' ' : '\n');
        }
    }

    for (i = 0; i < V; ++i) {
        Link cur = adj[i];
        while (cur) {
            Link next = cur->next;
            delete cur;
            cur = next;
        }
    }

    delete[] adj;
}
