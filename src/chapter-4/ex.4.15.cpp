// ex.4.15

// en: Extend your solution to Exercise 4.14 to include the unary
// operators - (negation) and $ (square root). Also, modify the
// abstract stack machine in Program 4.5 to use floating point. For
// example, given the expression:
//   (-(-1) + $((-1) * (-1)-(4 * (-1))))/2
// your program should print the value 1.618034.

// ru: Расширьте упражнение 4.14 таким образом, чтобы оно включало
// унарный операции - (смена знака) и $ (извлечение квадратного
// корня). Кроме того, измените механизм абстрактного стека в
// программе 4.5 так, чтобы можно было использовать числа с плавающей
// точкой. Например, имея в качестве исходного выражение:
//   (-(-1) + $((-1) * (-1) - (4 * (-1)))) / 2
// программа должна выдать число 1.618034.

#include <cmath>
#include <cstddef>
#include <iostream>
#include <stdexcept>

#include <catch.hpp>

#include <psv/stack.h>

template <typename T>
T EvalPostfix(const std::string& expr) {
    const auto size = expr.size();
    psv::Stack<T> value(size);

    for (std::size_t i = 0; i < size; ++i) {
        if (expr[i] == '+') value.Push(value.Pop() + value.Pop());
        if (expr[i] == '-') {
            auto v1 = value.Pop();
            auto v2 = value.Pop();
            value.Push(v2 - v1);
        }
        if (expr[i] == '*') value.Push(value.Pop() * value.Pop());
        if (expr[i] == '/') {
            auto v1 = value.Pop();
            if (v1 == 0) throw std::overflow_error("divide by zero");
            auto v2 = value.Pop();
            value.Push(v2 / v1);
        }
        if (expr[i] == '$') {
            value.Push(std::sqrt(value.Pop()));
        }
        if (expr[i] == '!') {
            value.Push(-value.Pop());
        }

        if (expr[i] >= '0' && expr[i] <= '9') value.Push(0);
        while (expr[i] >= '0' && expr[i] <= '9')
            value.Push(10 * value.Pop() + expr[i++] - '0');
    }

    return value.Pop();
}

bool IsNum(char c) { return c >= '0' && c <= '9'; }
bool IsVar(char c) { return std::isalpha(c); }
bool IsOp(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '$';
}
bool IsUnary(char c) { return c == '-' || c == '$' || c == '!'; }
bool IsRightAssoc(char c) { return c == '$' || c == '!'; }

int Precedence(char op) {
    switch (op) {
        case '(':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '!':
        case '$':
            return 3;
    }

    throw std::invalid_argument("invalid operator");
}

std::string ToPostfix(const std::string& expr) {
    const auto size = expr.size();
    psv::Stack<char> st(size);
    std::string ret;
    bool may_unary = true;
    for (std::size_t i = 0; i < size;) {
        if (IsNum(expr[i])) {
            // number
            while (IsNum(expr[i])) {
                ret.push_back(expr[i++]);
            }
            ret.push_back(' ');
            may_unary = false;
        } else if (IsVar(expr[i])) {
            // var
            while (IsVar(expr[i])) {
                ret.push_back(expr[i++]);
            }
            ret.push_back(' ');
            may_unary = false;
        } else if (expr[i] == '(') {
            st.Push(expr[i]);
            ++i;
            may_unary = true;
        } else if (expr[i] == ')') {
            while (!st.Empty() && st.Top() != '(') {
                ret.push_back(st.Pop());
                ret.push_back(' ');
            }
            if (!st.Empty() && st.Top() == '(') st.Pop();
            ++i;
            may_unary = false;
        } else if (IsOp(expr[i])) {
            // operator
            char op = expr[i];
            if (IsUnary(op) && may_unary) {
                if (op == '-') {
                    op = '!';
                }
            }

            while (
                !st.Empty() && st.Top() != '(' &&
                ((IsRightAssoc(op) && Precedence(st.Top()) > Precedence(op)) ||
                 (!IsRightAssoc(op) &&
                  Precedence(st.Top()) >= Precedence(op)))) {
                ret.push_back(st.Pop());
                ret.push_back(' ');
            }
            st.Push(op);
            ++i;
            may_unary = true;
        } else {
            // whitespace
            ++i;
        }
    }

    while (!st.Empty()) {
        auto c = st.Pop();
        if (c != '(') {
            ret.push_back(c);
            ret.push_back(' ');
        }
    }
    if (ret.back() == ' ') ret.resize(ret.size() - 1);

    return ret;
}

TEST_CASE("eval_postfix") {
    REQUIRE(EvalPostfix<double>(
                ToPostfix("((-(-1) + $((-1) * (-1) - (4 * (-1)))) / 2)")) ==
            Approx(1.618034));
}
