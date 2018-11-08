// ex.3.49

// en: Implement the interface in Program 3.12 using new and delete
// directly in newNode and deleteNode, respectively.

// ru: Реализуйте интерфейс программы 3.12 с помощью непосредственных
// вызовов new и delete в функциях newNode и deleteNode
// соответственно.

#include <cstdlib>
#include <iostream>

#include "program.3.12.h"

int usage(const char* bin) {
    std::cout << "Usage: " << bin << " <positive int N> <positive int M>\n";
    return 1;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        return usage(argv[0]);
    }

    int N = std::atoi(argv[1]);
    int M = std::atoi(argv[2]);
    if (N <= 0 || M <= 0) {
        return usage(argv[0]);
    }

    Node t, x;
    construct(N);
    x = newNode(1);
    for (int i = 2; i <= N; ++i) {
        t = newNode(i);
        insert(x, t);
        x = t;
    }

    while (x != next(x)) {
        for (int i = 1; i < M; ++i) x = next(x);
        deleteNode(remove(x));
    }

    std::cout << item(x) << '\n';
    deleteNode(x);

    return 0;
}
