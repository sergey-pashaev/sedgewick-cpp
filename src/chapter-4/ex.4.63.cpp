// ex.4.63

// en: Overload operators + and += to work for complex numbers
// (Programs 4.18 and 4.19).

// ru: Перегрузите операции + и += для работы с комплексными числами
// (программы 4.18 и 4.19).

#include <ostream>

#include <catch.hpp>

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

TEST_CASE("Complex addition") {
    Complex c1(2.0, 3.0);
    Complex c2(1.0, -1.0);

    Complex c3 = c1 + c2;
    REQUIRE(c3.Re() == 3.0);
    REQUIRE(c3.Im() == 2.0);

    c3 += c2;
    REQUIRE(c3.Re() == 4.0);
    REQUIRE(c3.Im() == 1.0);
}
