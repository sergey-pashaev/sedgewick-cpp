// program.3.10

// en: List reversal

// ru: Обращение списка

#include <cstdlib>
#include <iostream>

struct node {
    int item;
    node* next;

    node(int x, node* t) : item(x), next(t) {}
};

typedef node* link;

void print(link x) {
    for (link cur = x; cur; cur = cur->next) {
        std::cout << cur->item << (cur->next ? " " : "");
    }
    std::cout << '\n';
}

link reverse(link x) {
    link t, y = x, r = nullptr;
    while (y) {
        t = y->next;
        y->next = r;
        r = y;
        y = t;
    }

    return r;
}

int usage(const char* bin) {
    std::cout << "Usage: " << bin << " <positive int N>\n";
    return 1;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        return usage(argv[0]);
    }

    int N = std::atoi(argv[1]);
    if (N <= 0) {
        return usage(argv[0]);
    }

    link t = new node(1, 0);
    t->next = t;
    link x = t;

    for (int i = 2; i <= N; ++i) {
        x = (x->next = new node(i, nullptr));
    }

    print(t);
    t = reverse(t);
    print(t);

    return 0;
}
