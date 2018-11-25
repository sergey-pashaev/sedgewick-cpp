// ex.4.55

// en: Modify the standard array-based stack implementation in Section
// 4.4 (Program 4.7) to disallow duplicates with a forget-the-old-item
// policy. Use a brute-force approach that involves scanning through,
// and possibly rearranging, the whole stack.

// ru: Измените стандартную реализацию стэка на базе массива из
// раздела 4.4 (программа 4.7), чтобы в ней были запрещены дубликаты
// по правилу "удалять старый элемент". Используйте простейший метод,
// выполняющий просмотр всего стэка и перемещение его элементов.

#include <cstddef>
#include <stdexcept>

#include <catch.hpp>

template <typename T>
class UniqueStack {
   public:
    UniqueStack(std::size_t n) : capacity_(n), size_(0), data_(new T[n]) {}
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
            if (data_[i] == v) {
                // move
                for (std::size_t j = i + 1; j < size_; ++j) {
                    data_[j - 1] = data_[j];
                }

                // update
                data_[size_ - 1] = v;
                return;
            }
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

TEST_CASE("unique stack: remove old duplicates") {
    UniqueStack<int> s{3};
    REQUIRE(s.Empty());
    // duplicates
    s.Push(1);
    REQUIRE(s.Size() == 1);
    REQUIRE(s.Top() == 1);
    s.Push(1);
    REQUIRE(s.Size() == 1);
    REQUIRE(s.Top() == 1);

    s.Push(2);
    REQUIRE(s.Size() == 2);
    REQUIRE(s.Top() == 2);

    // duplicates
    s.Push(1);
    REQUIRE(s.Size() == 2);
    REQUIRE(s.Top() == 1);
    s.Push(2);
    REQUIRE(s.Size() == 2);
    REQUIRE(s.Top() == 2);

    s.Push(3);
    REQUIRE(s.Size() == 3);
    REQUIRE(s.Top() == 3);
}
