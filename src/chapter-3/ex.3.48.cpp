// ex.3.48

// en: Write a program that frees the nodes in even positions in a
// linked list (the second, fourth, sixth, and so forth).

// ru: Напишите программу, которая удаляет узлы в чётных позициях
// связного списка (2, 4, 6, ...).

#include <catch.hpp>

#include <psv/list.h>

using psv::Equal;
using psv::Free;
using psv::Make;
using psv::Node;
using psv::RemoveIf;

const int mod = 2;

struct PositionMod {
    explicit PositionMod(std::size_t mod) : mod(mod) {}

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
    const int N = 2;
    auto head = Make<int, N>({{1, 2}});

    RemoveIf(head, PositionMod(mod));

    REQUIRE(Equal<N>(head, {{1}}));
    Free(head);
}

TEST_CASE("more than mod") {
    const int N = 11;
    auto head = Make<int, N>({{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}});

    RemoveIf(head, PositionMod(mod));

    REQUIRE(Equal<N>(head, {{1, 3, 5, 7, 9, 11}}));
    Free(head);
}
