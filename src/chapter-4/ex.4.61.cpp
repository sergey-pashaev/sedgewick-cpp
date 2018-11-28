// ex.4.61

// en: Do Exercises 4.54 and 4.55 for the randomized-queue ADT.

// ru: Выполните упражнения 4.54 и 4.55 для рандомизированной очереди
// FIFO.

#include <cstddef>
#include <random>
#include <stdexcept>

#include <catch.hpp>

template <typename T>
class RandomQueueIgnoreDuplicates {
   public:
    explicit RandomQueueIgnoreDuplicates(std::size_t capacity)
        : n_(capacity + 1), q_(new T[n_]), head_(n_), tail_(0) {}

    ~RandomQueueIgnoreDuplicates() { delete[] q_; }

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

        // find v & return
        const std::size_t size = Size();
        for (std::size_t i = head_ % n_; i < size; ++i, i %= n_) {
            if (q_[i] == v) return;
        }

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

    std::size_t RandomNode() const {
        std::uniform_int_distribution<int> dist(0, Size() - 1);
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
std::mt19937 RandomQueueIgnoreDuplicates<T>::gen_{std::random_device()()};

TEST_CASE("queue: ignore new duplicates") {
    RandomQueueIgnoreDuplicates<int> q(3);
    REQUIRE(q.Empty());
    REQUIRE(q.Size() == 0);
    REQUIRE_THROWS_AS(q.Pop(), std::length_error);

    q.Push(1);
    REQUIRE(q.Size() == 1);

    // duplicates
    q.Push(2);
    REQUIRE(q.Size() == 2);

    q.Push(1);
    REQUIRE(q.Size() == 2);

    q.Push(2);
    REQUIRE(q.Size() == 2);

    q.Push(3);
    REQUIRE(q.Size() == 3);

    q.Pop();
    q.Pop();
    q.Pop();

    REQUIRE(q.Empty());
    REQUIRE(q.Size() == 0);

    // make dtor useful
    q.Push(4);
}

template <typename T>
class RandomQueueRemoveDuplicates {
   public:
    explicit RandomQueueRemoveDuplicates(std::size_t capacity)
        : n_(capacity + 1), q_(new T[n_]), head_(n_), tail_(0) {}

    ~RandomQueueRemoveDuplicates() { delete[] q_; }

    bool Empty() const { return head_ % n_ == tail_; }

    std::size_t Size() const {
        if (tail_ >= (head_ % n_)) {
            return tail_ - (head_ % n_);
        } else {
            return (tail_ + n_) - (head_ % n_);
        }
    }

    void Push(T v) {
        // find v & move
        const std::size_t size = Size();
        for (std::size_t i = head_ % n_; i < size; ++i, i %= n_) {
            if (q_[i] == v) {
                // move
                for (std::size_t j = i + 1; j < size; ++j) {
                    q_[j - 1] = q_[j];
                }

                // update tail
                q_[(tail_ - 1) % n_] = v;
                return;
            }
        }

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

    std::size_t RandomNode() const {
        std::uniform_int_distribution<int> dist(0, Size() - 1);
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
std::mt19937 RandomQueueRemoveDuplicates<T>::gen_{std::random_device()()};

TEST_CASE("queue: remove old duplicates") {
    RandomQueueRemoveDuplicates<int> q(3);
    REQUIRE(q.Empty());
    REQUIRE(q.Size() == 0);
    REQUIRE_THROWS_AS(q.Pop(), std::length_error);

    q.Push(1);
    REQUIRE(q.Size() == 1);

    // duplicates
    q.Push(2);
    REQUIRE(q.Size() == 2);

    q.Push(1);
    REQUIRE(q.Size() == 2);

    q.Push(2);
    REQUIRE(q.Size() == 2);

    q.Push(3);
    REQUIRE(q.Size() == 3);

    q.Pop();
    q.Pop();
    q.Pop();

    REQUIRE(q.Empty());
    REQUIRE(q.Size() == 0);

    // make dtor useful
    q.Push(4);
}
