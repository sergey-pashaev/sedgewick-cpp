// ex.4.40

// en: An uppercase letter means put at the beginning, a lowercase letter
// means put at the end, a plus sign means get from the beginning, and an
// asterisk means get from the end in the sequence
//   E A s + Y + Q U E * * + s t + * + I O * n + + *
// Give the sequence of values returned by the get operations when this
// sequence of operations is performed on an initially empty deque.

// ru: В последовательности
//   E A s + Y + Q U E * * + s t + * + I O * n + + *
// прописные буквы означают операцию занести в начале дэка, строчные
// буквы - операцию занести в конце дека, знак плюс означает операцию
// извлечь в начале, а звездочка - операцию извлечь в конце. Найдите
// последовательность значений, возвращаемых операциями извлечь, если эта
// последовательность операций выполняется над первоначально пустым
// дэком.

#include <cctype>
#include <iostream>
#include <stdexcept>

template <typename T>
class Deque {
   public:
    Deque(int capacity)
        : n_(capacity + 1), q_(new T[n_]), head_(n_), tail_(0) {}

    bool Empty() const { return head_ % n_ == tail_; }

    bool Full() const { return tail_ + 1 == head_; }

    void PushFront(T v) {
        if (Full()) Error("deque is full");
        --head_;
        if (head_ < 0) head_ = n_ - 1;
        q_[head_] = v;
    }

    void PushBack(T v) {
        if (Full()) Error("deque is full");
        q_[tail_++] = v;
        tail_ %= n_;
    }

    T PopFront() {
        if (Empty()) Error("deque is empty");
        head_ %= n_;
        return q_[head_++];
    }

    T PopBack() {
        if (Empty()) Error("deque is empty");
        --tail_;
        if (tail_ < 0) tail_ = n_ - 1;
        return q_[tail_];
    }

   private:
    void Error(const char* msg) const { throw std::length_error(msg); }

   private:
    int n_;
    T* q_;
    int head_;
    int tail_;
};

int main() {
    Deque<char> d{20};
    const char* input = "EAs+Y+QUE**+st+*+IO*n++*";
    while (*input) {
        const char c = *input;
        if (c == '+') {
            std::cout << d.PopFront() << '\n';
        } else if (c == '*') {
            std::cout << d.PopBack() << '\n';
        } else if (std::isupper(c)) {
            d.PushFront(c);
        } else if (std::islower(c)) {
            d.PushBack(c);
        }

        ++input;
    }

    return 0;
}
