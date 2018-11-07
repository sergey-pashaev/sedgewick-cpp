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

// Return number of nodes between nodes a & b in a circular list
template <typename T>
size_t BetweenCircular(const Node<T>* a, const Node<T>* b) {
    if (a == b) return 0;
    size_t n = 0;
    for (const Node<T>* cur = a->next(); cur && cur != a & cur != b;
         cur = cur->next())
        ++n;
    return n;
}

// Make list out of array of values
// Return head of list
template <typename T, std::size_t N>
Node<T>* Make(const std::array<T, N>& vals) {
    auto head = new Node<T>;
    auto cur = head;
    for (std::size_t i = 0; i < N; ++i) {
        cur = cur->next(new Node<T>(vals[i]));
    }

    return head;
}

// Free list, including head node
template <typename T>
void Free(Node<T>* head) {
    auto cur = head->next();
    while (cur) {
        auto next = cur->next();
        delete cur;
        cur = next;
    }

    delete head;
}

// list[i].value() == vals[i] ?
template <int N, typename T>
bool Equal(const Node<T>* head, const std::array<T, N>& vals) {
    size_t i = 0;
    for (auto cur = head->next(); cur; cur = cur->next()) {
        if (cur->value() != vals[i++]) return false;
    }

    return true;
}

// Make copy out of src list
template <typename T>
Node<T>* Copy(const Node<T>* src) {
    auto head = new Node<T>;
    auto copy = head;
    for (auto cur = src->next(); cur; cur = cur->next()) {
        copy = copy->next(new Node<T>(cur->value()));
    }

    return head;
}

// Remove node if f(node) == true
template <typename T, typename F>
void RemoveIf(Node<T>* head, F f) {
    for (auto cur = head; cur;) {
        Node<T>* x = cur->next();
        if (x && f(x)) {
            auto t = x->next();
            delete x;
            cur->next(t);
        } else {
            cur = cur->next();
        }
    }
}

// Copy node if f(node) == true
template <typename T, typename F>
Node<T>* CopyIf(const Node<T>* src, F f) {
    Node<T>* head = new Node<T>;
    auto copy = head;
    for (auto cur = src->next(); cur; cur = cur->next()) {
        if (f(cur)) copy = copy->next(new Node<T>(cur->value()));
    }

    return head;
}

// Reverse list
template <typename T>
void Reverse(Node<T>* head) {
    auto cur = head->next();
    Node<T>* prev = nullptr;
    Node<T>* next = nullptr;
    while (cur) {
        next = cur->next();
        cur->next(prev);
        prev = cur;
        cur = next;
    }

    head->next(prev);
}

};  // namespace psv

#endif /* PSV_LIST_H */
