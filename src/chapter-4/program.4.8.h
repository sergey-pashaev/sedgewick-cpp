#ifndef PROGRAM_4_8_H
#define PROGRAM_4_8_H

// program.4.8

// en: Linked-list implementation of a pushdown stack

// ru: Реализация стека магазинного типа на базе связного списка

#include <cstddef>
#include <stdexcept>

template <typename T>
class Stack {
   private:
    struct Node {
        Node(T v, Node* t) : v{v}, next{t} {}
        T v;
        Node* next;
    };
    typedef Node* Link;

   public:
    Stack(int) : head_{nullptr} {}
    ~Stack() {
        Link cur = head_;
        while (cur) {
            Link next = cur->next;
            delete cur;
            cur = next;
        }
    }
    bool Empty() const { return !head_; }
    void Push(T v) {
        try {
            head_ = new Node(v, head_);
        } catch (const std::bad_alloc& e) {
            Error("out of memory");
        }
    }
    T Pop() {
        if (Empty()) Error("stack is empty");
        T v = head_->v;
        Link t = head_->next;
        delete head_;
        head_ = t;
        return v;
    }
    std::size_t Size() const {
        std::size_t ret = 0;
        for (Link n = head_; n; n = n->next) {
            ++ret;
        }

        return ret;
    }

   private:
    void Error(const char* msg) const { throw std::length_error(msg); }

   private:
    Link head_;
};

#endif /* PROGRAM_4_8_H */
