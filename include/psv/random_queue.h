#ifndef PSV_RANDOM_QUEUE_H
#define PSV_RANDOM_QUEUE_H

#include <random>
#include <stdexcept>

namespace psv {

template <typename T>
class RandomQueue {
   public:
    explicit RandomQueue(int capacity)
        : n_(capacity + 1), q_(new T[n_]), head_(n_), tail_(0) {}

    bool Empty() const { return head_ % n_ == tail_; }

    int Size() const {
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
        int r = RandomNode();
        std::swap(q_[head_], q_[r]);
        return q_[head_++];
    }

   private:
    void Error(const char* msg) const { throw std::length_error(msg); }

    int RandomNode() const {
        std::uniform_int_distribution<int> dist{0, Size() - 1};
        return (head_ % n_) + dist(gen_);
    }

   private:
    int n_;
    T* q_;
    int head_;
    int tail_;

    static std::mt19937 gen_;
};

template <typename T>
std::mt19937 RandomQueue<T>::gen_{std::random_device()()};

}  // namespace psv

#endif /* PSV_RANDOM_QUEUE_H */
