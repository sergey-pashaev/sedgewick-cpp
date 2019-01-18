// ex.5.17

// en: Write a recursive program that finds the maximum element in a
// linked list.

// ru: Напишите рекурсивную программу, которая находит максимальный
// элемент в связном списке.

#include <catch.hpp>

#include <psv/list.h>

using psv::Equal;
using psv::Free;
using psv::Make;
using psv::Node;

template <typename T>
Node<T>* max(Node<T>* cur, Node<T>* cur_max = nullptr) {
    if (!cur) {
        return cur_max;
    } else {
        auto rest = max(cur->next(), cur);
        return rest ? (cur->value() > rest->value() ? cur : rest) : cur;
    }
}

TEST_CASE("max in the end") {
    const int N = 5;
    auto head = Make<int, N>({{1, 2, 3, 4, 5}});

    auto m = max(head->next());
    REQUIRE(m->value() == 5);

    Free(head);
}

TEST_CASE("max at the beginning") {
    const int N = 5;
    auto head = Make<int, N>({{5, 1, 2, 3, 4}});

    auto m = max(head->next());
    REQUIRE(m->value() == 5);

    Free(head);
}

TEST_CASE("max in the middle") {
    const int N = 5;
    auto head = Make<int, N>({{1, 2, 5, 3, 4}});

    auto m = max(head->next());
    REQUIRE(m->value() == 5);

    Free(head);
}

TEST_CASE("max is duplicated") {
    const int N = 5;
    auto head = Make<int, N>({{5, 1, 2, 5, 3}});

    auto m = max(head->next());
    REQUIRE(m->value() == 5);

    Free(head);
}

TEST_CASE("one element") {
    const int N = 1;
    auto head = Make<int, N>({{5}});

    auto m = max(head->next());
    REQUIRE(m->value() == 5);

    Free(head);
}
