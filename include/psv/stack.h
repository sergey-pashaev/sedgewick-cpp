#ifndef PSV_STACK_H
#define PSV_STACK_H

#include <cstddef>
#include <stdexcept>

namespace psv {

template <typename T>
class Stack {
   public:
    explicit Stack(std::size_t n) : capacity_(n), size_(0), data_(new T[n]) {}
    ~Stack() { delete[] data_; }

    bool empty() const { return size_ == 0; }

    T top() {
        if (!size_) throw std::length_error("stack is empty");
        return data_[size_ - 1];
    }

    T pop() {
        if (!size_) throw std::length_error("stack is empty");
        return data_[--size_];
    }

    void push(T v) {
        if (size_ == capacity_)
            throw std::length_error("stack capacity reached");
        data_[size_++] = v;
    }

   private:
    std::size_t capacity_;
    std::size_t size_;
    T* data_;
};

}  // namespace psv

#endif /* PSV_STACK_H */
