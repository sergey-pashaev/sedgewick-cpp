#ifndef PROGRAM_3_12_H
#define PROGRAM_3_12_H

// program.3.12

// en: List-processing interface

// ru: Интерфейс обработки списков

#include <cstdlib>

typedef int Item;

struct node {
    Item item;
    node* next;
};

typedef node* link;
typedef link Node;

void construct(int);
Node newNode(int);
void deleteNode(Node);
void insert(Node, Node);
Node remove(Node);
Node next(Node);
Item item(Node);

#ifdef PROGRAM_3_12_USE_FREELIST
link freelist;

void construct(int N) {
    freelist = new node[N + 1];
    for (int i = 0; i < N; ++i) {
        freelist[i].next = &freelist[i + 1];
    }

    freelist[N].next = 0;
}

Node newNode(int i) {
    link x = remove(freelist);
    x->item = i;
    x->next = x;
    return x;
}

void deleteNode(link x) { insert(freelist, x); }
#else
void construct(int) {}

Node newNode(int i) {
    link x = new node;
    x->item = i;
    x->next = x;
    return x;
}

void deleteNode(link x) { delete x; }
#endif

void insert(link x, link t) {
    t->next = x->next;
    x->next = t;
}

link remove(link x) {
    link t = x->next;
    x->next = t->next;
    return t;
}

link next(link x) { return x->next; }
Item item(link x) { return x->item; }

#endif /* PROGRAM_3_12_H */
