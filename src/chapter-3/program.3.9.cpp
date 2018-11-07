// program.3.9

// en: Circular list example (Josephus problem)

// ru: Пример циклического списка (задача Иосифа)

#include <cstdlib>
#include <iostream>

struct node {
    int item;
    node* next;

    node(int x, node* t) : item(x), next(t) {}
};

typedef node* link;

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

    link t = new node(1, 0);
    t->next = t;
    link x = t;

    for (int i = 2; i <= N; ++i) {
        x = (x->next = new node(i, t));
    }

    while (x != x->next) {
        for (int i = 1; i < M; ++i) x = x->next;
        x->next = x->next->next;
    }

    std::cout << x->item << '\n';

    return 0;
}
