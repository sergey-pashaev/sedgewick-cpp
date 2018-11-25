#ifndef PROGRAM_4_7_H
#define PROGRAM_4_7_H

// program.4.7

// en: Array implementation of a pushdown stack

// ru: Реализация стека магазинного типа на базе массива

#include <cstddef>
#include <stdexcept>

template <typename T>
class Stack {
   public:
    explicit Stack(int max) : s_{new T[max]}, n_{0}, cap_{max} {}
    ~Stack() { delete[] s_; }
    bool Empty() const { return n_ == 0; }
    void Push(T v) {
        if (n_ == cap_) Error("stack capacity reached");
        s_[n_++] = v;
    }
    T Pop() {
        if (Empty()) Error("stack is empty");
        return s_[n_--];
    }
    std::size_t Size() const { return n_; }

   private:
    void Error(const char* msg) const { throw std::length_error(msg); }

   private:
    T* s_;
    int n_;
    int cap_;
};

#endif /* PROGRAM_4_7_H */
