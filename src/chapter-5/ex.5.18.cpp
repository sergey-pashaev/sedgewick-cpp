// ex.5.18

// en: Modify the divide-and-conquer program for finding the maximum
// element in an array (Program 5.6) to divide an array of size N into
// one part of size k = 2^(ceil(lg N) – 1) and another of size N – k
// (so that the size of at least one of the parts is a power of 2).

// ru: Измените программу "разделяй и властвуй" для отыскания
// максимального элемента в массиве (программа 5.6), чтобы она делила
// массив размера N на две части, одна из которых имеет размер k =
// 2^(ceil(lg N) - 1), а вторая - N – k (чтобы размер хотя бы одной
// части был степенью 2).

#include <cmath>

#include <catch.hpp>

template <typename T>
T max(T a[], int l, int r) {
    if (l == r) return a[l];
    const int size = r - l + 1;
    const int k = std::pow(2, std::ceil(std::log10(size)) - 1);
    T u = max(a, l, l + k - 1);
    T v = max(a, l + k, r);
    return u > v ? u : v;
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
