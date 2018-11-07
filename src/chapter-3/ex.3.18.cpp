// ex.3.18

// en: Write a program that determines empirically the number of
// random positive integers less than 1000 that you can expect to
// generate before getting each value at least once.

// ru: Напишите программу, эмпирически определяющую количество
// случайных положительных чисел, меньших 1000 (N), генерацию которых
// можно ожидать до получения каждого значения хотя бы один раз.

#include <iostream>
#include <random>
#include <vector>

int usage(const char* bin) {
    std::cout << "Usage: " << bin << " <positive int N>\n";
    return 1;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        return usage(argv[0]);
    }

    const int N = std::atoi(argv[1]);
    if (N <= 0) {
        return usage(argv[0]);
    }

    std::vector<char> a(N, 0);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, N - 1);

    int cnt = 0;
    int matches = 0;
    while (matches < N) {
        const int i = dist(gen);
        if (!a[i]) {
            a[i] = 1;
            ++matches;
        }

        ++cnt;
    }

    std::cout << "random numbers till N matches: " << cnt << '\n';

    return 0;
}
