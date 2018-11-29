#ifndef PROGRAM_4_18_H
#define PROGRAM_4_18_H

// program.4.18

// en: First-class ADT interface for complex numbers

// ru: Интерфейс АТД первого класса для комплексных чисел

class Complex {
   public:
    Complex(double re, double im);
    double Re() const;
    double Im() const;
    Complex& operator*=(const Complex&);
};

#endif /* PROGRAM_4_18_H */
