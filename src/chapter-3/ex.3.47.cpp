// ex.3.47

// en: Write a program that frees the nodes in positions that are
// divisible by 5 in a linked list (the fifth, tenth, fifteenth, and
// so forth).

// ru: Напишите программу, которая удаляет узлы связного списка,
// находящиеся в позициях с номерами кратными 5 (5, 10, 15, ...).

#include <catch.hpp>

#include <psv/list.h>

using psv::Node;
using psv::Make;
using psv::Free;
using psv::Equal;
using psv::RemoveIf;

const int mod = 5;

struct PositionMod {
    PositionMod(std::size_t mod) : mod(mod) {}

    template <typename T>
    bool operator()(const Node<T>*) {
        return ++pos % mod == 0;
    }

    std::size_t mod = 1;
    std::size_t pos = 0;
};

TEST_CASE("less than mod") {
    const int N = 1;
    auto head = Make<int, N>({{1}});

    RemoveIf(head, PositionMod(mod));

    REQUIRE(Equal<N>(head, {{1}}));
    Free(head);
}

TEST_CASE("equal mod") {
    const int N = 5;
    auto head = Make<int, N>({{1, 2, 3, 4, 5}});

    RemoveIf(head, PositionMod(mod));

    REQUIRE(Equal<N>(head, {{1, 2, 3, 4}}));
    Free(head);
}

TEST_CASE("more than mod") {
    const int N = 11;
    auto head = Make<int, N>({{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}});

    RemoveIf(head, PositionMod(mod));

    REQUIRE(Equal<N>(head, {{1, 2, 3, 4, 6, 7, 8, 9, 11}}));
    Free(head);
}
