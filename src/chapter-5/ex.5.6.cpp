// ex.5.6

// en: Give the figure corresponding to Figure 5.2 for the result of
// running Euclid's algorithm for the inputs 89 and 55.

// ru: Приведите рисунок, соответствующий рис. 5.2, для результата
// выполнения алгоритма Евклида с числами 89 и 55.

#include <iomanip>
#include <iostream>

int gcd(int m, int n) {
    static int calls = 0;
    // indentation
    std::cout << std::setfill(' ') << std::setw(calls++) << "";
    // call params
    std::cout << "gcd(" << m << ", " << n << ")\n";

    if (n == 0) return m;
    return gcd(n, m % n);
}

int usage(const char* bin) {
    std::cout << "Usage: " << bin << " <positive int M> <positive int N>\n";
    return 1;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        return usage(argv[0]);
    }

    int m = std::atoi(argv[1]);
    int n = std::atoi(argv[2]);
    if (n <= 0 || m <= 0) {
        return usage(argv[0]);
    }

    gcd(m, n);

    return 0;
}
