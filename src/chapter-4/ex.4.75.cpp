// ex.4.74

// en: Develop an implementation of your first-class pushdown-stack
// ADT from Exercise 4.73 that uses a linked list as the underlying
// data structure.

// ru: Разработайте реализацию АТД первого класса для стэка
// магазинного типа из упражнения 4.73, в которой в качестве базовой
// структуры данных используется связный список.

#include <algorithm>
#include <cstddef>
#include <stdexcept>

#include <catch.hpp>

template <typename T>
class Stack {
   private:
    struct Node {
        Node(T v, Node* n) : v{v}, next{n} {}
        T v;
        Node* next;
    };

   public:
    explicit Stack(std::size_t capacity = 0)
        : capacity_{capacity}, size_{0}, head_{nullptr} {}

    Stack(const Stack& other)
        : capacity_{other.capacity_}, size_{other.size_}, head_{nullptr} {
        try {
            // copy
            for (Node* cur = other.head_; cur; cur = cur->next) {
                head_ = new Node(cur->v, head_);
            }

            // reverse
            Node* cur = head_;
            Node* prev = nullptr;
            Node* next = nullptr;
            while (cur) {
                next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
            }
            head_ = prev;
        } catch (const std::bad_alloc&) {
            Error("out of memory");
        }
    }

    Stack(Stack&& other) : Stack() { swap(*this, other); }

    Stack& operator=(Stack other) {
        swap(*this, other);
        return *this;
    }

    ~Stack() {
        Node* cur = head_;
        while (cur) {
            Node* next = cur->next;
            delete cur;
            cur = next;
        }
    }

    friend void swap(Stack& lhs, Stack& rhs) noexcept {
        using std::swap;
        swap(lhs.capacity_, rhs.capacity_);
        swap(lhs.size_, rhs.size_);
        swap(lhs.head_, rhs.head_);
    }

    bool Empty() const { return size_ == 0; }

    std::size_t Size() const { return size_; }

    const T& Top() const {
        if (Empty()) Error("stack is empty");
        return head_->v;
    }

    T Pop() {
        if (Empty()) Error("stack is empty");
        T v = head_->v;
        Node* t = head_->next;
        delete head_;
        head_ = t;
        --size_;
        return v;
    }

    void Push(const T& v) {
        if (size_ == capacity_) Error("stack capacity reached");
        try {
            head_ = new Node(v, head_);
        } catch (const std::bad_alloc) {
            Error("out of memory");
        }
        size_++;
    }

   private:
    void Error(const char* msg) const { throw std::length_error(msg); }

   private:
    std::size_t capacity_;
    std::size_t size_;
    Node* head_;
};

TEST_CASE("normal usage") {
    Stack<int> s{3};
    REQUIRE(s.Empty());
    REQUIRE_THROWS_AS(s.Top(), std::length_error);
    REQUIRE_THROWS_AS(s.Pop(), std::length_error);

    s.Push(1);
    REQUIRE(s.Size() == 1);
    REQUIRE(s.Top() == 1);

    s.Push(2);
    REQUIRE(s.Size() == 2);
    REQUIRE(s.Top() == 2);

    s.Push(3);
    REQUIRE(s.Size() == 3);
    REQUIRE(s.Top() == 3);

    REQUIRE_THROWS_AS(s.Push(4), std::length_error);

    REQUIRE(s.Pop() == 3);
    REQUIRE(s.Top() == 2);

    REQUIRE(s.Pop() == 2);
    REQUIRE(s.Top() == 1);

    REQUIRE(s.Pop() == 1);
    REQUIRE(s.Empty());

    REQUIRE_THROWS_AS(s.Top(), std::length_error);
    REQUIRE_THROWS_AS(s.Pop(), std::length_error);
}

TEST_CASE("copy ctor") {
    Stack<int> s1{3};
    s1.Push(1);
    s1.Push(2);
    s1.Push(3);

    Stack<int> s2(s1);
    REQUIRE(s2.Pop() == 3);
    REQUIRE(s2.Pop() == 2);
    REQUIRE(s2.Pop() == 1);
}

Stack<int> GetStack() {
    Stack<int> s{3};
    s.Push(1);
    s.Push(2);
    s.Push(3);
    return s;
}

TEST_CASE("move ctor") {
    Stack<int> s(GetStack());
    REQUIRE(s.Pop() == 3);
    REQUIRE(s.Pop() == 2);
    REQUIRE(s.Pop() == 1);
}

TEST_CASE("assignment operator") {
    Stack<int> s1{3};
    s1.Push(1);
    s1.Push(2);
    s1.Push(3);

    Stack<int> s2 = s1;
    REQUIRE(s2.Pop() == 3);
    REQUIRE(s2.Pop() == 2);
    REQUIRE(s2.Pop() == 1);
}
