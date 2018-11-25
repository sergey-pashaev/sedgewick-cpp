// program.3.10

// en: List reversal

// ru: Обращение списка

#include <cstdlib>
#include <iostream>

struct Node {
    int item;
    Node* next;

    Node(int x, Node* t) : item(x), next(t) {}
};

typedef Node* Link;

void Print(Link x) {
    for (Link cur = x; cur; cur = cur->next) {
        std::cout << cur->item << (cur->next ? " " : "");
    }
    std::cout << '\n';
}

Link Reverse(Link x) {
    Link t, y = x, r = nullptr;
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

    Link t = new Node(1, 0);
    t->next = t;
    Link x = t;

    for (int i = 2; i <= N; ++i) {
        x = (x->next = new Node(i, nullptr));
    }

    Print(t);
    t = Reverse(t);
    Print(t);

    return 0;
}
