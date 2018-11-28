// ex.4.59

// en: Do Exercise 4.56 for the FIFO queue ADT.

// ru: Выполните упражнение 4.56 для очереди FIFO.

#include <cstddef>
#include <stdexcept>

#include <catch.hpp>

template <typename T>
class QueueIgnoreDuplicates {
   private:
    struct Node {
        explicit Node(T v) : item{v} {}

        T item;
        Node* next = nullptr;
    };

   public:
    ~QueueIgnoreDuplicates() {
        auto t = head_;
        while (t) {
            auto next = t->next;
            delete t;
            t = next;
        }
    }

    bool Empty() const { return head_ == nullptr; }

    void Push(T v) {
        if (Find(v)) return;

        Node* t = tail_;
        try {
            tail_ = new Node(v);
        } catch (const std::bad_alloc& e) {
            Error("queue is full (out of memory)");
        }

        if (head_) {
            t->next = tail_;
        } else {
            head_ = tail_;
        }

        ++size_;
    }

    T Pop() {
        if (Empty()) Error("queue is empty");
        T v = head_->item;
        Node* t = head_->next;
        delete head_;
        head_ = t;
        --size_;
        return v;
    }

    T Front() const {
        if (Empty()) Error("queue is empty");
        return head_->item;
    }

    T Back() const {
        if (Empty()) Error("queue is empty");
        return tail_->item;
    }

    std::size_t Size() const { return size_; }

   private:
    void Error(const char* msg) const { throw std::length_error(msg); }

    Node* Find(const T v) const {
        for (Node* cur = head_; cur; cur = cur->next) {
            if (cur->item == v) return cur;
        }
        return nullptr;
    }

   private:
    Node* head_ = nullptr;
    Node* tail_ = nullptr;
    std::size_t size_ = 0;
};

TEST_CASE("queue: ignore new duplicates") {
    QueueIgnoreDuplicates<int> q;
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
   private:
    struct Node {
        explicit Node(T v) : item{v} {}

        T item;
        Node* next = nullptr;
    };

   public:
    ~QueueRemoveDuplicates() {
        auto t = head_;
        while (t) {
            auto next = t->next;
            delete t;
            t = next;
        }
    }

    bool Empty() const { return head_ == nullptr; }

    void Push(T v) {
        Node* cur = head_;
        Node* prev = nullptr;
        while (cur) {
            if (cur->item == v) {
                if (cur == tail_) return;

                if (prev) {
                    prev->next = cur->next;
                } else {
                    head_ = cur->next;
                }

                tail_->next = cur;
                cur->next = nullptr;
                tail_ = cur;
                return;
            }

            prev = cur;
            cur = cur->next;
        }

        Node* t = tail_;
        try {
            tail_ = new Node(v);
        } catch (const std::bad_alloc& e) {
            Error("queue is full (out of memory)");
        }

        if (head_) {
            t->next = tail_;
        } else {
            head_ = tail_;
        }

        ++size_;
    }

    T Pop() {
        if (Empty()) Error("queue is empty");
        T v = head_->item;
        Node* t = head_->next;
        delete head_;
        head_ = t;
        --size_;
        return v;
    }

    T Front() const {
        if (Empty()) Error("queue is empty");
        return head_->item;
    }

    T Back() const {
        if (Empty()) Error("queue is empty");
        return tail_->item;
    }

    std::size_t Size() const { return size_; }

   private:
    void Error(const char* msg) const { throw std::length_error(msg); }

   private:
    Node* head_ = nullptr;
    Node* tail_ = nullptr;
    std::size_t size_ = 0;
};

TEST_CASE("queue: remove old duplicates") {
    QueueRemoveDuplicates<int> q;
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
