// ex.4.48

// en: Build a random-queue ADT by writing an interface and an
// implementation that uses an array as the underlying data
// structure. Make sure that each operation takes constant time.

// ru: Создайте АТД неупорядоченной очереди (напишите интерфейс и
// реализацию), в котором в качестве базовой структуры данных
// используется массив. Обеспечьте для каждой операции постоянное
// время выполнения.

#include <cstdlib>
#include <random>
#include <stdexcept>
#include <utility>

#include <catch.hpp>

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

TEST_CASE("normal usage") {
    RandomQueue<int> q{3};
    REQUIRE(q.Size() == 0);
    q.Push(1);
    REQUIRE(q.Size() == 1);
    REQUIRE(q.Pop() == 1);
    q.Push(2);
    q.Push(3);
    REQUIRE(q.Size() == 2);
    q.Pop();
    q.Push(4);
    REQUIRE(q.Size() == 2);
    q.Pop();
    q.Push(5);
    q.Push(6);
    REQUIRE(q.Size() == 3);
    q.Pop();
    REQUIRE(q.Size() == 2);
    q.Pop();
    REQUIRE(q.Size() == 1);
    q.Pop();
    REQUIRE(q.Size() == 0);
}

TEST_CASE("empty queue") {
    RandomQueue<int> q{3};
    REQUIRE(q.Size() == 0);
    REQUIRE_THROWS_AS(q.Pop(), std::length_error);
}

TEST_CASE("full queue") {
    RandomQueue<int> q{3};
    q.Push(1);
    q.Push(2);
    q.Push(3);
    REQUIRE(q.Size() == 3);
    REQUIRE_THROWS_AS(q.Push(4), std::length_error);
}
