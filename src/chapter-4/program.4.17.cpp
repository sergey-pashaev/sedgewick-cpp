// program.4.17

// en: Complex numbers driver (roots of unity)

// ru: Драйвер комплексных чисел (корни из единицы)

#include <cmath>
#include <cstdlib>
#include <iostream>

class Complex {
   public:
    Complex(double re, double im) : re_{re}, im_{im} {}
    double Re() const { return re_; }
    double Im() const { return im_; }
    Complex operator+(const Complex& other) {
        return Complex(re_ + other.re_, im_ + other.im_);
    }
    Complex& operator+=(const Complex& other) {
        re_ += other.re_;
        im_ += other.im_;
        return *this;
    }
    Complex& operator*=(const Complex& other) {
        double t = re_;
        re_ = re_ * other.re_ - im_ * other.im_;
        im_ = t * other.im_ + im_ * other.re_;
        return *this;
    }

   private:
    double re_;
    double im_;
};

std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << c.Re() << ' ' << c.Im();
    return os;
}

int usage(const char* bin) {
    std::cout << "Usage: " << bin << " <positive int N>\n";
    return 1;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        return usage(argv[0]);
    }

    const int N = std::atoi(argv[1]);
    if (N <= 0) {
        return usage(argv[0]);
    }

    std::cout << N << " roots of unity:\n";
    for (int k = 0; k < N; ++k) {
        float theta = 2.0 * 3.14159 * k / N;
        Complex t(std::cos(theta), std::sin(theta)), x = t;
        std::cout << k << ": " << t << ' ';
        for (int j = 0; j < N - 1; ++j) x *= t;
        std::cout << x << '\n';
    }

    return 0;
}
