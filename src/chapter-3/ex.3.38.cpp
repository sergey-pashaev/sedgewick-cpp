// ex.3.38

// en: Write a function that takes two arguments - a link to a list
// and a function that takes a link as argument - and removes all
// items on the given list for which the function returns a nonzero
// value.

// ru: Напишите функцию, принимающую два аргумента - ссылку на список
// и функцию, принимающую список в качестве аргумента - и удаляет все
// элементы данного списка, для которых функцию возвращает ненулевое
// значение.

#include <catch.hpp>

#include <psv/list.h>

using psv::Node;
using psv::Make;
using psv::Free;
using psv::Equal;
using psv::RemoveIf;

TEST_CASE("remove odd nodes") {
    const int N = 6;
    auto l1 = Make<int, N>({{0, 1, 2, 3, 4, 5}});

    RemoveIf(l1, [](const Node<int>* n) { return n->value() % 2 == 0; });

    REQUIRE(Equal<N>(l1, {{1, 3, 5}}));
    Free(l1);
}

TEST_CASE("remove half of list") {
    const int N = 6;
    auto l1 = Make<int, N>({{0, 1, 2, 3, 4, 5}});

    RemoveIf(l1, [](const Node<int>* n) { return n->value() > 2; });

    REQUIRE(Equal<N>(l1, {{0, 1, 2}}));
    Free(l1);
}

TEST_CASE("remove one specific node") {
    const int N = 6;
    auto l1 = Make<int, N>({{0, 1, 2, 3, 4, 5}});

    RemoveIf(l1, [](const Node<int>* n) { return n->value() == 0; });

    REQUIRE(Equal<N>(l1, {{1, 2, 3, 4, 5}}));
    Free(l1);
}

TEST_CASE("remove last node") {
    const int N = 1;
    auto l1 = Make<int, N>({{0}});

    RemoveIf(l1, [](const Node<int>* n) { return n->value() == 0; });

    REQUIRE(Equal<N>(l1, {{}}));
    Free(l1);
}
