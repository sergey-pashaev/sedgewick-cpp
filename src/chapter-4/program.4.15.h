#ifndef PROGRAM_4_15_H
#define PROGRAM_4_15_H

// program.4.15

// en: FIFO queue array implementation

// ru: Реализация очереди FIFO на базе массива

template <typename T>
class Queue {
   public:
    explicit Queue(int capacity)
        : n_(capacity + 1), q_(new T[n_]), head_(n_), tail_(0) {}

    ~Queue() { delete[] q_; }

    bool empty() const { return head_ % n_ == tail_; }

    void put(T v) {
        q_[tail_++] = v;
        tail_ %= n_;
    }

    T get() {
        head_ %= n_;
        return q_[head_++];
    }

   private:
    int n_;
    T* q_;
    int head_;
    int tail_;
};

#endif /* PROGRAM_4_15_H */
