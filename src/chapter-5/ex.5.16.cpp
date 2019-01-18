// ex.5.16

// en: Write a recursive program that finds the maximum element in an
// array, based on comparing the first element in the array against
// the maximum element in the rest of the array (computed
// recursively).

// ru: Напишите рекурсивную программу, которая находит максимальный
// элемент в массиве, выполняя сравнение первого элемента с
// максимальным элементом остальной части массива (найденным
// рекурсивно).

#include <catch.hpp>

template <typename T>
T max(const T a[], int l, int r) {
    if (l == r) return a[l];
    T rest = max(a, l + 1, r);
    return a[l] > rest ? a[l] : rest;
}

TEST_CASE("max") {
    const int N = 5;
    const int end[N] = {1, 2, 3, 4, 5};
    const int beg[N] = {5, 1, 2, 3, 4};
    const int mid[N] = {1, 2, 5, 3, 4};
    const int dup[N] = {5, 1, 2, 5, 3};
    const int one[N] = {5};

    REQUIRE(max(end, 0, 4) == 5);
    REQUIRE(max(beg, 0, 4) == 5);
    REQUIRE(max(mid, 0, 4) == 5);
    REQUIRE(max(dup, 0, 4) == 5);
    REQUIRE(max(one, 0, 0) == 5);
}
