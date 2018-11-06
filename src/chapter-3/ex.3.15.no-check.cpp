// ex.3.15.no-check

// en: Empirically determine the effect of removing the test of a[i]
// from the inner loop of Program 3.5, for N = 10^3, 10^4, 10^5, and
// 10^6, and explain the effect that you observe.

// ru: Эмпирически определите эффект удаления проверки a[i] из
// внутреннего цикла программы 3.5 для N = 10^3, 10^4, 10^5, 10^6 и
// объясните его.

#include <iostream>
#include <vector>

int usage(const char* bin) {
    std::cout << "Usage: " << bin << " <positive int N>\n";
    return 1;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        return usage(argv[0]);
    }

    int N = std::atoi(argv[1]);
    if (N <= 0) {
        return usage(argv[0]);
    }

    std::vector<int> a(N, 1);
    for (int i = 2; i < N; ++i) {
        // use long to prevent int overflow
        for (long j = i; j * i < N; ++j) a[i * j] = 0;
    }
    return 0;
}
