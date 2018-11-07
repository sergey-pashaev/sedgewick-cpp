// ex.3.16

// en: Write a program that counts the number of different integers
// less than 1000 that appear in an input stream.

// ru: Напишите программу подсчета количества различных целых чисел,
// меньших 1000, которые встречаются во входном потоке.

#include <iostream>
#include <vector>

const int N = 1000;

int usage(const char* bin) {
    std::cout << "Usage: " << bin << '\n';
    std::cout << "\tinput - list of positive integers less than 1000\n";
    return 1;
}

int main(int, char* argv[]) {
    std::vector<char> a(N, 0);

    int x;
    int unique = 0;
    int n = N;
    while (n-- && std::cin >> x) {
        if (x <= 0 || x >= N) return usage(argv[0]);
        if (!a[x]) {
            a[x] = 1;
            ++unique;
        }
    }

    std::cout << unique << '\n';

    return 0;
}
