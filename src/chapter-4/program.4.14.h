#ifndef PROGRAM_4_14_H
#define PROGRAM_4_14_H

// program.4.14

// en: FIFO queue linked-list implementation

// ru: Реализация очереди FIFO на базе связного списка

template <typename T>
class Queue {
   private:
    struct node {
        node(T v) : item{v}, next{nullptr} {}

        T item;
        node* next;
    };
    typedef node* link;
    link head_;
    link tail_;

   public:
    Queue(int) { head_ = nullptr; }

    ~Queue() {
        link cur = head_;
        while (cur) {
            link next = cur->next;
            delete cur;
            cur = next;
        }
    }

    bool empty() const { return head_ == nullptr; }

    void put(T x) {
        link t = tail_;
        tail_ = new node(x);

        if (head_) {
            t->next = tail_;
        } else {
            head_ = tail_;
        }
    }

    T get() {
        T v = head_->item;
        link t = head_->next;
        delete head_;
        head_ = t;
        return v;
    }

   private:
};

#endif /* PROGRAM_4_14_H */
