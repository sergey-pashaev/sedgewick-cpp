// ex.3.26

// en: Given pointers x and t to nodes on a circular list, write a
// code fragment that moves the node following t to the position
// following the node following x on the list.

// ru: Напишите фрагмент кода, который для данных указателей x и t на
// узлы циклического списка перемещает узел, следующий за t, в позицию
// после узла x.

#include <array>
#include <iostream>

#include <catch.hpp>

#include <psv/list.h>

using psv::Node;

template <typename T>
void MoveAfter(Node<T>* dst, Node<T>* src) {
    if (dst == src || src->next() == dst) return;

    Node<T>* src_next = src->next();
    src->next(src_next->next());

    Node<T>* dst_next = dst->next();
    dst->next(src_next);

    src_next->next(dst_next);
}

template <int N, typename T>
void CheckValues(const Node<T>* node, const std::array<T, N>& vals) {
    size_t i = 0;
    for (const Node<T> *cur = node; cur && cur != cur->next();
         cur = cur->next(), ++i) {
        if (i && cur == node) break;  // cycle
        REQUIRE(cur->value() == vals[i]);
    }
}

template <typename T>
Node<T>* MakeList(size_t n, T start_value) {
    Node<T>* list = new Node<T>[n];
    for (size_t i = 0; i < n - 1; ++i) {
        list[i].value(start_value++);
        list[i].next(&list[i + 1]);
    }

    // init last node
    list[n - 1].value(start_value);

    return list;
}

TEST_CASE("list move") {
    const int N = 5;
    // make list out of n nodes
    Node<int>* a = MakeList(N, 0);

    // make cyclic
    a[N - 1].next(&a[0]);

    // a: 0 -> 1 -> 2 -> 3 -> 4 - > 0

    SECTION("insert in begin") {
        MoveAfter(&a[0], &a[2]);

        std::array<int, N> vals = {{0, 3, 1, 2, 4}};
        CheckValues<N>(&a[0], vals);
    }

    SECTION("insert in middle") {
        MoveAfter(&a[1], &a[3]);

        std::array<int, N> vals = {{0, 1, 4, 2, 3}};
        CheckValues<N>(&a[0], vals);
    }

    SECTION("insert in end") {
        MoveAfter(&a[4], &a[2]);

        std::array<int, N> vals = {{0, 1, 2, 4, 3}};
        CheckValues<N>(&a[0], vals);
    }

    SECTION("close pair") {
        MoveAfter(&a[3], &a[2]);

        std::array<int, N> vals = {{0, 1, 2, 3, 4}};  // no changes
        CheckValues<N>(&a[0], vals);
    }

    SECTION("same nodes") {
        MoveAfter(&a[2], &a[2]);

        std::array<int, N> vals = {{0, 1, 2, 3, 4}};  // no changes
        CheckValues<N>(&a[0], vals);
    }

    delete[] a;
}
