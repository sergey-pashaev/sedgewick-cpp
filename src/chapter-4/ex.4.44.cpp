// ex.4.44

// en: Provide an implementation for your deque interface (Exercise
// 4.43) that uses an array for the underlying data structure.

// ru: Напишите реализацию для интерфейса дека (упр. 4.43), в которой
// в качестве базовой структуры данных используется массив.

#include <memory>
#include <stdexcept>

#include <catch.hpp>

template <typename T>
class Deque {
   public:
    explicit Deque(int capacity)
        : n_(capacity + 1), q_(new T[n_]), head_(n_), tail_(0) {}

    bool Empty() const { return head_ % n_ == tail_; }

    bool Full() const { return tail_ + 1 == head_; }

    void PushFront(T v) {
        if (Full()) Error("deque is full");
        --head_;
        if (head_ < 0) head_ = n_ - 1;
        q_[head_] = v;
    }

    void PushBack(T v) {
        if (Full()) Error("deque is full");
        q_[tail_++] = v;
        tail_ %= n_;
    }

    T PopFront() {
        if (Empty()) Error("deque is empty");
        head_ %= n_;
        return q_[head_++];
    }

    T PopBack() {
        if (Empty()) Error("deque is empty");
        --tail_;
        if (tail_ < 0) tail_ = n_ - 1;
        return q_[tail_];
    }

   private:
    void Error(const char* msg) const { throw std::length_error(msg); }

   private:
    int n_;
    T* q_;
    int head_;
    int tail_;
};

TEST_CASE("deque") {
    Deque<int> d{3};
    REQUIRE(d.Empty());
    REQUIRE_THROWS_AS(d.PopFront(), std::length_error);
    REQUIRE_THROWS_AS(d.PopBack(), std::length_error);

    SECTION("use as stack (front)") {
        d.PushFront(1);
        d.PushFront(2);
        d.PushFront(3);

        REQUIRE_THROWS_AS(d.PushBack(4), std::length_error);
        REQUIRE_THROWS_AS(d.PushFront(4), std::length_error);

        REQUIRE(d.PopFront() == 3);
        REQUIRE(d.PopFront() == 2);
        REQUIRE(d.PopFront() == 1);
    }

    SECTION("use as stack (back)") {
        d.PushBack(1);
        d.PushBack(2);
        d.PushBack(3);

        REQUIRE_THROWS_AS(d.PushBack(4), std::length_error);
        REQUIRE_THROWS_AS(d.PushFront(4), std::length_error);

        REQUIRE(d.PopBack() == 3);
        REQUIRE(d.PopBack() == 2);
        REQUIRE(d.PopBack() == 1);
    }

    SECTION("use as queue (back -> front)") {
        d.PushBack(1);
        d.PushBack(2);
        d.PushBack(3);

        REQUIRE_THROWS_AS(d.PushBack(4), std::length_error);
        REQUIRE_THROWS_AS(d.PushFront(4), std::length_error);

        REQUIRE(d.PopFront() == 1);
        REQUIRE(d.PopFront() == 2);
        REQUIRE(d.PopFront() == 3);
    }

    SECTION("use as queue (front -> back)") {
        d.PushFront(1);
        d.PushFront(2);
        d.PushFront(3);

        REQUIRE_THROWS_AS(d.PushBack(4), std::length_error);
        REQUIRE_THROWS_AS(d.PushFront(4), std::length_error);

        REQUIRE(d.PopBack() == 1);
        REQUIRE(d.PopBack() == 2);
        REQUIRE(d.PopBack() == 3);
    }

    SECTION("use as deque (mixed)") {
        d.PushBack(1);
        d.PushFront(2);
        d.PushBack(3);

        REQUIRE_THROWS_AS(d.PushBack(4), std::length_error);
        REQUIRE_THROWS_AS(d.PushFront(4), std::length_error);

        REQUIRE(d.PopFront() == 2);
        REQUIRE(d.PopBack() == 3);
        REQUIRE(d.PopFront() == 1);
    }

    REQUIRE(d.Empty());
    REQUIRE_THROWS_AS(d.PopFront(), std::length_error);
    REQUIRE_THROWS_AS(d.PopBack(), std::length_error);
}
