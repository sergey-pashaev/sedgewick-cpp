#ifndef PSV_ARRAY_H
#define PSV_ARRAY_H

#include <cstddef>
#include <ostream>

namespace psv {

template <typename T>
struct Array2D {
    Array2D(std::size_t rows, std::size_t cols)
        : rows_(rows), cols_(cols), data(nullptr) {
        data = new T*[rows_];
        for (std::size_t i = 0; i < rows_; ++i) {
            data[i] = new T[cols_];
        }
    }

    ~Array2D() {
        for (std::size_t i = 0; i < rows_; ++i) {
            delete[] data[i];
        }

        delete[] data;
    }

    template <typename F>
    void ForEach(F func) {
        for (std::size_t i = 0; i < rows_; ++i) {
            for (std::size_t j = 0; j < cols_; ++j) {
                func(data[i][j]);
            }
        }
    }

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const Array2D<U>& arr);

    std::size_t rows_;
    std::size_t cols_;
    T** data;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Array2D<T>& arr) {
    for (std::size_t i = 0; i < arr.rows_; ++i) {
        for (std::size_t j = 0; j < arr.cols_; ++j) {
            os << arr.data[i][j] << (j == arr.cols_ - 1 ? '\n' : ' ');
        }
    }

    return os;
}

}  // namespace psv

#endif /* PSV_ARRAY_H */
