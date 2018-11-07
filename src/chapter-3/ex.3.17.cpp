// ex.3.17

// en: Write a program that determines empirically the number of
// random positive integers less than 1000 (N) that you can expect to
// generate before getting a repeated value.

// ru: Напишите программу, эмпирически определяющую количество
// случайных положительных чисел, меньших 1000(N), генерацию которых
// можно ожидать перед получением повторного значения.

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
    while (true) {
        int i = dist(gen);
        if (a[i]) break;
        a[i] = 1;
        ++cnt;
    }

    std::cout << "random numbers w/o repeat: " << cnt << '\n';

    return 0;
}
