// ex.5.1

// en: Write a recursive program to compute lg(N!).

// ru: Напишите рекурсивную программу вычисления lg(N!).

#include <cmath>

#include <catch.hpp>

// lg(n!) = lg(n * n-1 * ... 2 * 1) = lg(n) + lg(n-1) * ... * lg(2) + lg(1)

double f(int n) {
    if (n < 1) return 0;
    return std::log2(n) + f(n - 1);
}

TEST_CASE("log of factorial") {
    REQUIRE(Approx(0.0) == f(0));
    REQUIRE(Approx(21.7910611147) == f(10));
}
