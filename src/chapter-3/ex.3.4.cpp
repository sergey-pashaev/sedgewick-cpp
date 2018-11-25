// ex.3.4

// en: Do Exercises 3.2 and 3.3 for r = 2, 4, and 16.

// ru: Выполните упражнения 3.2 и 3.3 для r = 2, 4, 16.

#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>
#include <vector>

// old way & deprecated rand()
void MeasureRandomInt(int R, int N) {
    double avg = 0.0;
    double stddev = 0.0;
    std::srand(std::time(nullptr));
    for (int i = 0; i < N; ++i) {
        int x = std::rand() % R;
        avg += static_cast<double>(x) / N;
        stddev += static_cast<double>(x * x) / N;
    }

    stddev = std::sqrt(stddev - avg * avg);
    std::cout << "N=" << N << "\tR=" << R << "\tavg=" << avg
              << "\tstddev=" << stddev << '\n';
}

// modern way
void MeasureRandomIntModern(int R, int N) {
    double avg = 0.0;
    double stddev = 0.0;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, R - 1);
    for (int i = 0; i < N; ++i) {
        int x = dist(gen);
        avg += static_cast<double>(x) / N;
        stddev += static_cast<double>(x * x) / N;
    }

    stddev = std::sqrt(stddev - avg * avg);
    std::cout << "N=" << N << "\tR=" << R << "\tavg=" << avg
              << "\tstddev=" << stddev << '\n';
}

// old way & deprecated rand()
void MeasureRandomReal(int R, int N) {
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
void MeasureRandomRealModern(int R, int N) {
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
    std::vector<int> R = {2, 4, 10, 16, 100, 1000};
    std::vector<int> N = {1000, 10'000, 100'000, 1'000'000};
    for (int r : R) {
        for (int n : N) {
            std::cout << "old int : ";
            MeasureRandomInt(r, n);
            std::cout << "old real: ";
            MeasureRandomReal(r, n);
            std::cout << "new int : ";
            MeasureRandomIntModern(r, n);
            std::cout << "new real: ";
            MeasureRandomRealModern(r, n);
        }
    }
    return 0;
}
