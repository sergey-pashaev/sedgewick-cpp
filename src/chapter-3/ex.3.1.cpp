// ex.3.1

// en: Find the largest and smallest numbers that you can represent
// with types int, long int, short int, float, and double in your
// programming environment.

// ru: Найдите наибольшее и наименьшее числа, которые можно
// представить типами int, long int, short int, float, double в своей
// среде программирования.

#include <iostream>
#include <limits>
#include <typeinfo>

template <typename T>
void Limits() {
    std::cout << typeid(T).name() << ' ' << std::numeric_limits<T>::min() << ' '
              << std::numeric_limits<T>::max() << '\n';
}

int main() {
    Limits<int>();
    Limits<long int>();
    Limits<short int>();
    Limits<float>();
    Limits<double>();
    return 0;
}
