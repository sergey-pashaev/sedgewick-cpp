// program 5.2

// en: A questionable recursive program

// ru: Сомнительная рекурсивная программа

#include <iostream>

int puzzle(int n) {
    std::cout << "puzzle(" << n << ")\n";
    if (n == 1) return 1;
    if (n % 2 == 0)
        return puzzle(n / 2);
    else
        return puzzle(3 * n + 1);
}

int usage(const char* bin) {
    std::cout << "Usage: " << bin << " <positive int N>\n";
    return 1;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        return usage(argv[0]);
    }

    int n = std::atoi(argv[1]);
    if (n <= 0) {
        return usage(argv[0]);
    }

    puzzle(n);

    return 0;
}
