// ex.3.57

// en: Suppose that memory for strings is individually
// allocated. Write versions of strcpy and strcat that allocate memory
// and return a pointer to the new string for the result.

// ru: Предположим, что память для строк выделяется
// индивидуально. Напишите версии функций strcpy и strcat, которые
// выделяют память и возвращают указатель на новую строку результат.

#include <string>

#include <catch.hpp>

#include <psv/string.h>

using Catch::Matchers::Equals;

void CompareCopy(const char* str) {
    auto copy = psv::strcpy(str);

    REQUIRE(psv::strcmp(str, copy) == 0);
    REQUIRE_THAT(copy, Equals(str));

    delete[] copy;
}

void CompareAppend(const char* str1, const char* str2) {
    auto res = psv::strcat(str1, str2);

    std::string buf{str1};
    buf.append(str2);

    REQUIRE(psv::strcmp(buf.c_str(), res) == 0);
    REQUIRE_THAT(res, Equals(buf));

    delete[] res;
}

TEST_CASE("strcpy empty") { CompareCopy(""); }

TEST_CASE("strcpy 1 char") { CompareCopy("a"); }

TEST_CASE("strcpy multiple char") { CompareCopy("abc"); }

TEST_CASE("strcat empty") {
    CompareAppend("", "");
    CompareAppend("a", "");
    CompareAppend("", "a");
}

TEST_CASE("strcat 1 char") {
    CompareAppend("a", "b");
    CompareAppend("a", "bc");
    CompareAppend("ab", "c");
}

TEST_CASE("strcat multiple char") {
    CompareAppend("abc", "def");
    CompareAppend("abcd", "ef");
    CompareAppend("ab", "cdef");
}
