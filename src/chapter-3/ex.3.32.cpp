// ex.3.32

// en: Develop a version of Program 3.9 that uses an array of indices
// to implement the linked list (see Figure 3.6).

// ru: Разработайте версию программы 3.9, в которой для реализации
// связного списка используется массив индексов (см. рис. 3.6).

#include <cstdlib>
#include <iostream>

struct Node {
    int item;
    Node* next;

    Node(int x, Node* t) : item(x), next(t) {}
};

typedef Node* Link;

int usage(const char* bin) {
    std::cout << "Usage: " << bin << " <positive int N> <positive int M>\n";
    return 1;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        return usage(argv[0]);
    }

    int N = std::atoi(argv[1]);
    int M = std::atoi(argv[2]);
    if (N <= 0 || M <= 0) {
        return usage(argv[0]);
    }

    int* item = new int[N];
    int* next = new int[N];

    for (int i = 0; i < N; ++i) {
        item[i] = i + 1;
        next[i] = i + 1;
    }

    // make cyclic
    next[N - 1] = 0;

    int i = 0;
    while (next[i] != i) {
        // move to node before node to delete to
        for (int j = 1; j < M - 1; ++j) i = next[i];

        // delete next node
        next[i] = next[next[i]];

        // move to next node after deleted
        i = next[i];
    }

    std::cout << item[i] << '\n';

    delete[] item;
    delete[] next;

    return 0;
}
