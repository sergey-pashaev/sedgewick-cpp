// ex.4.54

// en: Modify the standard array-based stack implementation in Section
// 4.4 (Program 4.7) to disallow duplicates with an
// ignore-the-new-item policy. Use a brute-force approach that
// involves scanning through the whole stack.

// ru: Измените стандартную реализацию стэка на базе массива из
// раздела 4.4 (программа 4.7), чтобы в ней были запрещены дубликаты
// по правилу "игнорировать новый элемент". Используйте простейший
// метод, выполняющий просмотр всего стэка.

#include <cstddef>
#include <stdexcept>

#include <catch.hpp>

template <typename T>
class UniqueStack {
   public:
    explicit UniqueStack(std::size_t n)
        : capacity_(n), size_(0), data_(new T[n]) {}
    ~UniqueStack() { delete[] data_; }

    bool Empty() const { return size_ == 0; }

    T Top() const {
        if (Empty()) Error("stack is empty");
        return data_[size_ - 1];
    }

    T Pop() {
        if (Empty()) Error("stack is empty");
        return data_[--size_];
    }

    void Push(T v) {
        if (size_ == capacity_) Error("stack capacity reached");
        for (std::size_t i = 0; i < size_; ++i) {
            if (data_[i] == v) return;
        }
        data_[size_++] = v;
    }

    std::size_t Size() const { return size_; }

   private:
    void Error(const char* msg) const { throw std::length_error(msg); }

    std::size_t capacity_;
    std::size_t size_;
    T* data_;
};

TEST_CASE("unique stack: ignore new duplicates") {
    UniqueStack<int> s{3};
    REQUIRE(s.Empty());
    s.Push(1);
    REQUIRE(s.Size() == 1);
    s.Push(2);
    REQUIRE(s.Size() == 2);

    // duplicates
    s.Push(1);
    REQUIRE(s.Size() == 2);
    REQUIRE(s.Top() == 2);
    s.Push(1);
    REQUIRE(s.Size() == 2);
    REQUIRE(s.Top() == 2);

    s.Push(3);
    REQUIRE(s.Size() == 3);
}
