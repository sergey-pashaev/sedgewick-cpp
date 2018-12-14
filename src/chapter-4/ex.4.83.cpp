// ex.4.83

// en: Extend your polynomial ADT from Exercise 4.81 to include
// polynomial division and composition.

// ru: Расширьте АТД полинома из упражнения 4.81 так, чтобы он включал
// деление и суперпозицию полиномов.

#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <ostream>

#include <catch.hpp>

template <typename T>
class Poly {
   private:
    int n_;
    T* a_;

   public:
    Poly() : n_{0}, a_{nullptr} {}

    Poly(T v, int exp) : n_{exp + 1}, a_{n_ ? new T[n_] : nullptr} {
        std::fill(a_, a_ + n_, 0);
        a_[exp] = v;
    }

    Poly(const Poly& other) : n_{other.n_}, a_{new T[n_]} {
        std::copy(other.a_, other.a_ + n_, a_);
    }

    Poly(Poly&& other) : Poly() { swap(*this, other); }

    Poly& operator=(Poly other) {
        swap(*this, other);
        return *this;
    }

    ~Poly() { delete[] a_; }

    friend void swap(Poly& lhs, Poly& rhs) noexcept {
        using std::swap;
        swap(lhs.n_, rhs.n_);
        swap(lhs.a_, rhs.a_);
    }

    double Eval(double x) const {
        double v = 0.0;
        for (int i = n_ - 1; i >= 0; --i) {
            v = v * x + a_[i];
        }
        return v;
    }

    friend Poly operator+(const Poly& lhs, T v) { return lhs + Poly(v, 0); }

    friend Poly operator+(T v, const Poly& rhs) { return Poly(v, 0) + rhs; }

    friend Poly operator+(const Poly& lhs, const Poly& rhs) {
        Poly t(0, std::max(lhs.n_, rhs.n_) - 1);

        for (int i = 0; i < lhs.n_; ++i) {
            t.a_[i] += lhs.a_[i];
        }

        for (int i = 0; i < rhs.n_; ++i) {
            t.a_[i] += rhs.a_[i];
        }

        // remove highest zero coefficient
        while (t.a_[t.n_ - 1] == 0) {
            --t.n_;
        }

        return t;
    }

    Poly& operator+=(const Poly& rhs) {
        *this = *this + rhs;
        return *this;
    }

    friend Poly operator*(const Poly& lhs, const Poly& rhs) {
        Poly t(0, (lhs.n_ - 1) + (rhs.n_ - 1));

        for (int i = 0; i < lhs.n_; ++i) {
            for (int j = 0; j < rhs.n_; ++j) {
                t.a_[i + j] += lhs.a_[i] * rhs.a_[j];
            }
        }

        // remove highest zero coefficient
        while (t.a_[t.n_ - 1] == 0) {
            --t.n_;
        }

        return t;
    }

    friend Poly operator*(const Poly& lhs, T v) { return lhs * Poly(v, 0); }

    friend Poly operator*(T v, const Poly& rhs) { return Poly(v, 0) * rhs; }

    Poly& operator*=(const Poly& rhs) {
        *this = *this * rhs;
        return *this;
    }

    friend Poly operator/(const Poly& lhs, const Poly& rhs) {
        assert(lhs.n_ >= rhs.n_);

        Poly ret(0, 0);
        Poly remainder(lhs);

        while (remainder.n_ >= rhs.n_) {
            Poly p(remainder.a_[remainder.n_ - 1] / rhs.a_[rhs.n_ - 1],
                   remainder.n_ - rhs.n_);
            ret += p;
            remainder += (p * rhs * -1.0);
        }

        return ret;
    }

    friend Poly operator%(const Poly& lhs, const Poly& rhs) {
        assert(lhs.n_ >= rhs.n_);

        Poly ret(0, 0);
        Poly remainder(lhs);

        while (remainder.n_ >= rhs.n_) {
            Poly p(remainder.a_[remainder.n_ - 1] / rhs.a_[rhs.n_ - 1],
                   remainder.n_ - rhs.n_);
            ret += p;
            remainder += (p * rhs * -1.0);
        }

        return remainder;
    }

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const Poly<U>& p);

    Poly Integral() const {
        Poly t(0, n_);

        for (int i = 0; i < n_; ++i) {
            t.a_[i + 1] = a_[i] / (i + 1);
        }

        t.a_[0] = 1;  // + C
        return t;
    }

    Poly Derivative() const {
        Poly t(0, n_ - 2);

        for (int i = 0; i < t.n_; ++i) {
            t.a_[i] = (i + 1) * a_[i + 1];
        }

        return t;
    }

    Poly Superposition(const Poly& other) const {
        assert(n_ > 1);

        // constant
        Poly ret(a_[0], 0);

        // skip constant
        for (int i = 1; i < n_; ++i) {
            Poly t(a_[i], 0);
            for (int j = 0; j < i; ++j) {
                t *= other;
            }
            ret += t;
        }

        return ret;
    }
};

template <typename U>
std::ostream& operator<<(std::ostream& os, const Poly<U>& p) {
    if (!p.n_) {
        os << 0;
        return os;
    }

    os << std::showpos;
    for (int i = p.n_ - 1; i >= 0; --i) {
        if (!p.a_[i]) continue;

        os << p.a_[i];
        if (i > 0) {
            os << 'x';
            if (i != 1) {
                os << '^' << std::noshowpos << i << std::showpos;
            }
        }

        if (i < p.n_) {
            os << ' ';
        }
    }

    os << std::noshowpos;

    return os;
}

TEST_CASE("polynomial addition") {
    Poly<int> x3(1, 3);
    Poly<int> x2(1, 2);
    Poly<int> x(1, 1);

    Poly<int> p = 0 + 5 + x + x2 + 1 + x3 + (-1);
    std::cout << p << '\n';
    auto f = [](int x) { return 0 + 5 + x + x * x + 1 + x * x * x - 1; };

    for (double v = 0.0; v < 15.0; v += 1.0) {
        REQUIRE(f(v) == p.Eval(v));
    }
}

TEST_CASE("polynomial multiply") {
    Poly<double> x3(1, 3);
    Poly<double> x2(1, 2);
    Poly<double> x(1, 1);

    Poly<double> l = 1 + (-1.0) * x + 0.5 * x2 + (-1.0 / 6.0) * x3;
    Poly<double> r = 1 + x + x2 + x3;

    Poly<double> p = l * r;
    std::cout << p << '\n';
    auto f = [](double x) {
        return 1.0 + x * x * 0.5 + x * x * x * (1.0 / 3.0) -
               x * x * x * x * (2.0 / 3.0) + x * x * x * x * x * (1.0 / 3.0) -
               x * x * x * x * x * x * (1.0 / 6.0);
    };

    for (double v = 0.0; v < 15.0; v += 1.0) {
        REQUIRE(Approx(f(v)) == p.Eval(v));
    }

    REQUIRE(Approx(0.0) == (p * 0.0).Eval(1.0));
}

TEST_CASE("polynomial assignment addition") {
    Poly<int> x3(1, 3);
    Poly<int> x2(1, 2);
    Poly<int> x(1, 1);

    Poly<int> p = x + x2 + x3;
    p += p;
    std::cout << p << '\n';

    auto f = [](int x) { return 2 * x + 2 * x * x + 2 * x * x * x; };

    for (double v = 0.0; v < 15.0; v += 1.0) {
        REQUIRE(f(v) == p.Eval(v));
    }
}

TEST_CASE("polynomial assignment multiply") {
    Poly<int> x3(1, 3);
    Poly<int> x2(1, 2);
    Poly<int> x(1, 1);

    Poly<int> p = x + x2 + x3;
    p *= p;
    std::cout << p << '\n';

    auto f = [](int x) {
        return x * x + 2 * std::pow(x, 3) + 3 * std::pow(x, 4) +
               2 * std::pow(x, 5) + std::pow(x, 6);
    };

    for (double v = 0.0; v < 15.0; v += 1.0) {
        REQUIRE(f(v) == p.Eval(v));
    }
}

TEST_CASE("polynomial integral & derivative") {
    Poly<double> x3(1, 3);
    Poly<double> x2(1, 2);
    Poly<double> x(1, 1);

    Poly<double> p = x + x2 + x3;
    std::cout << p << '\n';
    p = p.Integral();
    std::cout << p << '\n';

    auto fi = [](double x) {
        double C = 1;
        return C + (1.0 / 2.0) * x * x + (1.0 / 3.0) * std::pow(x, 3) +
               (1.0 / 4.0) * std::pow(x, 4);
    };

    for (double v = 0.0; v < 15.0; v += 1.0) {
        REQUIRE(Approx(fi(v)) == p.Eval(v));
    }

    p = p.Derivative();
    std::cout << p << '\n';

    auto f = [](int x) { return x + x * x + x * x * x; };

    for (double v = 0.0; v < 15.0; v += 1.0) {
        REQUIRE(Approx(f(v)) == p.Eval(v));
    }
}

TEST_CASE("polynomial division") {
    Poly<double> x3(1, 3);
    Poly<double> x2(1, 2);
    Poly<double> x(1, 1);

    Poly<double> l = x3 + (-12.0) * x2 + (-42.0);
    std::cout << l << '\n';

    Poly<double> r = x + (-3.0);
    std::cout << r << '\n';

    auto f1 = [](double x) { return x * x - 9.0 * x - 27.0; };
    Poly<double> d = l / r;
    std::cout << d << '\n';
    for (double v = 0.0; v < 15.0; v += 1.0) {
        REQUIRE(Approx(f1(v)) == d.Eval(v));
    }

    Poly<double> rem = l % r;
    std::cout << rem << '\n';
    for (double v = 0.0; v < 15.0; v += 1.0) {
        REQUIRE(Approx(-123.0) == rem.Eval(v));
    }
}

TEST_CASE("polynomial superposition") {
    Poly<double> x3(1, 3);
    Poly<double> x2(1, 2);
    Poly<double> x(1, 1);

    Poly<double> f = x2 + 2.0 * x + (-1.0);
    std::cout << f << '\n';

    Poly<double> g = 2.0 * x + 3.0;
    std::cout << g << '\n';

    auto fg_expected = [](double x) { return 4.0 * x * x + 16.0 * x + 14.0; };
    Poly<double> fg = f.Superposition(g);
    std::cout << fg << '\n';
    for (double v = 0.0; v < 15.0; v += 1.0) {
        REQUIRE(Approx(fg_expected(v)) == fg.Eval(v));
    }

    auto gf_expected = [](double x) { return 2.0 * x * x + 4.0 * x + 1.0; };
    Poly<double> gf = g.Superposition(f);
    std::cout << gf << '\n';
    for (double v = 0.0; v < 15.0; v += 1.0) {
        REQUIRE(Approx(gf_expected(v)) == gf.Eval(v));
    }
}
