// ex.4.20

// en: Implement a compiler and interpreter for a programming language
// where each program consists of a single arithmetic expression
// preceded by a sequence of assignment statements with arithmetic
// expressions involving integers and variables named with single
// lower-case characters. For example, given the input
//   (x = 1)
//   (y = (x + 1))
//   (((x + y) * 3) + (4 * x))
// your program should print the value 13.

// ru: Напишите компилятор и интерпретатор для языка программирования,
// в котором каждая программа состоит из одного арфиметического
// выражения. Выражению может предшествовать ряд операторов
// присваивания с арифметическими выражениями, сотостоящими из целых
// чисел и переменных, обозначаемых одиночными строчными
// буквами. Например, получив входные данные:
//   (x = 1)
//   (y = (x + 1))
//   (((x + y) * 3) + (4 * x))
// программа должна вывести число 13.

#include <iostream>
#include <string>

#include <psv/calc.h>

// TODO: add "real" compilation to some bytecode or machine code

int main() {
    psv::Calculator c;
    std::cout << '>';
    for (std::string expr; std::getline(std::cin, expr); std::cout << '>') {
        std::cout << ' ' << c.Eval(expr) << '\n';
    }

    std::cout << '\n';
    return 0;
}
