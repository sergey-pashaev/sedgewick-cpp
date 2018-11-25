// ex.4.56

// en: Do Exercises 4.54 and 4.55 for the linked-list–based stack
// implementation in Section 4.4 (Program 4.8).

// ru: Выполните упражнения 4.54 и 4.55 для реализации стэка на базе
// связного списка из раздела 4.4 (программа 4.8).

#include <cstddef>
#include <stdexcept>

#include <catch.hpp>

template <typename T>
class UniqueStackIgnoreDuplicates {
   private:
    struct Node {
        Node(T v, Node* t) : v{v}, next{t} {}
        T v;
        Node* next;
    };

   public:
    explicit UniqueStackIgnoreDuplicates(std::size_t) : head_{nullptr} {}

    ~UniqueStackIgnoreDuplicates() {
        auto cur = head_;
        while (cur) {
            auto next = cur->next;
            delete cur;
            cur = next;
        }
    }

    bool Empty() const { return !head_; }

    void Push(T v) {
        try {
            // find v
            for (Node* cur = head_; cur; cur = cur->next) {
                if (cur->v == v) return;
            }

            head_ = new Node(v, head_);
        } catch (const std::bad_alloc& e) {
            Error("out of memory");
        }
    }

    T Top() const {
        if (Empty()) Error("stack is empty");
        return head_->v;
    }

    T Pop() {
        if (Empty()) Error("stack is empty");
        T v = head_->v;
        Node* t = head_->next;
        delete head_;
        head_ = t;
        return v;
    }

    std::size_t Size() const {
        std::size_t ret = 0;
        for (Node* n = head_; n; n = n->next) {
            ++ret;
        }

        return ret;
    }

   private:
    void Error(const char* msg) const { throw std::length_error(msg); }

   private:
    Node* head_;
};

TEST_CASE("unique stack: ignore new duplicates") {
    UniqueStackIgnoreDuplicates<int> s{3};
    REQUIRE(s.Empty());

    // duplicates
    s.Push(1);
    REQUIRE(s.Size() == 1);
    REQUIRE(s.Top() == 1);
    s.Push(1);
    REQUIRE(s.Size() == 1);
    REQUIRE(s.Top() == 1);

    // new element
    s.Push(2);
    REQUIRE(s.Size() == 2);
    REQUIRE(s.Top() == 2);

    // duplicates
    s.Push(1);
    REQUIRE(s.Size() == 2);
    REQUIRE(s.Top() == 2);
    s.Push(2);
    REQUIRE(s.Size() == 2);
    REQUIRE(s.Top() == 2);

    // new element
    s.Push(3);
    REQUIRE(s.Size() == 3);
    REQUIRE(s.Top() == 3);
}

template <typename T>
class UniqueStackRemoveDuplicates {
   private:
    struct Node {
        Node(T v, Node* t) : v{v}, next{t} {}
        T v;
        Node* next;
    };

   public:
    explicit UniqueStackRemoveDuplicates(std::size_t) : head_{nullptr} {}

    ~UniqueStackRemoveDuplicates() {
        auto cur = head_;
        while (cur) {
            auto next = cur->next;
            delete cur;
            cur = next;
        }
    }

    bool Empty() const { return !head_; }

    void Push(T v) {
        // FIXME: try block scope too wide
        try {
            if (head_) {
                Node* cur = head_;
                Node* prev = nullptr;
                // find node w/ v & move it before head
                while (cur) {
                    if (cur->v == v) {
                        if (prev) {
                            auto t = cur;
                            prev->next = cur->next;
                            t->next = head_;
                            head_ = t;
                        }
                        return;
                    } else {
                        prev = cur;
                        cur = cur->next;
                    }
                }
            }

            head_ = new Node(v, head_);
        } catch (const std::bad_alloc& e) {
            Error("out of memory");
        }
    }

    T Top() const {
        if (Empty()) Error("stack is empty");
        return head_->v;
    }

    T Pop() {
        if (Empty()) Error("stack is empty");
        T v = head_->v;
        Node* t = head_->next;
        delete head_;
        head_ = t;
        return v;
    }

    std::size_t Size() const {
        std::size_t ret = 0;
        for (Node* n = head_; n; n = n->next) {
            ++ret;
        }

        return ret;
    }

   private:
    void Error(const char* msg) const { throw std::length_error(msg); }

   private:
    Node* head_;
};

TEST_CASE("unique stack: remove old duplicates") {
    UniqueStackRemoveDuplicates<int> s{3};
    REQUIRE(s.Empty());

    // duplicates
    s.Push(1);
    REQUIRE(s.Size() == 1);
    REQUIRE(s.Top() == 1);
    s.Push(1);
    REQUIRE(s.Size() == 1);
    REQUIRE(s.Top() == 1);

    // new element
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

    // new element
    s.Push(3);
    REQUIRE(s.Size() == 3);
    REQUIRE(s.Top() == 3);
}
