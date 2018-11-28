// ex.4.58

// en: Do Exercises 4.54 and 4.55 for the FIFO queue ADT.

// ru: Выполните упражнения 4.54 и 4.55 для очереди FIFO.

#include <cstddef>
#include <stdexcept>

#include <catch.hpp>

template <typename T>
class QueueIgnoreDuplicates {
   public:
    explicit QueueIgnoreDuplicates(std::size_t capacity)
        : n_(capacity + 1), q_(new T[n_]), head_(n_), tail_(0) {}

    ~QueueIgnoreDuplicates() { delete[] q_; }

    bool Empty() const { return head_ % n_ == tail_; }

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
        return q_[head_++];
    }

    T Front() const {
        if (Empty()) Error("queue is empty");
        return q_[head_ % n_];
    }

    T Back() const {
        if (Empty()) Error("queue is empty");
        return q_[(tail_ - 1) % n_];
    }

    std::size_t Size() const {
        if (tail_ >= (head_ % n_)) {
            return tail_ - (head_ % n_);
        } else {
            return (tail_ + n_) - (head_ % n_);
        }
    }

   private:
    void Error(const char* msg) const { throw std::length_error(msg); }

   private:
    std::size_t n_;
    T* q_;
    std::size_t head_;
    std::size_t tail_;
};

TEST_CASE("queue: ignore new duplicates") {
    QueueIgnoreDuplicates<int> q(3);
    REQUIRE(q.Empty());
    REQUIRE(q.Size() == 0);
    REQUIRE_THROWS_AS(q.Pop(), std::length_error);

    q.Push(1);
    REQUIRE(q.Size() == 1);
    REQUIRE(q.Front() == 1);
    REQUIRE(q.Back() == 1);

    // duplicates
    q.Push(2);
    REQUIRE(q.Size() == 2);
    REQUIRE(q.Front() == 1);
    REQUIRE(q.Back() == 2);

    q.Push(1);
    REQUIRE(q.Size() == 2);
    REQUIRE(q.Front() == 1);
    REQUIRE(q.Back() == 2);

    q.Push(2);
    REQUIRE(q.Size() == 2);
    REQUIRE(q.Front() == 1);
    REQUIRE(q.Back() == 2);

    q.Push(3);
    REQUIRE(q.Size() == 3);
    REQUIRE(q.Front() == 1);
    REQUIRE(q.Back() == 3);

    REQUIRE(q.Pop() == 1);
    REQUIRE(q.Pop() == 2);
    REQUIRE(q.Pop() == 3);

    REQUIRE(q.Empty());
    REQUIRE(q.Size() == 0);

    // make dtor useful
    q.Push(4);
}

template <typename T>
class QueueRemoveDuplicates {
   public:
    explicit QueueRemoveDuplicates(std::size_t capacity)
        : n_(capacity + 1), q_(new T[n_]), head_(n_), tail_(0) {}

    ~QueueRemoveDuplicates() { delete[] q_; }

    bool Empty() const { return head_ % n_ == tail_; }

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
        return q_[head_++];
    }

    T Front() const {
        if (Empty()) Error("queue is empty");
        return q_[head_ % n_];
    }

    T Back() const {
        if (Empty()) Error("queue is empty");
        return q_[(tail_ - 1) % n_];
    }

    std::size_t Size() const {
        if (tail_ >= (head_ % n_)) {
            return tail_ - (head_ % n_);
        } else {
            return (tail_ + n_) - (head_ % n_);
        }
    }

   private:
    void Error(const char* msg) const { throw std::length_error(msg); }

   private:
    std::size_t n_;
    T* q_;
    std::size_t head_;
    std::size_t tail_;
};

TEST_CASE("queue: remove old duplicates") {
    QueueRemoveDuplicates<int> q(3);
    REQUIRE(q.Empty());
    REQUIRE(q.Size() == 0);
    REQUIRE_THROWS_AS(q.Pop(), std::length_error);

    q.Push(1);
    REQUIRE(q.Size() == 1);
    REQUIRE(q.Front() == 1);
    REQUIRE(q.Back() == 1);

    // duplicates
    q.Push(2);
    REQUIRE(q.Size() == 2);
    REQUIRE(q.Front() == 1);
    REQUIRE(q.Back() == 2);

    q.Push(1);
    REQUIRE(q.Size() == 2);
    REQUIRE(q.Front() == 2);
    REQUIRE(q.Back() == 1);

    q.Push(2);
    REQUIRE(q.Size() == 2);
    REQUIRE(q.Front() == 1);
    REQUIRE(q.Back() == 2);

    q.Push(3);
    REQUIRE(q.Size() == 3);
    REQUIRE(q.Front() == 1);
    REQUIRE(q.Back() == 3);

    q.Push(2);
    REQUIRE(q.Size() == 3);
    REQUIRE(q.Front() == 1);
    REQUIRE(q.Back() == 2);

    REQUIRE(q.Pop() == 1);
    REQUIRE(q.Pop() == 3);
    REQUIRE(q.Pop() == 2);

    REQUIRE(q.Empty());
    REQUIRE(q.Size() == 0);

    // make dtor useful
    q.Push(4);
}
