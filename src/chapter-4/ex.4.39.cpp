// ex.4.39

// en: Modify the linked-list–based FIFO queue implementation in the
// text (Program 4.14) to call a function error() if the client
// attempts to get when the queue is empty or if there is no memory
// available from new for a put.

// ru: Измените приведенную в тексте реализацию очереди FIFO на базе
// связного списка (программа 4.14) так, чтобы в ней вызывалась
// функция error(), если клиент пытается выполнить операцию извлечь,
// когда очередь пуста, или если при выполнении new для операции
// занести отсутствует доступная память.

#include <memory>
#include <stdexcept>

#include <catch.hpp>

bool fail_alloc = false;

template <typename T>
class Queue {
   private:
    struct node {
        node(T v) : item{v}, next{nullptr} {}

        void* operator new(std::size_t size) {
            if (fail_alloc) {
                throw std::bad_alloc();
            }

            return ::malloc(size);
        }

        void operator delete(void* p) { ::free(p); }

        T item;
        node* next;
    };
    typedef node* link;
    link head_;
    link tail_;

   public:
    Queue(int) { head_ = nullptr; }

    bool empty() const { return head_ == nullptr; }

    void put(T x) {
        link t = tail_;
        try {
            tail_ = new node(x);
        } catch (const std::bad_alloc& e) {
            throw std::length_error("queue is full (out of memory)");
        }

        if (head_) {
            t->next = tail_;
        } else {
            head_ = tail_;
        }
    }

    T get() {
        if (empty()) error("queue is empty");
        T v = head_->item;
        link t = head_->next;
        delete head_;
        head_ = t;
        return v;
    }

   private:
    void error(const char* msg) const { throw std::length_error(msg); }
};

TEST_CASE("empty queue") {
    Queue<int> q{3};
    REQUIRE_THROWS_AS(q.get(), std::length_error);
}

TEST_CASE("full queue") {
    Queue<int> q{3};
    q.put(1);
    q.put(2);
    q.put(3);
    fail_alloc = true;
    REQUIRE_THROWS_AS(q.put(4), std::length_error);
    fail_alloc = false;
}
