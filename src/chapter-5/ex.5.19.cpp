// ex.5.19

// en: Draw the tree corresponding to the recursive calls that your
// program from Exercise 5.18 makes when the array size is 11.

// ru: Нарисуйте дерево, которое соответствует рекурсивным вызовам,
// выполняемым программой из упражнения 5.18 при размере массива 11.

#include <cmath>
#include <iostream>

#include <catch.hpp>

template <typename T>
T max(T a[], int l, int r) {
    static int deep = 0;

    std::cout << std::string(deep * 2, ' ') << "max(a, " << l << ", " << r
              << ")\n";
    ++deep;

    if (l == r) {
        --deep;
        return a[l];
    }
    const int size = r - l + 1;
    const int k = std::pow(2, std::ceil(std::log2(size)) - 1);
    T u = max(a, l, l + k - 1);
    T v = max(a, l + k, r);
    --deep;
    return u > v ? u : v;
}

int main() {
    const int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    max(a, 0, 10);
    return 0;
}
