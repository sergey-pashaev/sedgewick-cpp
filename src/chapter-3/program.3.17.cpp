// program.3.17

// en: Sorting an array of strings

// ru: Сортировка массива строк.

#include <cstdlib>
#include <cstring>
#include <iostream>

int Compare(const void* i, const void* j) {
    return strcmp(*(char**)i, *(char**)j);
}

int main() {
    const int Nmax = 1000;
    const int Mmax = 10000;

    char* a[Nmax];
    int N;
    char buf[Mmax];
    int M = 0;

    for (N = 0; N < Nmax; ++N) {
        a[N] = &buf[M];
        if (!(std::cin >> a[N])) break;
        M += strlen(a[N]) + 1;
    }

    qsort(a, N, sizeof(char*), Compare);

    for (int i = 0; i < N; ++i) std::cout << a[i] << '\n';
}
