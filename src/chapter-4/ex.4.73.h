#ifndef EX_4_73_H
#define EX_4_73_H

// ex.4.73

// en: Write an interface for a first-class pushdown-stack ADT.

// ru: Напишите интерфейс АТД первого класса для стэка.

#include <cstddef>

template <typename T>
class Stack {
   public:
    explicit Stack(std::size_t capacity);
    Stack(const Stack& other);
    Stack(Stack&& other);
    Stack& operator=(Stack other);
    ~Stack();

    bool Empty() const;
    std::size_t Size() const;
    const T& Top() const;
    T Pop();
    void Push(const T& v);
};

#endif /* EX_4_73_H */
