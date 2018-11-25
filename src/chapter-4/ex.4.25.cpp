// ex.4.25

// en: Modify the linked-list–based pushdown-stack implementation in
// the text (Program 4.8) to use an array of indices to implement the
// list (see Figure 3.4 (??? maybe wrong link, it should be Figure
// 3.6)).

// ru: Измените реализацию стека магазинного типа на базе связного
// списка (программа 4.8) так, чтобы для создания списка в ней
// использовался массив индексов (см. рис. 3.4 (??? не тот рисунок,
// скорее рис.3.6)).

#include <cstddef>
#include <stdexcept>

#include <catch.hpp>

template <typename T>
class Stack {
   private:
    struct List {
        explicit List(std::size_t max)
            : item{new T[max]}, next{new std::size_t[max]} {}
        ~List() {
            delete[] item;
            delete[] next;
        }

        T* item;
        std::size_t* next;
    };

   public:
    explicit Stack(std::size_t max) : list_{max}, n_{0} {}
    bool Empty() const { return !n_; }
    void Push(T v) {
        list_.item[n_] = v;
        list_.next[n_] = n_ + 1;
        n_++;
    }
    T Pop() {
        --n_;
        T v = list_.item[n_];
        list_.next[n_] = 0;
        return v;
    }
    std::size_t Size() const { return n_; }

   private:
    List list_;
    std::size_t n_;
};

TEST_CASE("stack") {
    Stack<int> s{10};
    s.Push(3);
    s.Push(2);
    REQUIRE(s.Pop() == 2);
    s.Push(1);
    REQUIRE(s.Pop() == 1);
    REQUIRE(s.Pop() == 3);
}
