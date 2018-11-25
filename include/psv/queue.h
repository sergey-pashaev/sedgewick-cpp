#ifndef PSV_QUEUE_H
#define PSV_QUEUE_H

#include <stdexcept>

namespace psv {

template <typename T>
class Queue {
   private:
    struct Node {
        explicit Node(T v) : item{v} {}

        T item;
        Node* next = nullptr;
    };

   public:
    ~Queue() {
        auto t = head_;
        while (t) {
            auto next = t->next;
            delete t;
            t = next;
        }
    }

    bool Empty() const { return head_ == nullptr; }

    void Push(T v) {
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
    }

    T Pop() {
        if (Empty()) Error("queue is empty");
        T v = head_->item;
        Node* t = head_->next;
        delete head_;
        head_ = t;
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

   private:
    void Error(const char* msg) const { throw std::length_error(msg); }

   private:
    Node* head_ = nullptr;
    Node* tail_ = nullptr;
};

}  // namespace psv

#endif /* PSV_QUEUE_H */
