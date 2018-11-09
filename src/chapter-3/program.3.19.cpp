// program.3.19

// en: Adjacency-lists graph representation

// ru: Представление графа в виде списков смежности

#include <iostream>

struct node {
    int v;
    node* next;

    node(int v, node* next) : v(v), next(next) {}
};

typedef node* link;

int main() {
    const int V = 10;
    int i, j;
    link adj[V];

    for (i = 0; i < V; ++i) {
        adj[i] = 0;
    }

    while (std::cin >> i >> j) {
        adj[j] = new node(i, adj[j]);
        adj[i] = new node(j, adj[i]);
    }

    for (i = 0; i < V; ++i) {
        for (link cur = adj[i]; cur; cur = cur->next) {
            std::cout << i << '-' << cur->v << (cur->next ? " " : "\n");
        }
    }
}
