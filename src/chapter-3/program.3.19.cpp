// program.3.19

// en: Adjacency-lists graph representation

// ru: Представление графа в виде списков смежности

#include <iostream>

struct Node {
    int v;
    Node* next;

    Node(int v, Node* next) : v(v), next(next) {}
};

typedef Node* Link;

int main() {
    const int V = 10;
    int i, j;
    Link adj[V];

    for (i = 0; i < V; ++i) {
        adj[i] = 0;
    }

    while (std::cin >> i >> j) {
        adj[j] = new Node(i, adj[j]);
        adj[i] = new Node(j, adj[i]);
    }

    for (i = 0; i < V; ++i) {
        for (Link cur = adj[i]; cur; cur = cur->next) {
            std::cout << i << '-' << cur->v << (cur->next ? " " : "\n");
        }
    }
}
