// ex.4.38

// en: Modify the array-based FIFO queue implementation in the text
// (Program 4.15) to call a function error() if the client attempts to
// get when the queue is empty or to put when the queue is full.

// ru: Измените приведенную в тексте реализацию очереди FIFO на базе
// массива (программа 4.15) так, чтобы в ней вызывалась функция
// error(), если клиент пытается выполнить операцию извлечь, когда
// очередь пуста, или операцию занести, когда очередь заполнена.

#include <iostream>
#include <stdexcept>

#include <catch.hpp>

template <typename T>
class Queue {
   public:
    explicit Queue(int capacity)
        : n_(capacity + 1), q_(new T[n_]), head_(n_), tail_(0) {}

    ~Queue() { delete[] q_; }

    bool empty() const { return head_ % n_ == tail_; }

    void put(T v) {
        if (tail_ + 1 == head_) error("queue is full");
        q_[tail_++] = v;
        tail_ %= n_;
    }

    T get() {
        if (empty()) error("queue is empty");
        head_ %= n_;
        return q_[head_++];
    }

   private:
    void error(const char* msg) const { throw std::length_error(msg); }

   private:
    int n_;
    T* q_;
    int head_;
    int tail_;
};

TEST_CASE("normal usage") {
    Queue<int> q{3};
    q.put(1);
    REQUIRE(q.get() == 1);
    q.put(2);
    q.put(3);
    REQUIRE(q.get() == 2);
    q.put(4);
    REQUIRE(q.get() == 3);
    q.put(5);
    q.put(6);
    REQUIRE(q.get() == 4);
    REQUIRE(q.get() == 5);
    REQUIRE(q.get() == 6);
}

TEST_CASE("empty queue") {
    Queue<int> q{3};
    REQUIRE_THROWS_AS(q.get(), std::length_error);
}

TEST_CASE("full queue") {
    Queue<int> q{3};
    q.put(1);
    q.put(2);
    q.put(3);
    REQUIRE_THROWS_AS(q.put(4), std::length_error);
}
