// ex.4.36

// en: Give the contents of q[0], ..., q[4] after the execution of the
// operations illustrated in Figure 4.6, using Program 4.15. Assume
// that maxN is 10, as in Figure 4.8.

// ru: Найдите содержимое элементов q[0], ..., q[4] после выполнения
// программой 4.15 операций, показанных на рис 4.6. Считайте, что
// maxN, как и на рис. 4.8, равно 10.

#include <iostream>

#include "program.4.15.h"

template <typename T>
struct QueueGhost {
    int n_;
    T* q_;
    int head_;
    int tail_;
};

int main() {
    Queue<char> q{10};
    const char* input = "FIRS*T*IN***FI*RS***T*OUT*****";
    while (*input) {
        if (*input == '*')
            q.Get();
        else
            q.Put(*input);

        ++input;
    }

    QueueGhost<char>* g = reinterpret_cast<QueueGhost<char>*>(&q);
    for (auto i = 0; i < 5; ++i) {
        std::cout << "q[" << i << "]=" << g->q_[i] << '\n';
    }

    return 0;
}
