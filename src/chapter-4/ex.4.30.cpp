#include <cstdlib>
#include <iostream>

#include "ex.4.30.h"

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
        if (info.unite(p, q)) {
            std::cout << ' ' << p << ' ' << q << '\n';
        }
    }

    return 0;
}
