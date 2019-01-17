// ex.5.13

// en: Write a recursive program for the Josephus problem (see Section
// 3.3).

// ru: Напишите рекурсивную программу для решения задачи Иосифа Флавия
// (см. раздел 3.3).

#include <catch.hpp>

struct Node {
    Node(int v, Node* next = nullptr) : v{v}, next{next} {}
    int v;
    Node* next;
};

Node* advance(Node* cur, std::size_t n) {
    if (n) {
        return advance(cur->next, --n);
    } else {
        return cur;
    }
}

Node* JosephusRecursive(Node* x, int m) {
    if (x != x->next) {
        x = advance(x, m - 1);  // for (int i = 1; i < m; ++i) x = x->next;
        Node* next_next = x->next->next;
        delete x->next;
        x->next = next_next;
        x = JosephusRecursive(x, m);
    }

    return x;
}

int Josephus(int n, int m) {
    Node* t = new Node{1};
    t->next = t;
    Node* x = t;

    for (int i = 2; i <= n; ++i) {
        x = (x->next = new Node{i, t});
    }

    x = JosephusRecursive(x, m);
    int ret = x->v;
    delete x;

    return ret;
}

TEST_CASE("Josephus") {
    REQUIRE(Josephus(9, 5) == 8);

    // see ex.3.29.md
    REQUIRE(Josephus(1000, 2) == 977);
    REQUIRE(Josephus(1000, 3) == 604);
    REQUIRE(Josephus(1000, 5) == 763);
}
