// program.3.5

// en: Sieve of Eratosthenes

// ru: Решето Эратосфена

#include <iostream>

static const int N = 1000;

int main() {
    int i;
    int a[N];

    for (i = 2; i < N; ++i) a[i] = 1;
    for (i = 2; i < N; ++i) {
        if (a[i]) {
            for (int j = i; j * i < N; ++j) a[i * j] = 0;
        }
    }

    for (i = 2; i < N; ++i) {
        if (a[i]) std::cout << ' ' << i;
    }
    std::cout << '\n';
    return 0;
}
