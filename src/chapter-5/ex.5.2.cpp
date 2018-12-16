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

#include <cassert>
#include <cmath>
#include <cstdint>
#include <iostream>

#include <catch.hpp>

uint64_t mod_factorial(uint64_t n, uint64_t m) {
    if (!n) return 1;
    return (mod_factorial(n - 1, m) * n) % m;
}

int usage(const char* bin) {
    std::cout << "Usage: " << bin << " <positive int N> <positive int M>\n";
    return 1;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        return usage(argv[0]);
    }

    int n = std::atoi(argv[1]);
    int m = std::atoi(argv[2]);
    if (n <= 0 || m <= 0) {
        return usage(argv[0]);
    }

    std::cout << mod_factorial(n, m) << '\n';

    return 0;
}
