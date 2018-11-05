// ex.3.11.bit

// en: Modify our implementation of the sieve of Eratosthenes (Program
// 3.5) to use an array of (i) chars; and (ii) bits. Determine the
// effects of these changes on the amount of space and time used by
// the program.

// ru: Измените реализацию решета Эратосфена (program.3.5) для
// использования массива (1) символов и (2) разрядов. Определите
// влияние этих изменений на расход памяти и времени, используемых
// программой.

#include <bitset>
#include <iostream>

static const int N = 1000;

int main() {
    int i;
    std::bitset<N> a;

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
