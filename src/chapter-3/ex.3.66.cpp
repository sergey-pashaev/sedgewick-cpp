// ex.3.66

// en: Write a program to convert a sparse matrix from a
// two-dimensional array to a multilist with nodes for only nonzero
// values.

// ru: Напишите программу преобразования разреженной матрицы из
// двумерного массива в мультисписок с узлами только для ненулевых
// значений.

#include <iostream>
#include <memory>
#include <random>

#include <psv/array.h>

template <typename T>
struct mnode {
    T v;
    mnode* next_row;
    mnode* next_col;
    std::size_t row;
    std::size_t col;

    mnode() : v(0), next_row(nullptr), next_col(nullptr), row(0), col(0) {}

    mnode(T v, std::size_t row, std::size_t col)
        : v(v), next_row(nullptr), next_col(nullptr), row(row), col(col) {}
};

template <typename T>
using link = mnode<T>*;

int usage(const char* bin) {
    std::cout << "Usage: " << bin << " <positive int N - matrix size>\n";
    return 1;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        return usage(argv[0]);
    }

    int N = std::atoi(argv[1]);
    if (N <= 0) {
        return usage(argv[0]);
    }

    // allocate & fill array
    auto arr = psv::Array2D<int>(N, N);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 1);
    arr.for_each([&dist, &gen](int& v) { v = dist(gen); });

    std::cout << "Array: \n" << arr << '\n';

    // transform
    mnode<int>* rhead = new mnode<int>[arr.rows_];
    mnode<int>* chead = new mnode<int>[arr.cols_];

    // stich by columns
    for (std::size_t i = 0; i < arr.rows_; ++i) {
        mnode<int>* cur_row = nullptr;
        for (std::size_t j = 0; j < arr.cols_; ++j) {
            if (!arr.data[i][j]) continue;

            auto node = new mnode<int>{arr.data[i][j], i, j};
            if (!cur_row) {
                rhead[i].next_col = node;
            } else {
                cur_row->next_col = node;
            }

            cur_row = node;
        }
    }

    // stich by rows
    for (std::size_t j = 0; j < arr.cols_; ++j) {
        mnode<int>* cur_col = &chead[j];
        for (std::size_t i = 0; i < arr.rows_; ++i) {
            auto node = rhead[i].next_col;
            while (node) {
                if (node->col == j) {
                    cur_col->next_row = node;
                    cur_col = node;
                    break;
                }

                node = node->next_col;
            }
        }
    }

    std::cout << "iterate by rows:\n";
    for (std::size_t i = 0; i < arr.rows_; ++i) {
        for (auto n = rhead[i].next_col; n; n = n->next_col) {
            std::cout << n->v << '[' << n->row << ',' << n->col << ']'
                      << (n->next_col ? " " : "");
        }
        std::cout << '\n';
    }

    std::cout << "iterate by cols:\n";
    for (std::size_t i = 0; i < arr.cols_; ++i) {
        for (auto n = chead[i].next_row; n; n = n->next_row) {
            std::cout << n->v << '[' << n->row << ',' << n->col << ']'
                      << (n->next_row ? " " : "");
        }
        std::cout << '\n';
    }

    // cleanup
    for (std::size_t i = 0; i < arr.rows_; ++i) {
        auto n = rhead[i].next_col;
        while (n) {
            auto next = n->next_col;
            delete n;
            n = next;
        }
    }

    delete[] rhead;
    delete[] chead;
}
