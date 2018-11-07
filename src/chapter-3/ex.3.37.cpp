// ex.3.37

// en: Write a function that takes a link to a list as argument and
// returns a link to a copy of the list (a new list that contains the
// same items, in the same order).

// ru: Напишите функцию, которая принимает ссылку на список в качестве
// аргумента и возвращает ссылку на копию списка (новый список,
// содержащий те же элементы в том же порядке).

#include <array>

#include <catch.hpp>

#include <psv/list.h>

using psv::Node;
using psv::Make;
using psv::Free;
using psv::Equal;
using psv::Copy;

TEST_CASE("several elements") {
    const int N = 6;
    const std::array<int, N> vals = {{0, 1, 2, 3, 4, 5}};
    auto l1 = Make<int, N>(vals);
    auto l2 = Copy(l1);
    REQUIRE(Equal<N>(l1, vals));
    REQUIRE(Equal<N>(l2, vals));
    Free(l1);
    Free(l2);
}

TEST_CASE("two elements") {
    const int N = 2;
    const std::array<int, N> vals = {{0, 1}};
    auto l1 = Make<int, N>(vals);
    auto l2 = Copy(l1);
    REQUIRE(Equal<N>(l1, vals));
    REQUIRE(Equal<N>(l2, vals));
    Free(l1);
    Free(l2);
}

TEST_CASE("one element") {
    const int N = 1;
    const std::array<int, N> vals = {{1}};
    auto l1 = Make<int, N>(vals);
    auto l2 = Copy(l1);
    REQUIRE(Equal<N>(l1, vals));
    REQUIRE(Equal<N>(l2, vals));
    Free(l1);
    Free(l2);
}

TEST_CASE("empty") {
    const int N = 0;
    const std::array<int, N> vals = {};
    auto l1 = Make<int, N>(vals);
    auto l2 = Copy(l1);
    REQUIRE(Equal<N>(l1, vals));
    REQUIRE(Equal<N>(l2, vals));
    Free(l1);
    Free(l2);
}
