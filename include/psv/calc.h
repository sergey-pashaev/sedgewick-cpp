#ifndef PSV_CALC_H
#define PSV_CALC_H

#include <cctype>
#include <cmath>
#include <cstddef>
#include <stack>
#include <stdexcept>
#include <string>
#include <unordered_map>

namespace psv {

class Calculator {
   public:
    double Eval(const std::string& expr) {
        return EvalPostfix(ToPostfix(expr));
    }

    void Reset() { vars_.clear(); }

   private:
    enum Association { NONE, LEFT, RIGHT };

    struct Operator {
        char op;
        char rep;  // intermidiate representation
        int precedence;
        Association assoc;
        bool unary;
    };

    // clang-format off
    static constexpr Operator operators[] = {
        {'-', '!', 4, RIGHT, true},
        {'$', '$', 4, RIGHT, true},
        {'*', '*', 3, LEFT, false},
        {'/', '/', 3, LEFT, false},
        {'+', '+', 2, LEFT, false},
        {'-', '-', 2, LEFT, false},
        {'=', '=', 1, RIGHT, false},
        {'(', '(', 0, NONE, false},
        {')', ')', 0, NONE, false},
    };
    // clang-format on

    static const Operator* GetOperator(char c, bool may_unary) {
        for (std::size_t i = 0; i < 9; ++i) {
            if (operators[i].op == c && operators[i].unary == may_unary)
                return &operators[i];
        }

        return nullptr;
    }

    int Precedence(char op) {
        switch (op) {
            case '(':
            case ')':
                return 0;
            case '=':
                return 1;
            case '+':
            case '-':
                return 2;
            case '*':
            case '/':
                return 3;
            case '!':
            case '$':
                return 4;
        }

        throw std::invalid_argument("invalid operator");
    }

    std::string ToPostfix(const std::string& expr) {
        const auto size = expr.size();
        std::stack<char> oper;
        std::string ret;
        ret.resize(expr.size());
        bool may_unary = true;

        for (std::size_t i = 0; i < size;) {
            if (std::isdigit(expr[i])) {
                while (std::isdigit(expr[i])) {
                    ret.push_back(expr[i++]);
                }
                ret.push_back(' ');
                may_unary = false;
            } else if (std::isalpha(expr[i])) {
                ret.push_back(expr[i++]);
                ret.push_back(' ');
                may_unary = false;
            } else if (expr[i] == '(') {
                oper.push(expr[i++]);
                may_unary = true;
            } else if (expr[i] == ')') {
                while (!oper.empty() && oper.top() != '(') {
                    ret.push_back(oper.top());
                    ret.push_back(' ');
                    oper.pop();
                }

                if (!oper.empty() && oper.top() == '(') {
                    oper.pop();
                } else {
                    throw std::invalid_argument("unbalanced parentheses");
                }

                ++i;
                may_unary = false;
            } else if (const Operator* op = GetOperator(expr[i], may_unary)) {
                while (!oper.empty() && oper.top() != '(' &&
                       ((op->assoc == RIGHT &&
                         Precedence(oper.top()) > Precedence(op->rep)) ||
                        (op->assoc == LEFT &&
                         Precedence(oper.top()) >= Precedence(op->rep)))) {
                    ret.push_back(oper.top());
                    ret.push_back(' ');
                    oper.pop();
                }

                oper.push(op->rep);
                ++i;
                may_unary = true;
            } else {
                // whitespace
                ++i;
            }
        }

        while (!oper.empty()) {
            if (oper.top() != '(') {
                ret.push_back(oper.top());
                ret.push_back(' ');
                oper.pop();
            }
        }

        if (ret.back() == ' ') ret.resize(ret.size() - 1);

        return ret;
    }

    double EvalPostfix(const std::string& expr) {
        const auto size = expr.size();
        std::stack<double> value;
        std::stack<char> vars;

        for (std::size_t i = 0; i < size; ++i) {
            if (expr[i] == '+') {
                auto v1 = value.top();
                value.pop();
                auto v2 = value.top();
                value.pop();
                value.push(v2 + v1);
            } else if (expr[i] == '-') {
                auto v1 = value.top();
                value.pop();
                auto v2 = value.top();
                value.pop();
                value.push(v2 - v1);
            } else if (expr[i] == '*') {
                auto v1 = value.top();
                value.pop();
                auto v2 = value.top();
                value.pop();
                value.push(v2 * v1);
            } else if (expr[i] == '/') {
                auto v1 = value.top();
                if (v1 == 0) throw std::overflow_error("divide by zero");
                value.pop();
                auto v2 = value.top();
                value.pop();
                value.push(v2 / v1);
            } else if (expr[i] == '$') {
                auto v1 = value.top();
                value.pop();
                value.push(std::sqrt(v1));
            } else if (expr[i] == '!') {
                auto v1 = value.top();
                value.pop();
                value.push(-v1);
            } else if (expr[i] == '=') {
                auto var = vars.top();
                vars.pop();
                vars_[var] = value.top();
            } else if (std::isalpha(expr[i])) {
                if (vars_.find(expr[i]) != vars_.end()) {
                    value.push(vars_[expr[i]]);
                } else {
                    vars.push(expr[i]);
                }
            } else if (std::isdigit(expr[i])) {
                value.push(0);
                while (std::isdigit(expr[i])) {
                    auto v = value.top();
                    value.pop();
                    value.push(10 * v + expr[i++] - '0');
                }
            }
        }

        return value.top();
    }

   private:
    std::unordered_map<char, double> vars_;
};

constexpr Calculator::Operator Calculator::operators[];

}  // namespace psv

#endif /* PSV_CALC_H */
