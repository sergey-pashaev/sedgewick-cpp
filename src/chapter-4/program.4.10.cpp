// program.4.10

// en: Equivalence-relations ADT client

// ru: Клиент для АТД отношений эквивалентности

#include "program.4.11.h"

#include <cstdlib>
#include <iostream>

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

    UF info(N);
    int p, q;
    while (std::cin >> p >> q) {
        if (!info.Find(p, q)) {
            info.Unite(p, q);
            std::cout << ' ' << p << ' ' << q << '\n';
        }
    }

    return 0;
}
