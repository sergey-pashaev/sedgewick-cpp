// ex.4.14

// en: Extend Programs 4.5 and 4.6 to include the - (subtract) and /
// (divide) operations.

// ru: Расширьте программы 4.5 и 4.6 таким образом, чтобы они
// обрабатывали операции - (вычитание) и / (деление).

#include <cstddef>
#include <iostream>
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

        if (expr[i] >= '0' && expr[i] <= '9') value.push(0);
        while (expr[i] >= '0' && expr[i] <= '9')
            value.push(10 * value.pop() + expr[i++] - '0');
    }

    return value.pop();
}

std::string to_postfix(const std::string& expr) {
    const auto size = expr.size();
    psv::Stack<char> op(size);
    std::string ret;
    for (std::size_t i = 0; i < size; ++i) {
        if (expr[i] >= '0' && expr[i] <= '9') {
            while (expr[i] >= '0' && expr[i] <= '9') {
                ret.push_back(expr[i++]);
            }
            ret.push_back(' ');
        }
        if (expr[i] == ')') {
            ret.push_back(op.pop());
            ret.push_back(' ');
        }
        if (expr[i] == '+' || expr[i] == '*' || expr[i] == '/' ||
            expr[i] == '-') {
            op.push(expr[i]);
        }
    }

    if (ret.back() == ' ') ret.resize(ret.size() - 1);

    return ret;
}

TEST_CASE("eval_postfix") {
    REQUIRE(eval_postfix<int>("10 2 +") == 12);
    REQUIRE(eval_postfix<int>("2 12 *") == 24);
    REQUIRE(eval_postfix<int>("5 9 * 8 7 4 6 + * 2 1 3 * + * + *") == 16110);
    REQUIRE(eval_postfix<int>("5 9 8 + 4 6 * * 7 + *") == 2075);

    // minus
    REQUIRE(eval_postfix<int>("2 2 -") == 0);
    REQUIRE(eval_postfix<int>("3 2 -") == 1);
    REQUIRE(eval_postfix<int>("2 3 -") == -1);

    // division
    REQUIRE(eval_postfix<int>("3 3 /") == 1);
    REQUIRE(eval_postfix<int>("6 3 /") == 2);
    REQUIRE(eval_postfix<int>("3 6 /") == 0);

    // order of calc
    REQUIRE(eval_postfix<int>("10 15 - 3 *") == -15);
    REQUIRE(eval_postfix<int>("15 7 1 1 + - / 3 * 2 1 1 + + -") == 5);
}

TEST_CASE("to_postfix") {
    using Catch::Matchers::Equals;
    REQUIRE_THAT(to_postfix("(1 + 2)"), Equals("1 2 +"));
    REQUIRE_THAT(to_postfix("(2 * 3)"), Equals("2 3 *"));
    REQUIRE_THAT(to_postfix("(22 * 33)"), Equals("22 33 *"));
    REQUIRE_THAT(to_postfix("(5 * ((9 * 8) + (7 * (4 + 6))))"),
                 Equals("5 9 8 * 7 4 6 + * + *"));
    REQUIRE_THAT(to_postfix("(5 * (((9 + 8) * (4 * 6)) + 7))"),
                 Equals("5 9 8 + 4 6 * * 7 + *"));
    REQUIRE_THAT(to_postfix("((10 - 15) * 3)"), Equals("10 15 - 3 *"));
    REQUIRE_THAT(to_postfix("(((1 + 2) * 4) / 3)"), Equals("1 2 + 4 * 3 /"));
}
