// program.4.6

// en: Infix-to-postfix conversion

// ru: Преобразование из инфиксной формы в постфиксную

#include <cstring>
#include <iostream>

#include <psv/stack.h>

int usage(const char* bin) {
    std::cout << "Usage: " << bin << " <string expression>\n";
    return 1;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        return usage(argv[0]);
    }

    char* a = argv[1];
    std::size_t N = std::strlen(a);
    psv::Stack<char> ops(N);

    for (std::size_t i = 0; i < N; ++i) {
        if (a[i] == ')') {
            std::cout << ops.pop() << (i + 1 < N ? ' ' : '\n');
        }
        if (a[i] == '+' || a[i] == '*') {
            ops.push(a[i]);
        }
        if (a[i] >= '0' && a[i] <= '9') {
            std::cout << a[i] << (i + 1 < N ? ' ' : '\n');
        }
    }

    // FIXME: weird output, all digits separated by spaces

    return 0;
}
