// ex.4.21

// en: Give the contents of s[0], ..., s[4] after the execution of the
// operations illustrated in Figure 4.1, using Program 4.7.

// ru: Определите содержимое элементов s[0], ..., s[4] после
// выполнения программой 4.7 операций, показанных на рис. 4.1.

#include <iostream>

#include "program.4.7.h"

template <typename T>
struct StackGhost {
    T* s_;
    int n_;
};

int main() {
    Stack<char> s{10};
    const char* input = "LA*STI*N*FIR*ST**OU*T*******";
    while (*input) {
        if (*input == '*')
            s.pop();
        else
            s.push(*input);

        ++input;
    }

    StackGhost<char>* g = reinterpret_cast<StackGhost<char>*>(&s);
    for (auto i = 0; i < 5; ++i) {
        std::cout << "s[" << i << "]=" << g->s_[i] << '\n';
    }
    return 0;
}
