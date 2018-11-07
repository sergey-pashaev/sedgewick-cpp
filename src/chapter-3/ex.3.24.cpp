// ex.3.24

// en: Write a code fragment that determines the number of nodes that
// are between the nodes referenced by two given pointers x and t to
// nodes on a circular list.

// ru: Напишите фрагмент кода, который определяет количество узлов в
// циклическом списке между узлами, указанными двумя данными
// указателями x и t.

#include <iostream>

#include <catch.hpp>

#include <psv/list.h>

using psv::Node;
using psv::BetweenCircular;

TEST_CASE("cyclic list distance BetweenCircular 2 nodes") {
    const int N = 10;
    // make list out of n nodes
    Node<int>* nodes = new Node<int>[N];
    for (int i = 0; i < N - 1; ++i) {
        nodes[i].value(i);
        nodes[i].next(&nodes[i + 1]);
    }

    // make it cyclic
    nodes[N - 1].value(N - 1);
    nodes[N - 1].next(&nodes[0]);

    // list:
    // 0 -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 0
    REQUIRE(BetweenCircular(&nodes[0], &nodes[0]) == 0);
    REQUIRE(BetweenCircular(&nodes[0], &nodes[1]) == 0);
    REQUIRE(BetweenCircular(&nodes[0], &nodes[2]) == 1);
    REQUIRE(BetweenCircular(&nodes[0], &nodes[9]) == 8);
    REQUIRE(BetweenCircular(&nodes[5], &nodes[4]) == 8);

    delete[] nodes;
}
