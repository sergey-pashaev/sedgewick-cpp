// ex.3.34

// en: Write a function that moves the smallest item on a given list
// to be the first node on the list.

// ru: Напишите функцию, которая перемещает наименьший элемент данного
// списка в начало списка.

#include <catch.hpp>

#include <psv/list.h>

using psv::Node;
using psv::Make;
using psv::Free;
using psv::Equal;

template <typename T>
void MoveMinToBegin(Node<T>* head) {
    if (!head->next()) {
        return;
    }

    // find min
    auto min = head->next();
    for (auto cur = head->next(); cur; cur = cur->next()) {
        if (cur->value() < min->value()) {
            min = cur;
        }
    }

    // move to node before min
    auto cur = head;
    while (cur->next() != min) cur = cur->next();

    // cut min
    cur->next(min->next());

    // insert min at begin
    min->next(head->next());
    head->next(min);
}

const int N = 5;

TEST_CASE("min in end") {
    auto head = Make<int, N>({{5, 4, 3, 2, 1}});

    MoveMinToBegin(head);

    REQUIRE(Equal<N>(head, {{1, 5, 4, 3, 2}}));
    Free(head);
}

TEST_CASE("min in middle") {
    auto head = Make<int, N>({{2, 3, 1, 4, 5}});

    MoveMinToBegin(head);

    REQUIRE(Equal<N>(head, {{1, 2, 3, 4, 5}}));
    Free(head);
}

TEST_CASE("min in begin") {
    auto head = Make<int, N>({{1, 2, 3, 4, 5}});

    MoveMinToBegin(head);

    REQUIRE(Equal<N>(head, {{1, 2, 3, 4, 5}}));
    Free(head);
}

TEST_CASE("more than one min, move first one") {
    auto head = Make<int, N>({{2, 1, 3, 1, 4}});

    MoveMinToBegin(head);

    REQUIRE(Equal<N>(head, {{1, 2, 3, 1, 4}}));
    Free(head);
}

TEST_CASE("all same") {
    auto head = Make<int, N>({{1, 1, 1, 1, 1}});

    MoveMinToBegin(head);

    REQUIRE(Equal<N>(head, {{1, 1, 1, 1, 1}}));
    Free(head);
}

TEST_CASE("empty list") {
    auto head = new Node<int>;

    MoveMinToBegin(head);

    REQUIRE(head->next() == nullptr);
    Free(head);
}

TEST_CASE("1 node") {
    auto head = Make<int, 1>({{1}});

    MoveMinToBegin(head);

    REQUIRE(Equal<N>(head, {{1}}));
    Free(head);
}

TEST_CASE("2 nodes") {
    auto head = Make<int, 2>({{2, 1}});

    MoveMinToBegin(head);

    REQUIRE(Equal<N>(head, {{1, 2}}));
    Free(head);
}
