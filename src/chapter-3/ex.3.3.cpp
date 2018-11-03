// ex.3.3

// en: Test the random-number generator on your system by generating N
// random numbers of type double between 0 and 1, transforming them to
// integers between 0 and r-1 by multiplying by r and truncating the
// result, and computing the average and standard deviation for r =
// 10, 100, and 1000 and N = 10^3, 10^4, 10^5, and 10^6.

// ru: Протестируйте генератор случайный чисел в своей системе. Для
// этого сгенерируйте N случайный чисел типа double в диапазоне от 0
// до 1, преобразуя их в целые числа диапазона от 0 до r-1 путем
// умножения на r и усечения результата. Затем вычислите среднее
// значение и сренднеквадратическое отклонение для r = 10, 100 и 1000
// и N = 10^3, 10^4, 10^5 и 10^6.

#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>
#include <vector>

// old way & deprecated rand()
void measure_rand_real(int R, int N) {
    double avg = 0.0;
    double stddev = 0.0;
    std::srand(std::time(nullptr));
    for (int i = 0; i < N; ++i) {
        double d = static_cast<double>(std::rand()) / RAND_MAX;
        int x = static_cast<int>(d * R);
        avg += static_cast<double>(x) / N;
        stddev += static_cast<double>(x * x) / N;
    }

    stddev = std::sqrt(stddev - avg * avg);
    std::cout << "N=" << N << "\tR=" << R << "\tavg=" << avg
              << "\tstddev=" << stddev << '\n';
}

// modern way
void measure_rand_real_modern(int R, int N) {
    double avg = 0.0;
    double stddev = 0.0;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(0, 1.0);
    for (int i = 0; i < N; ++i) {
        int x = static_cast<int>(dist(gen) * R);
        avg += static_cast<double>(x) / N;
        stddev += static_cast<double>(x * x) / N;
    }

    stddev = std::sqrt(stddev - avg * avg);
    std::cout << "N=" << N << "\tR=" << R << "\tavg=" << avg
              << "\tstddev=" << stddev << '\n';
}

int main() {
    std::vector<int> R = {10, 100, 1000};
    std::vector<int> N = {1000, 10'000, 100'000, 1'000'000};
    for (int r : R) {
        for (int n : N) {
            std::cout << "old: ";
            measure_rand_real(r, n);
            std::cout << "new: ";
            measure_rand_real_modern(r, n);
        }
    }
    return 0;
}
