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

int usage(const char* bin) {
    std::cout << "Usage: " << bin << " <string>\n";
    return 1;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        return usage(argv[0]);
    }

    const int N = std::numeric_limits<char>::max() + 1;
    std::array<int, N> table = {};
    for (const char* str = argv[1]; *str; ++str) {
        ++table[static_cast<int>(*str)];
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
