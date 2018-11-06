// ex.3.14

// en: The C++ standard library includes the Vector data type as an
// alternative to arrays. Find out how to use this data type on your
// system, and determine the effect on the runtime when you replace
// the array in Program 3.5 by a Vector.

// ru: Стандартная библиотека С++ в качестве альтернативы массивам
// содержит тип данных vector. Узнайте, как использовать этот тип
// данных в своей системе, и определите его влияние на время
// выполнения, если заменить в программе 3.5 массив типом vector.

#include <iostream>
#include <vector>

static const int N = 1000;

int main() {
    int i;
    std::vector<int> a(N, 1);
    for (i = 2; i < N; ++i) {
        if (a[i]) {
            for (int j = i; j * i < N; ++j) a[i * j] = 0;
        }
    }

    for (i = 2; i < N; ++i) {
        if (a[i]) std::cout << ' ' << i;
    }
    std::cout << '\n';
    return 0;
}
