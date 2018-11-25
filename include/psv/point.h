#ifndef PSV_POINT_H
#define PSV_POINT_H

#include <cmath>
#include <ostream>
#include <random>

namespace psv {

template <typename T>
class Point {
   public:
    Point() : x_(0), y_(0) {}

    Point(T x, T y) : x_(x), y_(y) {}

    T X() const { return x_; }
    T Y() const { return y_; }

    T Distance() const { return std::sqrt(x_ * x_ + y_ * y_); }

    T Distance(const Point& other) const {
        const T dx = this->x_ - other.x_;
        const T dy = this->y_ - other.y_;
        return std::sqrt(dx * dx + dy * dy);
    }

    bool operator==(const Point& other) const {
        return Distance(other) < epsilon_;
    }

    static Point Random() { return Point(dist_(gen_), dist_(gen_)); }

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const Point<U>& point);

   private:
    T x_;
    T y_;

    static T epsilon_;

    static std::mt19937 gen_;
    static std::uniform_real_distribution<T> dist_;
};

template <typename T>
T Point<T>::epsilon_ = 0.001;

template <typename T>
std::mt19937 Point<T>::gen_{std::random_device()()};

template <typename T>
std::uniform_real_distribution<T> Point<T>::dist_{0, 1.0};

template <typename U>
std::ostream& operator<<(std::ostream& os, const Point<U>& point) {
    os << '(' << point.X() << ',' << point.Y() << ')';
    return os;
}

template <typename T>
class PolarPoint {
   public:
    PolarPoint() : r_(0), phi_(0) {}

    PolarPoint(T r, T phi) : r_(r), phi_(phi) {}

    PolarPoint(const Point<T>& p)
        : r_(p.Distance()), phi_(std::atan2(p.Y(), p.X())) {}

    T R() const { return r_; }
    T Phi() const { return phi_; }

    T Distance(const PolarPoint& other) const {
        // sqrt(r1^2 + r2^2 - 2*r1*r2*cos(phi2 - phi1)
        return std::sqrt(r_ * r_ + other.r_ * other.r_ -
                         2 * r_ * other.r_ * std::cos(other.phi_ - phi_));
    }

    T Distance() const { return r_; }

    bool operator==(const Point<T>& other) const {
        return Distance(other) < Point<T>::epsilon_;
    }

    static PolarPoint Random() { return PolarPoint(Point<T>::random()); }

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os,
                                    const PolarPoint<U>& point);

   private:
    T r_;
    T phi_;
};

template <typename U>
std::ostream& operator<<(std::ostream& os, const PolarPoint<U>& point) {
    os << '(' << point.R() << ',' << point.Phi() << ')';
    return os;
}

}  // namespace psv

#endif /* PSV_POINT_H */
