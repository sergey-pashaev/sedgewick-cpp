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

}  // namespace psv

#endif /* PSV_POINT_H */
