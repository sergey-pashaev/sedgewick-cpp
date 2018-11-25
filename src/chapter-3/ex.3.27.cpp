// ex.3.27

// en: When building the list, Program 3.9 sets twice as many link
// values as it needs to because it maintains a circular list after
// each node is inserted. Modify the program to build the circular
// list without doing this extra work.

// ru: При построении списка программа 3.9 устанавливает в два раза
// больше ссылок, чем нужно, поскольку поддерживает цикличность списка
// после вставки каждого узла. Измените программу таким образом, чтобы
// циклический список создавался без выполнения этих лишних операций.

#include <cstdlib>
#include <iostream>

struct Node {
    int item;
    Node* next;

    Node(int x, Node* t) : item(x), next(t) {}
    explicit Node(int x) : item(x), next(nullptr) {}
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

    Link t = new Node(1);
    Link x = t;

    for (int i = 2; i <= N; ++i) {
        x = (x->next = new Node(i));
    }
    x->next = t;

    while (x != x->next) {
        for (int i = 1; i < M; ++i) x = x->next;
        x->next = x->next->next;
    }

    std::cout << x->item << '\n';

    return 0;
}
