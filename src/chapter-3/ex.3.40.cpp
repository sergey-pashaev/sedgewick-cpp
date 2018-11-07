// ex.3.40

// en: Implement a version of Program 3.10 that uses a head node.

// ru: Реализуйте версию программы 3.10, в которой используется
// ведущий узел.

#include <catch.hpp>

#include <psv/list.h>

using psv::Node;
using psv::Make;
using psv::Free;
using psv::Equal;
using psv::Reverse;

TEST_CASE("empty list") {
    const int N = 0;
    auto l = Make<int, N>({{}});

    Reverse(l);

    REQUIRE(Equal<N>(l, {{}}));
    Free(l);
}

TEST_CASE("one node") {
    const int N = 1;
    auto l = Make<int, N>({{0}});

    Reverse(l);

    REQUIRE(Equal<N>(l, {{0}}));
    Free(l);
}

TEST_CASE("two nodes") {
    const int N = 2;
    auto l = Make<int, N>({{0, 1}});

    Reverse(l);

    REQUIRE(Equal<N>(l, {{1, 0}}));
    Free(l);
}

TEST_CASE("more nodes") {
    const int N = 6;
    auto l = Make<int, N>({{0, 1, 2, 3, 4, 5}});

    Reverse(l);

    REQUIRE(Equal<N>(l, {{5, 4, 3, 2, 1, 0}}));
    Free(l);
}
