#ifndef JOSEPHUS_H
#define JOSEPHUS_H

int Josephus(int n, int m) {
    struct Node {
        int item;
        Node* next;

        Node(int x, Node* t) : item(x), next(t) {}
    };

    typedef Node* Link;

    Link t = new Node(1, 0);
    t->next = t;
    Link x = t;

    for (int i = 2; i <= n; ++i) {
        x = (x->next = new Node(i, t));
    }

    while (x != x->next) {
        for (int i = 1; i < m; ++i) x = x->next;
        Link next_next = x->next->next;
        delete x->next;
        x->next = next_next;
    }

    int ret = x->item;
    delete x;

    return ret;
}

#endif /* JOSEPHUS_H */
