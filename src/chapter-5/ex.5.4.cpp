// ex.5.4

// en: Find the value of N < 10^6 for which Program 5.2 makes the
// maximum number of recursive calls.

// ru: Найдите значение N < 10^6, при котором программа 5.2 выполняет
// максимальное количество рекурсивных вызовов.

#include <cstdint>
#include <iostream>

static uint64_t calls = 0;

uint64_t puzzle(uint64_t n) {
    ++calls;
    if (n == 1) return 1;
    if (n % 2 == 0)
        return puzzle(n / 2);
    else
        return puzzle(3 * n + 1);
}

int main() {
    uint64_t max = 0;
    uint64_t ret = 0;
    for (uint64_t i = 1; i < 1'000'000; ++i) {
        calls = 0;
        puzzle(i);
        if (calls > max) {
            max = calls;
            ret = i;
        }
    }

    std::cout << ret << '\n';

    return 0;
}
