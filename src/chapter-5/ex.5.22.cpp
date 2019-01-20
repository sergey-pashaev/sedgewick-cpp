// ex.5.22

// en: Write a recursive program that computes the length of the ith
// mark in a ruler with 2^n–1 marks.

// ru: Напишите рекурсивную программу, которая вычисляет длину i-ой
// метки на линейке с 2^n-1 метками.

#include <cmath>

#include <catch.hpp>

int height(int i, int l, int r, int h) {
    if (!h) return 0;

    int m = (l + r) / 2;
    if (m == i) {
        return h;
    } else {
        int v = height(i, l, m, h - 1);
        if (v) return v;

        v = height(i, m, r, h - 1);
        return v ? v : 0;
    }
}

TEST_CASE("height") {
    const int n = 4;
    const int l = 0;
    const int r = std::pow(2, n);

    //                      |
    //          |           |           |
    //    |     |     |     |     |     |     |
    // |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
    // 1  2  3  4  5  6  7  8  9 10 11 12 13 14 15

    REQUIRE(height(8, l, r, n) == 4);
    REQUIRE(height(7, l, r, n) == 1);
    REQUIRE(height(6, l, r, n) == 2);
    REQUIRE(height(5, l, r, n) == 1);
}
