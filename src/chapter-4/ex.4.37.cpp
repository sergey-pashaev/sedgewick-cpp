// ex.4.36

// en: A letter means put and an asterisk means get in the sequence
//   E A S * Y * Q U E * * * S T * * * I O * N * * *
// Give the sequence of values returned by the get operations when
// this sequence of operations is performed on an initially empty FIFO
// queue.

// ru: В последовательности
//   E A S * Y * Q U E * * * S T * * * I O * N * * *
// буква означает операцию занести, а звездочка - операцию
// извлечь. Найдите последовательность значений, возвращаемых
// операциями извлечь, если эта последовательность операций
// выполняется над первоначально пустой очередью FIFO.

#include <iostream>

#include "program.4.15.h"

int main() {
    Queue<char> q{10};
    const char* input = "EAS*Y*QUE***ST***IO*N***";
    while (*input) {
        if (*input == '*')
            std::cout << q.Get() << '\n';
        else
            q.Put(*input);

        ++input;
    }

    return 0;
}
