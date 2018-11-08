#ifndef PSV_STRING_H
#define PSV_STRING_H

#include <cstddef>

namespace psv {

const std::size_t TRAILING_ZERO = 1;

std::size_t strlen(const char* str) {
    auto p = str;
    while (*p++)
        ;

    return p - str - 1;
}

char* strcpy(const char* src) {
    const std::size_t size = strlen(src);
    char* dest = new char[size + TRAILING_ZERO];
    char* p = dest;
    while ((*p++ = *src++))
        ;

    return dest;
}

char* strcat(const char* a, const char* b) {
    const std::size_t a_size = strlen(a);
    const std::size_t b_size = strlen(b);

    char* res = new char[a_size + b_size + TRAILING_ZERO];
    char* p = res;
    while ((*p++ = *a++))
        ;

    --p;  // rewrite trailing zero

    while ((*p++ = *b++))
        ;
    return res;
}

int strcmp(const char* a, const char* b) {
    while (*a++ == *b++) {
        if (*(a - 1) == 0) return 0;
    }
    return *(a - 1) - *(b - 1);
}

}  // namespace psv

#endif /* PSV_STRING_H */
