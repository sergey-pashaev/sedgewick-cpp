// ex.4.47

// en: Write a client that tests your deque ADTs (Exercise 4.43) by
// reading, as the first argument on the command line, a string of
// commands like those given in Exercise 4.40 then performing the
// indicated operations. Add a member function dump to the interface
// and implementations, and print out the contents of the deque after
// each operation, in the style of Figure 4.6.

// ru: Напишите программу-клиент для тестирования АТД дека
// (упр. 4.43), которая считывает из командной строки в качестве
// первого аргумента строку команд, подобную приведенной в упр 4.40,
// после чего выполняет указанные операции. В интерфейс и реализации
// добавьте функцию-член dump и выводите содержимое дека после каждой
// операции как это сделано на рис. 4.6.

#include <cctype>
#include <iostream>

#include <psv/deque.h>

int usage(const char* bin) {
    std::cout << "Usage: " << bin << " <string>\n";
    return 1;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        return usage(argv[0]);
    }

    psv::Deque<char> d;
    char* input = argv[1];
    while (*input) {
        const char c = *input;
        std::cout << c << "  ";

        if (c == '+') {
            std::cout << d.PopFront() << "  ";
        } else if (c == '*') {
            std::cout << d.PopBack() << "  ";
        } else if (std::isupper(c)) {
            d.PushFront(c);
            std::cout << "   ";
        } else if (std::islower(c)) {
            d.PushBack(c);
            std::cout << "   ";
        }

        if (!d.Empty()) {
            d.Dump(std::cout);
        } else {
            std::cout << '\n';
        }

        ++input;
    }

    return 0;
}
