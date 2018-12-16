// ex.5.1

// en: Write a recursive program to compute lg(N!).

// ru: Напишите рекурсивную программу вычисления lg(N!).

#include <cassert>
#include <cmath>

#include <catch.hpp>

int factorial(int n) {
    assert(n >= 0);
    if (!n) return 1;
    return n * factorial(n - 1);
}

double f(int n) { return std::log10(factorial(n)); }

TEST_CASE("log of factorial") {
    REQUIRE(Approx(0.0) == f(0));
    REQUIRE(Approx(6.55976303288) == f(10));
}
