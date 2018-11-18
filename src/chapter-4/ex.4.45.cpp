// ex.4.45

// en: Provide an implementation for your deque interface (Exercise
// 4.43) that uses a doubly linked list for the underlying data
// structure.

// ru: Напишите реализацию для интерфейса дека (упр. 4.43), в которой
// в качестве базовой структуры данных используется двузсвязный
// список.

#include <stdexcept>

#include <catch.hpp>

bool fail_alloc = false;

template <typename T>
class Deque {
   private:
    struct Node {
        Node(T v) : item{v} {}

        void* operator new(std::size_t size) {
            if (fail_alloc) {
                throw std::bad_alloc();
            }

            return ::malloc(size);
        }

        void operator delete(void* p) { ::free(p); }

        T item;
        Node* next = nullptr;
        Node* prev = nullptr;
    };

   public:
    Deque(int) {}

    ~Deque() {
        auto t = head_;
        while (t) {
            auto next = t->next;
            delete t;
            t = next;
        }
    }

    bool Empty() const { return head_ == nullptr || tail_ == nullptr; }

    void PushFront(T v) {
        Node* t = head_;
        try {
            head_ = new Node(v);
        } catch (const std::bad_alloc& e) {
            throw std::length_error("deque is full (out of memory)");
        }
        if (tail_) {
            t->prev = head_;
            head_->next = t;
        } else {
            tail_ = head_;
        }
    }

    void PushBack(T v) {
        Node* t = tail_;
        try {
            tail_ = new Node(v);
        } catch (const std::bad_alloc& e) {
            throw std::length_error("deque is full (out of memory)");
        }
        if (head_) {
            t->next = tail_;
            tail_->prev = t;
        } else {
            head_ = tail_;
        }
    }

    T PopFront() {
        if (Empty()) Error("deque is empty");
        T v = head_->item;
        Node* t = head_->next;
        delete head_;
        head_ = t;
        if (head_) {
            head_->prev = nullptr;
        } else {
            tail_ = head_;
        }
        return v;
    }

    T PopBack() {
        if (Empty()) Error("deque is empty");
        T v = tail_->item;
        Node* t = tail_->prev;
        delete tail_;
        tail_ = t;
        if (tail_) {
            tail_->next = nullptr;
        } else {
            head_ = tail_;
        }
        return v;
    }

   private:
    void Error(const char* msg) const { throw std::length_error(msg); }

   private:
    Node* head_ = nullptr;
    Node* tail_ = nullptr;
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

        fail_alloc = true;
        REQUIRE_THROWS_AS(d.PushBack(4), std::length_error);
        REQUIRE_THROWS_AS(d.PushFront(4), std::length_error);
        fail_alloc = false;

        REQUIRE(d.PopFront() == 3);
        REQUIRE(d.PopFront() == 2);
        REQUIRE(d.PopFront() == 1);
    }

    SECTION("use as stack (back)") {
        d.PushBack(1);
        d.PushBack(2);
        d.PushBack(3);

        fail_alloc = true;
        REQUIRE_THROWS_AS(d.PushBack(4), std::length_error);
        REQUIRE_THROWS_AS(d.PushFront(4), std::length_error);
        fail_alloc = false;

        REQUIRE(d.PopBack() == 3);
        REQUIRE(d.PopBack() == 2);
        REQUIRE(d.PopBack() == 1);
    }

    SECTION("use as queue (back -> front)") {
        d.PushBack(1);
        d.PushBack(2);
        d.PushBack(3);

        fail_alloc = true;
        REQUIRE_THROWS_AS(d.PushBack(4), std::length_error);
        REQUIRE_THROWS_AS(d.PushFront(4), std::length_error);
        fail_alloc = false;

        REQUIRE(d.PopFront() == 1);
        REQUIRE(d.PopFront() == 2);
        REQUIRE(d.PopFront() == 3);
    }

    SECTION("use as queue (front -> back)") {
        d.PushFront(1);
        d.PushFront(2);
        d.PushFront(3);

        fail_alloc = true;
        REQUIRE_THROWS_AS(d.PushBack(4), std::length_error);
        REQUIRE_THROWS_AS(d.PushFront(4), std::length_error);
        fail_alloc = false;

        REQUIRE(d.PopBack() == 1);
        REQUIRE(d.PopBack() == 2);
        REQUIRE(d.PopBack() == 3);
    }

    SECTION("use as deque (mixed)") {
        d.PushBack(1);
        d.PushFront(2);
        d.PushBack(3);

        fail_alloc = true;
        REQUIRE_THROWS_AS(d.PushBack(4), std::length_error);
        REQUIRE_THROWS_AS(d.PushFront(4), std::length_error);
        fail_alloc = false;

        REQUIRE(d.PopFront() == 2);
        REQUIRE(d.PopBack() == 3);
        REQUIRE(d.PopFront() == 1);
    }

    fail_alloc = false;
    REQUIRE(d.Empty());
    REQUIRE_THROWS_AS(d.PopFront(), std::length_error);
    REQUIRE_THROWS_AS(d.PopBack(), std::length_error);
}
