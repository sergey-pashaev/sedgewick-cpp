// ex.4.42

// en: Given two sequences, give an algorithm for determining whether
// or not it is possible to add plus signs and asterisks to make the
// first produce the second when interpreted as a sequence of deque
// operations in the sense of Exercise 4.41.

// ru: Приведите алгоритм, позволяющий определить для двух данных
// последовательностей, можно ли в первую последовательность вставить
// плюсы и звёздочки так, чтобы, интерпретирую ее как
// последовательность операций над деком в смысле упр. 4.41 получить
// вторую последовательность.

#include <cctype>
#include <iostream>

#include <catch.hpp>

#include <psv/deque.h>
#include <psv/queue.h>

char Push(char c, psv::Deque<char>& q) {
    if (std::islower(c)) {
        q.PushBack(c);
    } else {
        q.PushFront(c);
    }

    return c;
}

char Pop(char c, psv::Deque<char>& d) {
    if (std::islower(c)) {
        d.PopBack();
        return '*';
    } else {
        d.PopFront();
        return '+';
    }
}

// Idea is to try to produce desired output sequence until some
// impossible operation to perform happens.
bool IsDequeable(const char* in_c, const char* res_c) {
    psv::Queue<char> q;
    for (; *in_c; ++in_c) {
        q.Push(*in_c);
    }

    psv::Deque<char> d;
    for (; *res_c; ++res_c) {
        const char out = *res_c;

        // pop if possible
        if (!d.Empty()) {
            if (out == d.Front()) {
                d.PopFront();
                std::cout << "+ ";
                continue;
            } else if (out == d.Back()) {
                d.PopBack();
                std::cout << "* ";
                continue;
            } else {
                if (q.Empty()) {
                    std::cout << " impossible\n";
                    return false;
                }
            }
        }

        if (!q.Empty()) {
            while (!q.Empty() && q.Front() != out) {
                std::cout << Push(q.Pop(), d) << ' ';
            }

            if (q.Empty()) {
                std::cout << " impossible\n";
                return false;
            }

            // push & pop
            auto in = q.Pop();
            std::cout << Push(in, d) << ' ';
            std::cout << Pop(in, d) << ' ';
        }
    }

    std::cout << '\n';
    return true;
}

TEST_CASE("IsDequeable positive") {
    REQUIRE(IsDequeable("E", "E"));
    REQUIRE(IsDequeable("Ea", "Ea"));
    REQUIRE(IsDequeable("Ea", "aE"));
    REQUIRE(IsDequeable("EasY", "EsaY"));
    REQUIRE(IsDequeable("EasY", "aYsE"));
    REQUIRE(IsDequeable("EasY", "asYE"));
}

TEST_CASE("IsDequeable negative") {
    REQUIRE_FALSE(IsDequeable("E", "A"));
    REQUIRE_FALSE(IsDequeable("EasY", "YasE"));
}
