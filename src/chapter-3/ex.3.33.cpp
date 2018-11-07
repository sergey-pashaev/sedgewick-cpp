// ex.3.33

// en: Write a function that moves the largest item on a given list to
// be the final node on the list.

// ru: Напишите функцию, которая перемещает наибольший элемент данного
// списка в конец списка.

#include <catch.hpp>

#include <psv/list.h>

using psv::Node;
using psv::Make;
using psv::Free;
using psv::Equal;

template <typename T>
void MoveMaxToEnd(Node<T>* head) {
    if (!head->next()) {
        return;
    }

    // find max
    auto max = head->next();
    for (auto cur = head->next(); cur; cur = cur->next()) {
        if (cur->value() > max->value()) {
            max = cur;
        }
    }

    // move to node before max
    auto cur = head;
    while (cur->next() != max) cur = cur->next();

    // cut max
    cur->next(max->next());

    // find tail
    while (cur->next()) cur = cur->next();

    // insert max at end
    cur->next(max);
    max->next(nullptr);
}

const int N = 5;

TEST_CASE("max in begin") {
    auto head = Make<int, N>({{5, 4, 3, 2, 1}});

    MoveMaxToEnd(head);

    REQUIRE(Equal<N>(head, {{4, 3, 2, 1, 5}}));
    Free(head);
}

TEST_CASE("max in middle") {
    auto head = Make<int, N>({{1, 2, 5, 3, 4}});

    MoveMaxToEnd(head);

    REQUIRE(Equal<N>(head, {{1, 2, 3, 4, 5}}));
    Free(head);
}

TEST_CASE("max in end") {
    auto head = Make<int, N>({{1, 2, 3, 4, 5}});

    MoveMaxToEnd(head);

    REQUIRE(Equal<N>(head, {{1, 2, 3, 4, 5}}));
    Free(head);
}

TEST_CASE("more than one max, move first one") {
    auto head = Make<int, N>({{1, 5, 3, 5, 4}});

    MoveMaxToEnd(head);

    REQUIRE(Equal<N>(head, {{1, 3, 5, 4, 5}}));
    Free(head);
}

TEST_CASE("all same") {
    auto head = Make<int, N>({{1, 1, 1, 1, 1}});

    MoveMaxToEnd(head);

    REQUIRE(Equal<N>(head, {{1, 1, 1, 1, 1}}));
    Free(head);
}

TEST_CASE("empty list") {
    auto head = new Node<int>;

    MoveMaxToEnd(head);

    REQUIRE(head->next() == nullptr);
    Free(head);
}

TEST_CASE("1 node") {
    auto head = Make<int, 1>({{1}});

    MoveMaxToEnd(head);

    REQUIRE(Equal<N>(head, {{1}}));
    Free(head);
}

TEST_CASE("2 nodes") {
    auto head = Make<int, 2>({{2, 1}});

    MoveMaxToEnd(head);

    REQUIRE(Equal<N>(head, {{1, 2}}));
    Free(head);
}
