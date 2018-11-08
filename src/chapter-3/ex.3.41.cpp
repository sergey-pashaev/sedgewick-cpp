// ex.3.41

// en: Implement a version of Program 3.11 that does not use head
// nodes.

// ru: Реализуйте версию программы 3.11, в которой не используются
// ведущие узлы.

#include <array>
#include <iostream>
#include <random>
#include <vector>

#include <catch.hpp>

#include <psv/list.h>

using psv::Node;
using psv::Make;
using psv::Free;

TEST_CASE("insertion sort") {
    const std::array<std::size_t, 4> sizes = {{1, 10, 100, 1000}};

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 1000);

    for (auto size : sizes) {
        auto head = new Node<int>;
        auto cur = head;
        for (std::size_t i = 0; i < size; ++i) {
            cur = cur->next(new Node<int>(dist(gen)));
        }

        auto sorted = InsertionSort(head->next());
        head->next(sorted);

        std::vector<int> v;
        v.reserve(size);
        for (auto cur = head->next(); cur; cur = cur->next()) {
            v.push_back(cur->value());
        }

        REQUIRE(std::is_sorted(v.begin(), v.end()));

        Free(head);
    }
}
