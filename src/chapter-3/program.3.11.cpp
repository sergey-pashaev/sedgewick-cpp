// program.3.11

// en: List insertion sort

// ru: Сортировка методом вставки в список

#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <random>
#include <vector>

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

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 1000);

    Node heada(0, nullptr);
    Link a = &heada;
    Link t = a;

    for (int i = 0; i < N; ++i) {
        t = (t->next = new Node(dist(gen), nullptr));
    }

    Node headb(0, nullptr);
    Link u, x, b = &headb;

    // loop over unsorted list
    for (t = a->next; t; t = u) {
        u = t->next;

        // find node to insert before
        for (x = b; x->next; x = x->next) {
            if (t->item < x->next->item) break;
        }

        // insert
        t->next = x->next;
        x->next = t;
    }

    std::vector<int> v;
    v.reserve(N);
    for (x = b->next; x; x = x->next) {
        v.push_back(x->item);
    }

    // cleanup
    for (x = b->next; x; x = u) {
        u = x->next;
        delete x;
    }

    assert(std::is_sorted(v.begin(), v.end()));

    return 0;
}
