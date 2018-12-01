// ex.4.50

// en: Write a client that picks numbers for a lottery by putting the
// numbers 1 through 99 on a random queue, then prints the result of
// removing five of them.

// ru: Напишите программу-клиент, которая выбирает для лотереи числа
// следующим образом: заносит в неупорядоченную очередь числа от 1 до
// 99, а затем выводит результат удаления пяти чисел.

#include <iostream>

#include <psv/random_queue.h>

int main() {
    std::size_t from = 1;
    std::size_t to = 99;
    psv::RandomQueue<int> q{to};
    for (std::size_t i = from; i <= to; ++i) {
        q.Push(i);
    }

    std::size_t to_remove = 5;
    for (std::size_t i = 0; i < to_remove; ++i) {
        std::cout << q.Pop() << '\n';
    }

    return 0;
}
