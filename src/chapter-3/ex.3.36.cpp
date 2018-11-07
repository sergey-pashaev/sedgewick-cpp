// ex.3.36

// en: Implement a code fragment for a linked list that exchanges the
// positions of the nodes after the nodes referenced by two given
// links t and u.

// ru: Реализуйте фрагмент кода для связного списка, меняющий местами
// узлы, которые следуют после узлов, указываемых t и u.

#include <stdexcept>
#include <utility>

#include <catch.hpp>

#include <psv/list.h>

using psv::Node;
using psv::Make;
using psv::Free;
using psv::Equal;

// nX    - nX           - node before to node to swap
// nX_s  - nX->next()   - X node to swap
// nX_sn - nX_s->next() - X node after node to swap

// no overlap:
// | node |  0 |    1 |     2 |  3 |    4 |     5 |
// |------+----+------+-------+----+------+-------|
// | ptr  | n1 | n1_s | n1_sn |    |      |       |
// | ptr  |    |      |       | n2 | n2_s | n2_sn |

// sn node overlap: treated exactly the same as no overlap !!!
// | node |  0 |    1 | 2       |    3 |     4 | 5 |
// |------+----+------+---------+------+-------+---|
// | ptr  | n1 | n1_s | *n1_sn* |      |       |   |
// | ptr  |    |      | *n2*    | n2_s | n2_sn |   |

// s node overlap:
// | node |  0 | 1      | 2     |     3 | 4 | 5 |
// |------+----+--------+-------+-------+---+---|
// | ptr  | n1 | *n1_s* | n1_sn |       |   |   |
// | ptr  |    | *n2*   | n2_s  | n2_sn |   |   |

template <typename T>
void swap_no_overlap(Node<T>* n1, Node<T>* n2) {
    auto n1_s = n1->next();
    auto n2_s = n2->next();
    auto n1_sn = n1_s->next();
    auto n2_sn = n2_s->next();

    // 1. n1.next   = n2_s
    // 2. n2_s.next = n1_sn
    // 3. n2.next   = n1_s
    // 4. n1_s.next = n2_sn
    //
    //                                 1.
    //      +-----------------------------------------------+
    //      |                      3.                       |
    //      |           +-----------------------+           |
    //      |           v                       |           V
    //   +-----+ 1.  +-----+ 4.  +-----+     +-----+ 3.  +-----+ 2.  +-----+
    // --| n1  |-XX->|n1_s |-XX->|n1_sn|---->| n2  |-XX->|n2_s |-XX->|n2_sn|-->
    //   +-----+     +-----+     +-----+     +-----+     +-----+     +-----+
    //                  |           ^          2.           |           ^
    //                  |           +-----------------------+           |
    //                  |                      4.                       |
    //                  +-----------------------------------------------+

    n1->next(n2_s);
    n2_s->next(n1_sn);
    n2->next(n1_s);
    n1_s->next(n2_sn);
}

template <typename T>
void swap_s_overlap(Node<T>* n1, Node<T>* n2) {
    auto n1_s = n1->next();
    auto n2_s = n2->next();
    // auto n1_sn = n1_s->next();
    auto n2_sn = n2_s->next();

    // 1. n1.next   = n2_s
    // 2. n2_s.next = n1_s
    // 3. n1_s.next = n2_sn
    //
    //                               3.
    //                  +-----------------------+
    //             1.   |                       |
    //      +-----------+-----------+           |
    //      |           |           |           |
    //      |           |           V           |
    //   +-----+ 1.  +-----+     +-----+        |
    // --| n1  |-XX->|n1_s | 3.  |n1_sn|        V
    //   +-----+     +-----+-XX->+-----+ 2.  +-----+
    //               | n2  |     |n2_s |-XX->|n2_sn|-->
    //               +-----+     +-----+     +-----+
    //                  ^           |
    //                  |    2.     |
    //                  +-----------+

    n1->next(n2_s);
    n2_s->next(n1_s);
    n1_s->next(n2_sn);
}

template <typename T>
void swap(Node<T>* n1, Node<T>* n2) {
    if (n1 == n2) return;

    auto n1_s = n1->next();
    auto n2_s = n2->next();

    if (!n1_s || !n2_s) throw std::out_of_range("can't swap node with nil");

    if (n1_s == n2) {
        swap_s_overlap(n1, n2);
    } else if (n2_s == n1) {
        swap_s_overlap(n2, n1);
    } else {
        swap_no_overlap(n1, n2);
    }
}

template <typename T>
std::pair<Node<T>*, Node<T>*> GetIndexes(const Node<T>* head, std::size_t i1,
                                         std::size_t i2) {
    Node<T>* n1 = nullptr;
    Node<T>* n2 = nullptr;

    std::size_t i = 0;
    for (auto cur = head->next(); cur; cur = cur->next(), ++i) {
        if (i == i1) n1 = cur;
        if (i == i2) n2 = cur;
    }

    return std::make_pair(n1, n2);
}

const int N = 6;

TEST_CASE("no overlap") {
    auto head = Make<int, N>({{0, 1, 2, 3, 4, 5}});

    auto node = GetIndexes(head, 0, 3);
    swap(node.first, node.second);

    REQUIRE(Equal<N>(head, {{0, 4, 2, 3, 1, 5}}));
    Free(head);
}

TEST_CASE("no overlap, swapped args") {
    auto head = Make<int, N>({{0, 1, 2, 3, 4, 5}});

    auto node = GetIndexes(head, 3, 0);
    swap(node.first, node.second);

    REQUIRE(Equal<N>(head, {{0, 4, 2, 3, 1, 5}}));
    Free(head);
}

TEST_CASE("sn overlap") {
    auto head = Make<int, N>({{0, 1, 2, 3, 4, 5}});

    auto node = GetIndexes(head, 0, 2);
    swap(node.first, node.second);

    REQUIRE(Equal<N>(head, {{0, 3, 2, 1, 4, 5}}));
    Free(head);
}

TEST_CASE("sn overlap, swapped args") {
    auto head = Make<int, N>({{0, 1, 2, 3, 4, 5}});

    auto node = GetIndexes(head, 2, 0);
    swap(node.first, node.second);

    REQUIRE(Equal<N>(head, {{0, 3, 2, 1, 4, 5}}));
    Free(head);
}

TEST_CASE("s overlap") {
    auto head = Make<int, N>({{0, 1, 2, 3, 4, 5}});

    auto node = GetIndexes(head, 0, 1);
    swap(node.first, node.second);

    REQUIRE(Equal<N>(head, {{0, 2, 1, 3, 4, 5}}));
    Free(head);
}

TEST_CASE("s overlap, swapped args") {
    auto head = Make<int, N>({{0, 1, 2, 3, 4, 5}});

    auto node = GetIndexes(head, 1, 0);
    swap(node.first, node.second);

    REQUIRE(Equal<N>(head, {{0, 2, 1, 3, 4, 5}}));
    Free(head);
}

TEST_CASE("same nodes") {
    auto head = Make<int, N>({{0, 1, 2, 3, 4, 5}});

    auto node = GetIndexes(head, 0, 0);
    swap(node.first, node.second);

    REQUIRE(Equal<N>(head, {{0, 1, 2, 3, 4, 5}}));
    Free(head);
}

TEST_CASE("s overlap, at end") {
    auto head = Make<int, N>({{0, 1, 2, 3, 4, 5}});

    auto node = GetIndexes(head, 3, 4);
    swap(node.first, node.second);

    REQUIRE(Equal<N>(head, {{0, 1, 2, 3, 5, 4}}));
    Free(head);
}

TEST_CASE("s overlap, at end, swapped args") {
    auto head = Make<int, N>({{0, 1, 2, 3, 4, 5}});

    auto node = GetIndexes(head, 4, 3);
    swap(node.first, node.second);

    REQUIRE(Equal<N>(head, {{0, 1, 2, 3, 5, 4}}));
    Free(head);
}

TEST_CASE("out of range exception") {
    auto head = Make<int, N>({{0, 1, 2, 3, 4, 5}});

    auto node = GetIndexes(head, 4, 5);
    REQUIRE_THROWS_AS(swap(node.first, node.second), std::out_of_range);

    REQUIRE(Equal<N>(head, {{0, 1, 2, 3, 4, 5}}));
    Free(head);
}
