#ifndef PROGRAM_4_14_H
#define PROGRAM_4_14_H

// program.4.14

// en: FIFO queue linked-list implementation

// ru: Реализация очереди FIFO на базе связного списка

template <typename T>
class Queue {
   private:
    struct Node {
        Node(T v) : item{v}, next{nullptr} {}

        T item;
        Node* next;
    };
    typedef Node* Link;
    Link head_;
    Link tail_;

   public:
    Queue(int) { head_ = nullptr; }

    ~Queue() {
        Link cur = head_;
        while (cur) {
            Link next = cur->next;
            delete cur;
            cur = next;
        }
    }

    bool Empty() const { return head_ == nullptr; }

    void Put(T x) {
        Link t = tail_;
        tail_ = new Node(x);

        if (head_) {
            t->next = tail_;
        } else {
            head_ = tail_;
        }
    }

    T Get() {
        T v = head_->item;
        Link t = head_->next;
        delete head_;
        head_ = t;
        return v;
    }

   private:
};

#endif /* PROGRAM_4_14_H */
