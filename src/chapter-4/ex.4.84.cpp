// ex.4.84

// en: Develop an ADT that allows clients to perform addition and
// multiplication of arbitrarily long integers.

// ru: Разработайте АТД, который позволяет клиентским программам
// выполнять сложение и умножение целых чисел произвольной точности.

#include <cstdint>
#include <cstring>
#include <iostream>
#include <ostream>

#include <catch.hpp>

class BigNum {
   public:
    BigNum() : a_{} {}

    BigNum(const char* s) {
        std::size_t sz = std::strlen(s);
        for (int i = sz - 1; i >= 0; --i) {
            a_.push_back(s[i] - '0');
        }
    }

    BigNum(int v) {
        while (v > 9) {
            a_.push_back(v % 10);
            v /= 10;
        }
        a_.push_back(v);
    }

    friend bool operator==(const BigNum& lhs, const BigNum& rhs) {
        return lhs.a_ == rhs.a_;
    }

    friend bool operator!=(const BigNum& lhs, const BigNum& rhs) {
        return !(lhs == rhs);
    }

    friend BigNum operator+(const BigNum& lhs, const BigNum& rhs) {
        const std::size_t m = lhs.a_.size();
        const std::size_t n = rhs.a_.size();
        BigNum ret;
        const std::size_t s = std::max(m, n);
        ret.a_.resize(s + 1, 0);

        const uint8_t b = 10;
        uint8_t k = 0;
        for (std::size_t i = 0; i < s; ++i) {
            uint8_t t = k;
            if (i < m) t += lhs.a_[i];
            if (i < n) t += rhs.a_[i];

            ret.a_[i] = t % b;
            k = t / b;
        }

        if (k) {
            ret.a_[s] = k;
        }

        if (!ret.a_[s]) {
            ret.a_.resize(s);
        }

        return ret;
    }

    friend BigNum operator*(const BigNum& lhs, const BigNum& rhs) {
        const std::size_t m = lhs.a_.size();
        const std::size_t n = rhs.a_.size();
        BigNum ret;
        ret.a_.resize(m + n, 0);

        const int b = 10;

        for (std::size_t j = 0; j < n; ++j) {
            uint16_t k = 0;
            for (std::size_t i = 0; i < m; ++i) {
                ret.a_[i + j] += k + lhs.a_[i] * rhs.a_[j];
                k = ret.a_[i + j] / b;
                ret.a_[i + j] %= b;
            }
            ret.a_[j + m] = k;
        }

        if (!ret.a_[m + n - 1]) {
            ret.a_.resize(m + n - 1);
        }

        return ret;
    }

    friend std::ostream& operator<<(std::ostream& os, const BigNum& n);

   private:
    std::vector<uint8_t> a_;
};

std::ostream& operator<<(std::ostream& os, const BigNum& n) {
    for (auto it = n.a_.rbegin(); it != n.a_.rend(); ++it) {
        os << char('0' + *it);
    }
    return os;
}

TEST_CASE("bignum addition") {
    REQUIRE(BigNum(0) + BigNum("0") == BigNum(0));
    REQUIRE(BigNum(1) + BigNum("0") == BigNum(1));
    REQUIRE(BigNum(0) + BigNum("1") == BigNum(1));
    REQUIRE(BigNum(9) + BigNum("1") == BigNum(10));
    REQUIRE(BigNum("9") + BigNum(1) == BigNum(10));
    REQUIRE(BigNum(9) + BigNum(2) == BigNum(11));
    REQUIRE(BigNum(19) + BigNum(29) == BigNum(48));
}

TEST_CASE("bignum multiplication") {
    REQUIRE(BigNum("0") * BigNum(5) == BigNum(0));
    REQUIRE(BigNum("10") * BigNum(55) == BigNum(550));
    REQUIRE(BigNum("2") * BigNum(4) == BigNum(8));
    REQUIRE(BigNum("4") * BigNum(9) == BigNum(36));
    REQUIRE(BigNum("99") * BigNum(99) == BigNum(9801));
    REQUIRE(BigNum("123456789123456789") * BigNum("987654321987654321") ==
            BigNum("121932631356500531347203169112635269"));
}
