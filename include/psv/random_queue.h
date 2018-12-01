#ifndef PSV_RANDOM_QUEUE_H
#define PSV_RANDOM_QUEUE_H

#include <algorithm>
#include <cstddef>
#include <random>
#include <stdexcept>

namespace psv {

template <typename T>
class RandomQueue {
   public:
    explicit RandomQueue(std::size_t capacity = 0)
        : n_{capacity + 1}, q_{n_ ? new T[n_] : nullptr}, head_{n_}, tail_{0} {}

    RandomQueue(const RandomQueue& other)
        : n_{other.n_},
          q_{n_ ? new T[n_] : nullptr},
          head_{other.head_},
          tail_{other.tail_} {
        std::copy(other.q_, other.q_ + n_, q_);
    }

    RandomQueue(RandomQueue&& other) : RandomQueue() { swap(*this, other); }

    RandomQueue& operator=(RandomQueue other) {
        swap(*this, other);
        return *this;
    }

    friend void swap(RandomQueue& lhs, RandomQueue& rhs) noexcept {
        using std::swap;
        swap(lhs.n_, rhs.n_);
        swap(lhs.q_, rhs.q_);
        swap(lhs.head_, rhs.head_);
        swap(lhs.tail_, rhs.tail_);
    }

    ~RandomQueue() { delete[] q_; }

    bool Empty() const { return head_ % n_ == tail_; }

    std::size_t Size() const {
        if (tail_ >= (head_ % n_)) {
            return tail_ - (head_ % n_);
        } else {
            return (tail_ + n_) - (head_ % n_);
        }
    }

    void Push(T v) {
        if (tail_ + 1 == head_) Error("queue is full");
        q_[tail_++] = v;
        tail_ %= n_;
    }

    T Pop() {
        if (Empty()) Error("queue is empty");
        head_ %= n_;
        std::swap(q_[head_], q_[RandomNode()]);
        return q_[head_++];
    }

   private:
    void Error(const char* msg) const { throw std::length_error(msg); }

    std::size_t RandomNode() const {
        std::uniform_int_distribution<std::size_t> dist{0, Size() - 1};
        return (head_ % n_) + dist(gen_);
    }

   private:
    std::size_t n_;
    T* q_;
    std::size_t head_;
    std::size_t tail_;

    static std::mt19937 gen_;
};

template <typename T>
std::mt19937 RandomQueue<T>::gen_{std::random_device()()};

}  // namespace psv

#endif /* PSV_RANDOM_QUEUE_H */
