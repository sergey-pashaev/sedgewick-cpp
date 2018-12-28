// ex.5.5

// en: Provide a nonrecursive implementation of Euclid's algorithm.

// ru: Создайте нерекурсивную реализацию алгоритма Евклида.

#include <catch.hpp>

int gcd(int m, int n) {
    if (n == 0) return m;
    return gcd(n, m % n);
}

int gcd_iterative(int m, int n) {
    int t = 0;
    while (n != 0) {
        t = m;
        m = n;
        n = t % n;
    }

    return m;
}

TEST_CASE("gcd iterative") {
    REQUIRE(gcd(12, 18) == gcd_iterative(12, 18));
    REQUIRE(gcd(54, 24) == gcd_iterative(54, 24));
    REQUIRE(gcd(84, 132) == gcd_iterative(84, 132));
    REQUIRE(gcd(299792458, 6447287) == gcd_iterative(299792458, 6447287));
}
