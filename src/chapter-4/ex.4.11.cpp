// ex.4.11

// en: Given two sequences, give an algorithm for determining whether
// or not asterisks can be added to make the first produce the second,
// when interpreted as a sequence of stack operations in the sense of
// Exercise 4.10.

// ru: Предположим, что даны две последовательности букв. Разработайте
// алгоритм, позволяющий определить, можно ли в первую
// последовательность добавить звёздочки так, чтобы эта
// последовательность, выполненная как последовательность стековых
// операций (в смысле упражнения 4.10), дала в результате вторую
// последовательность.

#include <iostream>
#include <string>

#include <catch.hpp>

// Idea is to try to produce desired output sequence until some
// impossible operation to perform happens.
bool IsStackable(const char* in_c, const char* res_c) {
    std::string in(in_c);
    std::string res(res_c);

    const std::size_t isize = in.size();
    const std::size_t rsize = res.size();
    // we start with push because of empty stack
    bool push = true;
    std::size_t i = 0;
    // iterate over desired result
    for (std::size_t r = 0; r < rsize; ++r) {
        if (push) {
            // skip striked out symbols
            while (i < isize && in[i] == '.') ++i;

            // push until desired symbol is found
            while (i < isize && in[i] != res[r]) {
                std::cout << in[i++] << ' ';
            }

            // end of input - symbol not found
            if (i == isize) {
                std::cout << " impossible (\'" << res[r]
                          << "\' is not found in input string)\n";
                return false;
            }

            // symbol found
            // push input
            std::cout << in[i] << ' ';
            // pop output
            std::cout << "* ";

            // strike it out
            in[i] = res[r] = '.';

            // start popping if we at the end of input
            if (i == isize - 1) {
                push = false;
            }
        } else {
            // skip striked out symbols
            while (i > 0 && in[i] == '.') --i;

            // beginning of input - symbol not found
            if (i == 0 && in[i] == '.') {
                std::cout << " impossible (\'" << res[r]
                          << "\' is not found in input string)\n";
                return false;
            }

            if (in[i] == res[r]) {
                // symbol found
                // pop output
                std::cout << "* ";

                // strike it out
                in[i] = res[r] = '.';

                // advance in input
                if (i > 0) --i;
            } else {
                // symbol not found
                std::cout
                    << " impossible (\'" << in[i]
                    << "\' at the top of the stack and we expecting to pop \'"
                    << res[r] << "\')\n";
                return false;
            }
        }
    }

    std::cout << '\n';
    return true;
}

TEST_CASE("positive") {
    REQUIRE(IsStackable("E", "E"));
    REQUIRE(IsStackable("EA", "AE"));
    REQUIRE(IsStackable("EAS", "ESA"));
    REQUIRE(IsStackable("EAS", "SAE"));
    REQUIRE(IsStackable("EASY", "EASY"));
    REQUIRE(IsStackable("EASY", "YSAE"));
    REQUIRE(IsStackable("EASY", "ASYE"));
}

TEST_CASE("negative") {
    REQUIRE_FALSE(IsStackable("E", "A"));
    REQUIRE_FALSE(IsStackable("E", "EA"));
    REQUIRE_FALSE(IsStackable("EASY", "AYES"));
    REQUIRE_FALSE(IsStackable("ABC", "CAB"));
}
