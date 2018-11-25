// program.4.5

// en: Postfix-expression evaluation

// ru: Вычисление постфиксного выражения

#include <cstring>
#include <iostream>

#include <psv/stack.h>

int main() {
    std::string expr;
    std::getline(std::cin, expr);
    const char* a = expr.c_str();
    std::size_t N = std::strlen(a);
    psv::Stack<int> save(N);

    for (std::size_t i = 0; i < N; ++i) {
        if (a[i] == '+') save.Push(save.Pop() + save.Pop());
        if (a[i] == '*') save.Push(save.Pop() * save.Pop());
        if (a[i] >= '0' && a[i] <= '9') save.Push(0);
        while (a[i] >= '0' && a[i] <= '9')
            save.Push(10 * save.Pop() + a[i++] - '0');
    }

    std::cout << save.Pop() << '\n';

    return 0;
}
