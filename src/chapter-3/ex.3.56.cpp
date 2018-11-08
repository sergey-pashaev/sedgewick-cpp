// ex.3.56

// en: Write a program that checks whether a given string is a
// palindrome (reads the same backward or forward), ignoring
// blanks. For example, your program should report success for the
// string 'if i had a hifi'.

// ru: Напишите программу, которая определяет, является ли данная
// строка палиндромом (одинаково читается в прямом и обратном
// направлениях), если игнорировать пробелы.  Пример: "if i had a
// hifi"

#include <cstring>

#include <catch.hpp>

bool IsPalindrome(const char* str) {
    int len = strlen(str);
    int beg = 0;
    int end = len - 1;
    while (beg < len && end >= 0) {
        while (str[beg] == ' ') ++beg;
        while (str[end] == ' ') --end;

        if (str[beg++] != str[end--]) return false;
    }

    return true;
}

TEST_CASE("palindrome") {
    REQUIRE(IsPalindrome("if i had a hifi"));
    REQUIRE(IsPalindrome("  a b a "));
    REQUIRE(IsPalindrome("  a "));
    REQUIRE(IsPalindrome(" a b  c   b a"));
}

TEST_CASE("not a palindrome") { REQUIRE(!IsPalindrome("not a palindrome")); }
