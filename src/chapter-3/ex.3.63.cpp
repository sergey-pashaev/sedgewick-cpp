// ex.3.63

// en: Modify Program 3.17 to process input strings individually
// (allocate memory for each string after reading it from the
// input). You can assume that all strings have less than 100
// characters.

// ru: Измените программу 3.17 для индивидуальной обработки вводимых
// строк (память выделяется каждой строке после считывания её из
// ввода). Можно предположить, что длина любой строки не превышает 100
// символов.

#include <cstdlib>
#include <cstring>
#include <iostream>

int Compare(const void* i, const void* j) {
    return strcmp(*(char**)i, *(char**)j);
}

int main() {
    const int wordsMax = 1000;
    const int bufMax = 100;

    char* a[wordsMax];
    char buf[bufMax];

    int N;
    for (N = 0; N < wordsMax; ++N) {
        if (!(std::cin >> buf)) break;
        auto wsize = strlen(buf);
        auto w = new char[wsize + 1];
        a[N] = strcpy(w, buf);
    }

    qsort(a, N, sizeof(char*), Compare);

    for (int i = 0; i < N; ++i) std::cout << a[i] << '\n';

    for (int i = 0; i < N; ++i) {
        delete[] a[i];
    }
}
