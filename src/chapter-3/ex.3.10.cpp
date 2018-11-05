// ex.3.10

// en: Suppose that a is declared as int a[99]. Give the contents of
// the array after the following two statements are executed:
// for (i = 0; i < 99; i++) a[i] = 98 - i
// for (i = 0; i < 99; i++) a[i] = a[a[i]];

// ru: Предположим, переменная a объявлена как int a[99]. Определите
// содержимое массива после выполнения следующих двух операторов:
// for (i = 0; i < 99; ++i) a[i] = 98 - i
// for (i = 0; i < 99; ++i) a[i] = a[a[i]]

#include <iostream>

int main() {
    int a[99];
    int i;
    for (i = 0; i < 99; ++i) a[i] = 98 - i;
    for (i = 0; i < 99; ++i) a[i] = a[a[i]];
    for (i = 0; i < 99; ++i) std::cout << "a[" << i << "]=" << a[i] << '\n';
}
