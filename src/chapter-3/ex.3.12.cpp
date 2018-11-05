// ex.3.12

// en: Use the sieve of Eratosthenes to determine the number of primes
// less than N, for N = 10^3, 10^4, 10^5, and 10^6.

// ru: С помощью решета Эратосфена определите количество простых
// чисел, меньших N, для N = 10^3, 10^4, 10^5, 10^6

#include <iostream>
#include <vector>

int prime_numbers_count(int N) {
    char* a = new char[N];
    for (int i = 0; i < N; ++i) a[i] = 1;
    int cnt = 0;
    for (int i = 2; i < N; ++i) {
        if (a[i]) {
            // use long to prevent int overflow
            for (long j = i; j * i < N; ++j) {
                a[i * j] = 0;
                ++cnt;
            }
        }
    }

    delete[] a;

    return cnt;
}

int main() {
    const std::vector<int> N = {1000, 10'000, 100'000, 1'000'000};
    for (auto n : N) {
        std::cout << "N = " << n << " count = " << prime_numbers_count(n)
                  << '\n';
    }
    return 0;
}
