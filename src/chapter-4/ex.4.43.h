#ifndef EX_4_43_H
#define EX_4_43_H

// ex.4.43

// en: Write an interface for the deque ADT.

// ru: Напишите интерфейс для АТД дека.

template <typename T>
class Deque {
   public:
    Deque(int);
    ~Deque();
    bool Empty() const;
    void PushFront(T v);
    void PushBack(T v);
    T PopFront();
    T PopBack();
};

#endif /* EX_4_43_H */
