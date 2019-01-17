// ex.5.14

// en: Write a recursive program that removes the final node of a
// linked list.

// ru: Напишите рекурсивную программу, которая удаляет последний узел
// из связного списка.

#include <catch.hpp>

#include <psv/list.h>

using psv::Equal;
using psv::Free;
using psv::Make;
using psv::Node;

template <typename T>
void RemoveLast(Node<T>* cur, Node<T>* prev = nullptr) {
    const auto next = cur->next();
    if (next) {
        RemoveLast(next, cur);
    } else {
        delete cur;
        if (prev) {
            prev->next(nullptr);
        }
    }
}

TEST_CASE("non empty list") {
    const int N = 5;
    auto head = Make<int, N>({{1, 2, 3, 4, 5}});
    REQUIRE(Equal<N>(head, {1, 2, 3, 4, 5}));

    RemoveLast(head);

    REQUIRE(Equal<4>(head, {1, 2, 3, 4}));

    Free(head);
}

TEST_CASE("one element") {
    const int N = 1;
    auto head = Make<int, N>({{1}});
    REQUIRE(Equal<N>(head, {1}));

    RemoveLast(head);

    REQUIRE(Equal<0>(head, {}));

    Free(head);
}
