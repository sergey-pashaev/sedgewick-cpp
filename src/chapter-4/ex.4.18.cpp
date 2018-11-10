// ex.4.18

// en: Write a program that converts a postfix expression to infix,
// using a pushdown stack.

// ru: Напишите программу, которая преобразует постфиксное выражение в
// инфиксное, используя стэк магазинного типа.

#include <cmath>
#include <cstddef>
#include <iostream>
#include <sstream>
#include <stdexcept>

#include <catch.hpp>

#include <psv/stack.h>

template <typename T>
T eval_postfix(const std::string& expr) {
    const auto size = expr.size();
    psv::Stack<T> value(size);

    for (std::size_t i = 0; i < size; ++i) {
        if (expr[i] == '+') value.push(value.pop() + value.pop());
        if (expr[i] == '-') {
            auto v1 = value.pop();
            auto v2 = value.pop();
            value.push(v2 - v1);
        }
        if (expr[i] == '*') value.push(value.pop() * value.pop());
        if (expr[i] == '/') {
            auto v1 = value.pop();
            if (v1 == 0) throw std::overflow_error("divide by zero");
            auto v2 = value.pop();
            value.push(v2 / v1);
        }
        if (expr[i] == '$') {
            value.push(std::sqrt(value.pop()));
        }
        if (expr[i] == '!') {
            value.push(-value.pop());
        }

        if (expr[i] >= '0' && expr[i] <= '9') value.push(0);
        while (expr[i] >= '0' && expr[i] <= '9')
            value.push(10 * value.pop() + expr[i++] - '0');
    }

    return value.pop();
}

bool is_num(char c) { return c >= '0' && c <= '9'; }
bool is_var(char c) { return std::isalpha(c); }
bool is_op(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '$' || c == '!';
}
bool is_unary(char c) { return c == '-' || c == '$' || c == '!'; }
bool is_right_assoc(char c) { return c == '$' || c == '!'; }

int precedence(char op) {
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

std::string to_infix(const std::string& expr) {
    const auto size = expr.size();
    psv::Stack<std::string> value(size);
    for (std::size_t i = 0; i < size;) {
        if (is_op(expr[i])) {
            auto op = expr[i];
            switch (op) {
                case '+':
                case '-':
                case '*':
                case '/': {
                    auto v1 = value.pop();
                    auto v2 = value.pop();
                    std::string s;
                    s += '(';
                    s += v2;
                    s += ' ';
                    s += op;
                    s += ' ';
                    s += v1;
                    s += ')';
                    value.push(s);
                    break;
                }
                case '!':
                case '$': {
                    std::string s;
                    s += '(';
                    s += (op == '!' ? '-' : op);
                    s += value.pop();
                    s += ')';
                    value.push(s);
                    break;
                }
                default:
                    break;
            }
            ++i;
        } else if (is_num(expr[i])) {
            std::string s;
            while (is_num(expr[i])) {
                s += expr[i++];
            }
            value.push(s);
        } else {
            // whitespace
            ++i;
        }
    }

    return value.pop();
}

std::string to_postfix(const std::string& expr) {
    const auto size = expr.size();
    psv::Stack<char> st(size);
    std::string ret;
    bool may_unary = true;
    for (std::size_t i = 0; i < size;) {
        if (is_num(expr[i])) {
            // number
            while (is_num(expr[i])) {
                ret.push_back(expr[i++]);
            }
            ret.push_back(' ');
            may_unary = false;
        } else if (is_var(expr[i])) {
            // var
            while (is_var(expr[i])) {
                ret.push_back(expr[i++]);
            }
            ret.push_back(' ');
            may_unary = false;
        } else if (expr[i] == '(') {
            st.push(expr[i]);
            ++i;
            may_unary = true;
        } else if (expr[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                ret.push_back(st.pop());
                ret.push_back(' ');
            }
            if (!st.empty() && st.top() == '(') st.pop();
            ++i;
            may_unary = false;
        } else if (is_op(expr[i])) {
            // operator
            char op = expr[i];
            if (is_unary(op) && may_unary) {
                if (op == '-') {
                    op = '!';
                }
            }

            while (!st.empty() && st.top() != '(' &&
                   ((is_right_assoc(op) &&
                     precedence(st.top()) > precedence(op)) ||
                    (!is_right_assoc(op) &&
                     precedence(st.top()) >= precedence(op)))) {
                ret.push_back(st.pop());
                ret.push_back(' ');
            }
            st.push(op);
            ++i;
            may_unary = true;
        } else {
            // whitespace
            ++i;
        }
    }

    while (!st.empty()) {
        auto c = st.pop();
        if (c != '(') {
            ret.push_back(c);
            ret.push_back(' ');
        }
    }
    if (ret.back() == ' ') ret.resize(ret.size() - 1);

    return ret;
}

TEST_CASE("eval_postfix") {
    REQUIRE(eval_postfix<double>(
                to_postfix("((-(-1) + $((-1) * (-1) - (4 * (-1)))) / 2)")) ==
            Approx(1.618034));
    REQUIRE(eval_postfix<double>(to_postfix(to_infix(
                to_postfix("((-(-1) + $((-1) * (-1) - (4 * (-1)))) / 2)")))) ==
            Approx(1.618034));
}
