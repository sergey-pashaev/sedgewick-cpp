// ex.3.12

// en: Use the sieve of Eratosthenes to determine the number of primes
// less than N, for N = 10^3, 10^4, 10^5, and 10^6.

// ru: С помощью решета Эратосфена определите количество простых
// чисел, меньших N, для N = 10^3, 10^4, 10^5, 10^6

#include <iostream>
#include <vector>

#include "eratosthenes.h"

int main() {
    const std::vector<int> N = {1000, 10'000, 100'000, 1'000'000};
    for (auto n : N) {
        std::cout << "N = " << n << " count = " << prime_numbers_count(n)
                  << '\n';
    }
    return 0;
}
