// ex.4.27

// en: Develop an ADT that provides clients with two different
// pushdown stacks. Use an array implementation. Keep one stack at the
// beginning of the array and the other at the end. (If the client
// program is such that one stack grows while the other one shrinks,
// this implementation uses less space than other alternatives.)

// ru: Разработайте АТД, предоставляющий два разных стэка магазинного
// типа.  Воспользуйтесь реализацией на базе массива. Один стек
// расположите в начале массива, а другой - в конце. (Если клиентская
// программа работает так, что при увеличении одного стека другой
// уменьшается, эта реализация будет занимать меньший объём памяти,
// чем другие варианты.)

#include <stdexcept>

#include <catch.hpp>

template <typename T>
class DoubleStack {
   public:
    explicit DoubleStack(int size)
        : capacity_{size}, beg_{0}, end_{size - 1}, data_{new T[size]} {}
    ~DoubleStack() { delete[] data_; }

    void PushFront(T v) {
        if (beg_ == capacity_)
            throw std::length_error("front stack capacity reached");
        if (beg_ > end_)
            throw std::length_error("front & back stacks collision");
        data_[beg_++] = v;
    }
    void PushBack(T v) {
        if (end_ < 0) throw std::length_error("back stack capacity reached");
        if (beg_ > end_)
            throw std::length_error("front & back stacks collision");
        data_[end_--] = v;
    }
    T PopFront() {
        if (!beg_) throw std::length_error("front stack is empty");
        return data_[--beg_];
    }
    T PopBack() {
        if (end_ == capacity_ - 1)
            throw std::length_error("back stack is empty");
        return data_[++end_];
    }
    T Front() const {
        if (!beg_) throw std::length_error("front stack is empty");
        return data_[beg_ - 1];
    }
    T Back() const {
        if (end_ == capacity_ - 1)
            throw std::length_error("back stack is empty");
        return data_[end_ + 1];
    }

   private:
    int capacity_;
    int beg_;
    int end_;
    T* data_;
};

TEST_CASE("normal usage") {
    DoubleStack<int> s{4};
    s.PushFront(1);
    REQUIRE(s.Front() == 1);
    s.PushFront(2);
    REQUIRE(s.Front() == 2);
    s.PushBack(4);
    REQUIRE(s.Back() == 4);
    s.PushBack(3);
    REQUIRE(s.Back() == 3);
    s.PopFront();
    REQUIRE(s.Front() == 1);
    s.PopBack();
    REQUIRE(s.Back() == 4);
    s.PushFront(2);
    s.PushFront(3);
    REQUIRE(s.Front() == 3);
}

TEST_CASE("pop empty stack") {
    DoubleStack<int> s{4};
    REQUIRE_THROWS_AS(s.PopFront(), std::length_error);
    REQUIRE_THROWS_AS(s.PopBack(), std::length_error);
    REQUIRE_THROWS_AS(s.Front(), std::length_error);
    REQUIRE_THROWS_AS(s.Back(), std::length_error);
}

TEST_CASE("front capacity reached") {
    DoubleStack<int> s{4};
    s.PushFront(1);
    s.PushFront(2);
    s.PushFront(3);
    s.PushFront(4);
    REQUIRE_THROWS_AS(s.PushFront(5), std::length_error);
}

TEST_CASE("back capacity reached") {
    DoubleStack<int> s{4};
    s.PushBack(1);
    s.PushBack(2);
    s.PushBack(3);
    s.PushBack(4);
    REQUIRE_THROWS_AS(s.PushBack(5), std::length_error);
}

TEST_CASE("stacks collision") {
    DoubleStack<int> s{4};
    s.PushBack(1);
    s.PushBack(2);
    s.PushFront(3);
    s.PushFront(4);
    REQUIRE_THROWS_AS(s.PushBack(5), std::length_error);
}
