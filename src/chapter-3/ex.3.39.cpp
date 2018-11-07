// ex.3.39

// en: Solve Exercise 3.38, but make copies of the nodes that pass the
// test and return a link to a list containing those nodes, in the
// order that they appear in the original list.

// ru: Выполните упражнение 3.38, но создайте копии узлов, которые
// прошли проверку и возвратите ссылку на список, содержащий эти узлы,
// в порядке их следования.

#include <catch.hpp>

#include <psv/list.h>

using psv::Node;
using psv::Make;
using psv::Free;
using psv::Equal;
using psv::CopyIf;

TEST_CASE("copy odd nodes") {
    const int N = 6;
    auto l1 = Make<int, N>({{0, 1, 2, 3, 4, 5}});

    auto l2 =
        CopyIf(l1, [](const Node<int>* n) { return n->value() % 2 == 0; });

    REQUIRE(Equal<N>(l2, {{0, 2, 4}}));
    Free(l1);
    Free(l2);
}

TEST_CASE("copy half of list") {
    const int N = 6;
    auto l1 = Make<int, N>({{0, 1, 2, 3, 4, 5}});

    auto l2 = CopyIf(l1, [](const Node<int>* n) { return n->value() > 2; });

    REQUIRE(Equal<N>(l2, {{3, 4, 5}}));
    Free(l1);
    Free(l2);
}

TEST_CASE("copy one specific node") {
    const int N = 6;
    auto l1 = Make<int, N>({{0, 1, 2, 3, 4, 5}});

    auto l2 = CopyIf(l1, [](const Node<int>* n) { return n->value() == 0; });

    REQUIRE(Equal<N>(l2, {{0}}));
    Free(l1);
    Free(l2);
}

TEST_CASE("copy last node") {
    const int N = 1;
    auto l1 = Make<int, N>({{0}});

    auto l2 = CopyIf(l1, [](const Node<int>* n) { return n->value() == 0; });

    REQUIRE(Equal<N>(l2, {{0}}));
    Free(l1);
    Free(l2);
}
