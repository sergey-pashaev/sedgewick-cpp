#ifndef ERATOSTHENES_H
#define ERATOSTHENES_H

#include <vector>

int PrimeNumbersCount(int N) {
    std::vector<char> a(N, 1);
    for (int i = 2; i < N; ++i) {
        if (a[i]) {
            // use long to prevent int overflow
            for (long j = i; j * i < N; ++j) {
                a[i * j] = 0;
            }
        }
    }

    int cnt = 0;
    for (int i = 2; i < N; ++i) {
        if (a[i]) ++cnt;
    }

    return cnt;
}

#endif /* ERATOSTHENES_H */
