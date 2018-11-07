// ex.3.23

// en: Write a function that returns the number of nodes on a circular
// list, given a pointer to one of the nodes on the list.

// ru: Напишиту функцию, которая возвращает количество узлов,
// циклического списка по заданному указателю на один из узлов списка.

#include <iostream>

#include <catch.hpp>

#include <psv/list.h>

using psv::Node;
using psv::LengthCircular;

TEST_CASE("circular list length") {
    const int N = 10;
    Node<int>* nodes = new Node<int>[N];
    for (int i = 0; i < N - 1; ++i) {
        nodes[i].value(i);
        nodes[i].next(&nodes[i + 1]);
    }

    // check non-cyclic list
    for (int i = 0; i < N; ++i) {
        REQUIRE(LengthCircular(&nodes[i]) == N - i);
    }

    // make it cyclic
    nodes[N - 1].value(N - 1);
    nodes[N - 1].next(&nodes[0]);

    // check cyclic list
    for (int i = 0; i < N; ++i) {
        REQUIRE(LengthCircular(&nodes[i]) == N);
    }

    delete[] nodes;
}
