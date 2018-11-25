// ex.3.64

// en: Write a program to fill in a two-dimensional array of 0 - 1
// values by setting a[i][j] to 1 if the greatest common divisor of i
// and j is 1, and to 0 otherwise.

// ru: Напишите программу заполнения двумерного массива значениями 0 и
// 1: элемент a[i][j] должен содержать 1, если наибольший общий
// делитель i и j равен единице, и значение 0 в остальных случаях.

#include <array>
#include <iostream>

using std::array;

int GCD(int a, int b) { return b ? GCD(b, a % b) : a; }

int main() {
    const int N = 20;
    const int M = 20;
    array<array<int, M>, N> arr = {};

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            arr[i][j] = GCD(i, j) == 1;
            std::cout << arr[i][j] << (j + 1 < N ? " " : "");
        }
        std::cout << '\n';
    }
}
