#ifndef PSV_POINT_H
#define PSV_POINT_H

#include <cmath>

namespace psv {

template <typename T>
class Point {
   public:
    Point() : x_(0), y_(0) {}

    Point(T x, T y) : x_(x), y_(y) {}

    T X() const { return x_; }
    T Y() const { return y_; }

    T distance() const { return std::sqrt(x_ * x_ + y_ * y_); }

   private:
    T x_;
    T y_;
};

template <typename T>
class PolarPoint {
   public:
    PolarPoint() : r_(0), phi_(0) {}

    PolarPoint(const Point<T>& p)
        : r_(p.distance()), phi_(std::atan2(p.Y(), p.X())) {}

    T R() const { return r_; }
    T Phi() const { return phi_; }

    T distance(const PolarPoint& other) const {
        // sqrt(r1^2 + r2^2 - 2*r1*r2*cos(phi2 - phi1)
        return std::sqrt(r_ * r_ + other.r_ * other.r_ -
                         2 * r_ * other.r_ * std::cos(other.phi_ - phi_));
    }

    T distance() const { return r_; }

   private:
    T r_;
    T phi_;
};

}  // namespace psv

#endif /* PSV_POINT_H */
