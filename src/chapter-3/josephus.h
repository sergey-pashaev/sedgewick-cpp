#ifndef JOSEPHUS_H
#define JOSEPHUS_H

int josephus(int n, int m) {
    struct node {
        int item;
        node* next;

        node(int x, node* t) : item(x), next(t) {}
    };

    typedef node* link;

    link t = new node(1, 0);
    t->next = t;
    link x = t;

    for (int i = 2; i <= n; ++i) {
        x = (x->next = new node(i, t));
    }

    while (x != x->next) {
        for (int i = 1; i < m; ++i) x = x->next;
        link next_next = x->next->next;
        delete x->next;
        x->next = next_next;
    }

    int ret = x->item;
    delete x;

    return ret;
}

#endif /* JOSEPHUS_H */
