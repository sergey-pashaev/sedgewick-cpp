// ex.3.5

// en: Implement the necessary functions to allow Program 3.2 to be
// used for random bits(numbers that can take only the values 0 or 1).

// ru: Реализуйте функции, позволяющие применять программу 3.2 для
// случайных разрядов (чисел, которые могут принимать только 0 и 1).

#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>
#include <vector>

// old way & deprecated rand()
void MeasureRandomBool(int N) {
    double avg = 0.0;
    double stddev = 0.0;
    std::srand(std::time(nullptr));
    for (int i = 0; i < N; ++i) {
        int x = (static_cast<double>(std::rand()) / RAND_MAX) > 0.5 ? 1 : 0;
        avg += static_cast<double>(x) / N;
        stddev += static_cast<double>(x * x) / N;
    }

    stddev = std::sqrt(stddev - avg * avg);
    std::cout << "N=" << N << "\tavg=" << avg << "\tstddev=" << stddev << '\n';
}

// modern way
void MeasureRandomBoolModern(int N) {
    double avg = 0.0;
    double stddev = 0.0;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(0, 1.0);
    for (int i = 0; i < N; ++i) {
        int x = dist(gen) > 0.5 ? 1 : 0;
        avg += static_cast<double>(x) / N;
        stddev += static_cast<double>(x * x) / N;
    }

    stddev = std::sqrt(stddev - avg * avg);
    std::cout << "N=" << N << "\tavg=" << avg << "\tstddev=" << stddev << '\n';
}

int main() {
    std::vector<int> N = {1000, 10'000, 100'000, 1'000'000};
    for (int n : N) {
        std::cout << "old: ";
        MeasureRandomBool(n);
        std::cout << "new: ";
        MeasureRandomBoolModern(n);
    }
    return 0;
}
