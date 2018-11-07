#ifndef PSV_LIST_H
#define PSV_LIST_H

#include <array>
#include <cstddef>

namespace psv {

template <typename T>
class Node {
   public:
    // default ctor
    Node() : next_(nullptr) {}

    // create node w/ value & empty link
    Node(const T& value) : value_(value), next_(nullptr) {}

    // get value
    T value() const { return value_; }

    // set value
    void value(T value) { value_ = value; }

    // get link to next node
    Node* next() const { return next_; }

    // set link to next node
    Node* next(Node* node) { return next_ = node; }

   private:
    T value_;
    Node* next_;
};

// Return length of circular list
template <typename T>
size_t LengthCircular(const Node<T>* node) {
    size_t len = 1;
    for (const Node<T>* cur = node->next(); cur && cur != node;
         cur = cur->next())
        ++len;
    return len;
}

};  // namespace psv

#endif /* PSV_LIST_H */
