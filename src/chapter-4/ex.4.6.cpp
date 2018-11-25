// ex.4.6

// en: Give a class definition for Item that overloads the == operator
// to support equality testing among floating-point numbers. Consider
// two floating-point numbers to be equal if the absolute value of
// their difference divided by the larger (in absolute value) of the
// two numbers is less than 10^–6

// ru: Дайте определение для класса Item, в котором для проверки
// равенства чисел с плавающей точкой используется перегруженная
// операция ==. Считайте два числа с плавающей точкой равными, если
// абсолютная величина их разности, деленная на большее (по абсолютной
// величине) из двух чисел, меньшее чем 10^-6

#include <algorithm>
#include <cmath>

#include <catch.hpp>

class Item {
   public:
    explicit Item(double v) : v_(v) {}

    bool operator==(const Item &other) const {
        return (std::fabs(v_ - other.v_) /
                std::max(std::fabs(v_), std::fabs(other.v_))) < epsilon_;
    }

   private:
    double v_;
    static constexpr double epsilon_ = 1.e-6;
};

TEST_CASE("Item equality") {
    Item a(1.0);
    Item b(1.0000001);
    Item c(1.000001);
    Item d(1.00001);
    REQUIRE(a == b);
    REQUIRE(a == c);
    REQUIRE(!(a == d));
}
