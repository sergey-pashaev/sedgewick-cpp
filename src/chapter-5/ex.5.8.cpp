// ex.5.8

// en: Give the figure corresponding to Figure 5.3 for the result of
// recursive prefix-expression evaluation for the input + * * 12 12 12
// 144.

// ru: Приведите рисунок, соответствующий рис. 5.3, для результата
// вычисления префиксного выражения + * * 12 12 12 144.

#include <iomanip>
#include <iostream>
#include <string>

std::string expr;
const char* a = nullptr;
int i = 0;

static int deep = 0;
void indent() { std::cout << std::setfill(' ') << std::setw(deep * 2) << ""; }
void incd() { ++deep; }
void decd() { --deep; }

std::string subexpr(const char* e) {
    const char* c = e;
    int operands = 2;

    // skip first operation
    ++c;

    while (operands > 0) {
        while (*c == ' ') ++c;

        if (*c == '+' || *c == '*') {
            operands += 1;
            ++c;
        }

        if (*c >= '0' && *c <= '9') {
            while (*c >= '0' && *c <= '9') ++c;
            --operands;
        }
    }

    return std::string(e, c - e);
}

int eval() {
    while (a[i] == ' ') ++i;

    if (a[i] == '+') {
        indent();
        std::cout << "eval() " << subexpr(a + i) << '\n';
        incd();

        ++i;
        int v1 = eval();
        int v2 = eval();

        indent();
        std::cout << "return " << v1 + v2 << " = " << v1 << '+' << v2 << '\n';
        decd();

        return v1 + v2;
    }

    if (a[i] == '*') {
        indent();
        std::cout << "eval() " << subexpr(a + i) << '\n';
        incd();

        ++i;
        int v1 = eval();
        int v2 = eval();

        indent();
        std::cout << "return " << v1 * v2 << " = " << v1 << '*' << v2 << '\n';
        decd();

        return v1 * v2;
    }

    int x = 0;
    while (a[i] >= '0' && a[i] <= '9') {
        x = 10 * x + a[i++] - '0';
    }

    indent();
    std::cout << "eval() " << x << '\n';

    return x;
}

int main() {
    for (; std::getline(std::cin, expr);) {
        a = expr.c_str();
        i = 0;
        std::cout << eval() << '\n';
    }

    return 0;
}
