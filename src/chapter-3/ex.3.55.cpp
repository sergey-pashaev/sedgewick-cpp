// ex.3.55

// en: Write a program that takes a string as argument, and that
// prints out a table giving, for each character that occurs in the
// string, the character and its frequency of occurrence.

// ru: Напишите программу, которая принимает строку в качестве
// аргумента и выводит таблицу со всеми имеющимися в строке символами
// и частотой появления каждого из них.

#include <array>
#include <iostream>
#include <limits>

int main() {
    std::string line;
    std::getline(std::cin, line);
    const int N = std::numeric_limits<char>::max() + 1;
    std::array<int, N> table = {};
    for (const char c : line) {
        ++table[static_cast<int>(c)];
    }

    for (int i = 0, n = 0; i < N; ++i) {
        if (table[i]) {
            std::cout << static_cast<char>(i) << ' ' << table[i];
            std::cout << (++n % 5 == 0 ? '\n' : '\t');
        }
    }
    std::cout << '\n';

    return 0;
}
