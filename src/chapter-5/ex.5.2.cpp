// ex.5.2

// en: Modify Program 5.1 to compute N! mod M, such that overflow is
// no longer an issue. Try running your program for M = 997 and N =
// 10^3, 10^4, 10^5, and 10^6, to get an indication of how your
// programming system handles deeply nested recursive calls.

// ru: Измените программу 5.1 для вычисления N! mod M без риска
// вызвать переполнение. Попробуйте выполнить программу для М = 997 и
// N = 10^3, 10^4, 10^5 и 10^6, чтобы увидеть, как используемая
// система программирования обрабатывает рекурсивные вызовы с большой
// глубиной вложенности.

#include <catch.hpp>

// n! % m = (n * n-1 * ... * 2 * 1) % m

// (n * n-1 * ... * 2 * 1) % m =
// = ((n % m) * (n-1 % m) * ... * (2 % m) * (1 % m)) % m

// if n >= m : somewhere in this product n % m = 0 so whole product will be 0

// if n < m : n % m = n, so product = (n * n - 1 * ... 2 * 1) % m , so
// in order to avoid overflow we might calculate % m on each step

int mod_factorial_i(int n, int m) {
    if (n >= m) return 0;
    int ret = 1;
    for (int i = 1; i <= n; ++i) ret = (ret * i) % m;
    return ret;
}

int mod_factorial_r(int n, int m) {
    if (n == 1) return n % m;
    return ((n % m) * mod_factorial_r(n - 1, m)) % m;
}

TEST_CASE("modulo of factorial: iterative") {
    REQUIRE(mod_factorial_i(5, 7) == 1);
    REQUIRE(mod_factorial_i(6, 7) == 6);

    REQUIRE(mod_factorial_i(997, 1000) == 0);
    REQUIRE(mod_factorial_i(997, 10'000) == 0);
    REQUIRE(mod_factorial_i(997, 100'000) == 0);
    REQUIRE(mod_factorial_i(997, 1'000'000) == 0);
}

TEST_CASE("modulo of factorial: recursive") {
    REQUIRE(mod_factorial_r(5, 7) == 1);
    REQUIRE(mod_factorial_r(6, 7) == 6);

    REQUIRE(mod_factorial_r(997, 1000) == 0);
    REQUIRE(mod_factorial_r(997, 10'000) == 0);
    REQUIRE(mod_factorial_r(997, 100'000) == 0);
    REQUIRE(mod_factorial_r(997, 1'000'000) == 0);
}
