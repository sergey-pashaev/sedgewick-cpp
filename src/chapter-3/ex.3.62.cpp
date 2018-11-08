// ex.3.62

// en: Write a version of Program 3.16 that handles three-dimensional
// arrays.

// ru: Напишите версию программы 3.16, обрабатывающую трехмерные
// массивы.

#include <iostream>

int*** malloc3d(int x, int y, int z) {
    int*** a = new int**[x];
    for (int i = 0; i < x; ++i) {
        a[i] = new int*[y];
        for (int j = 0; j < y; ++j) {
            a[i][j] = new int[z];
        }
    }

    return a;
}

void free3d(int*** a, int x, int y) {
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            delete[] a[i][j];
        }

        delete[] a[i];
    }

    delete[] a;
}

int usage(const char* bin) {
    std::cout << "Usage: " << bin
              << " <positive int X> <positive int Y> <positive int Z>\n";
    return 1;
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        return usage(argv[0]);
    }

    const int X = std::atoi(argv[1]);
    const int Y = std::atoi(argv[2]);
    const int Z = std::atoi(argv[3]);
    if (X <= 0 || Y <= 0 || Z <= 0) {
        return usage(argv[0]);
    }

    auto p = malloc3d(X, Y, Z);

    for (int k = 0; k < Z; ++k)
        for (int j = 0; j < Y; ++j)
            for (int i = 0; i < X; ++i) p[i][j][k] = 1;

    free3d(p, X, Y);

    return 0;
}
