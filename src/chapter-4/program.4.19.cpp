// program.4.19

// en: First-class ADT for complex numbers

// ru: АТД первого класса для комплексных чисел

#include <ostream>

class Complex {
   public:
    Complex(double re, double im) : re_{re}, im_{im} {}
    double Re() const { return re_; }
    double Im() const { return im_; }
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
