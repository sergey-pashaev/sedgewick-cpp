#ifndef PSV_DEQUE_H
#define PSV_DEQUE_H

#include <ostream>
#include <stdexcept>

namespace psv {

template <typename T>
class Deque {
   private:
    struct Node {
        Node(T v) : item{v} {}

        T item;
        Node* next = nullptr;
        Node* prev = nullptr;
    };

   public:
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

    T Front() const {
        if (Empty()) Error("deque is empty");
        return head_->item;
    }

    T Back() const {
        if (Empty()) Error("deque is empty");
        return tail_->item;
    }

    void Dump(std::ostream& os) const {
        auto t = head_;
        while (t) {
            auto next = t->next;
            os << t->item << (next ? ' ' : '\n');
            t = next;
        }
    }

   private:
    void Error(const char* msg) const { throw std::length_error(msg); }

   private:
    Node* head_ = nullptr;
    Node* tail_ = nullptr;
};

}  // namespace psv

#endif /* PSV_DEQUE_H */
