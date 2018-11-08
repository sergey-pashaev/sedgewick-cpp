// ex.3.42

// en: Implement a version of Program 3.9 that uses a head node.

// ru: Реализуйте версию программы 3.9, в которой используется ведущий
// узел.

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

    link head = new node(0, nullptr);
    link x = head;

    for (int i = 1; i <= N; ++i) {
        x = (x->next = new node(i, head->next));
    }

    for (x = head->next; x->next != x;) {
        for (int i = 0; i < M; ++i) x = x->next;
        x->next = x->next->next;
    }

    std::cout << x->item << '\n';

    return 0;
}
