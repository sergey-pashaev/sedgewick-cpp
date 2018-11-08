// ex.3.58

// en: Write a program that takes a string as argument and reads a
// sequence of words (sequences of characters separated by blank
// space) from standard input, printing out those that appear as
// substrings somewhere in the argument string.

// ru: Напишите программу, которая принимает строку в качестве
// аргумента и читает ряд слов (последовательностей символов,
// разделенных пробелами) из стандартного ввода, выводя те из них,
// которые входят как подстроки в строку аргумента.

#include <iostream>
#include <string>

#include <psv/string.h>

int usage(const char* bin) {
    std::cout << "Usage: " << bin << " <string>\n";
    return 1;
}

bool find(const char* str, const char* pattern) {
    auto ssize = psv::strlen(str);
    auto psize = psv::strlen(pattern);

    if (ssize < psize) return false;

    std::size_t i, j;
    for (i = 0; i <= ssize - psize; ++i) {
        for (j = 0; j < psize; ++j) {
            if (str[i + j] != pattern[j]) break;
        }

        if (j == psize) return true;
    }

    return false;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        return usage(argv[0]);
    }

    const char* str = argv[1];
    std::string word;
    while (std::cin >> word) {
        if (find(str, word.c_str())) std::cout << word << '\n';
    }

    return 0;
}
