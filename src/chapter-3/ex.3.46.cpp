// ex.3.46

// en: Write a program that frees(invokes delete with a pointer to) all
// the nodes on a given linked list.

// ru: Напишите программу, которая удаляет все узлы связного списка (с
// помощью операции delete с указателем).

#include <array>
#include <iostream>
#include <random>

#include <catch.hpp>

#include "psv/list.h"

using psv::Node;
using psv::Make;
using psv::Free;

TEST_CASE("free list") {
    const std::array<std::size_t, 5> sizes = {{0, 1, 10, 100, 1000}};

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 1000);

    for (auto size : sizes) {
        auto head = new Node<int>;
        auto cur = head;
        for (std::size_t i = 0; i < size; ++i) {
            cur = cur->next(new Node<int>(dist(gen)));
        }

        Free(head);
    }
}
