// program.4.6

// en: Infix-to-postfix conversion

// ru: Преобразование из инфиксной формы в постфиксную

#include <cstring>
#include <iostream>

#include <psv/stack.h>

int main() {
    std::string expr;
    std::getline(std::cin, expr);
    const char* a = expr.c_str();
    std::size_t N = std::strlen(a);
    psv::Stack<char> ops(N);

    for (std::size_t i = 0; i < N; ++i) {
        if (a[i] == ')') {
            std::cout << ops.Pop() << (i + 1 < N ? ' ' : '\n');
        }
        if (a[i] == '+' || a[i] == '*') {
            ops.Push(a[i]);
        }
        if (a[i] >= '0' && a[i] <= '9') {
            std::cout << a[i] << (i + 1 < N ? ' ' : '\n');
        }
    }

    // FIXME: weird output, all digits separated by spaces

    return 0;
}
