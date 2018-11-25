#ifndef PROGRAM_3_16_H
#define PROGRAM_3_16_H

// program.3.16

// en: Two-dimensional array allocation

// ru: Выделение памяти под двумерный массив

int** Malloc2D(int r, int c) {
    int** t = new int*[r];
    for (int i = 0; i < r; ++i) {
        t[i] = new int[c];
    }

    return t;
}

void Free2D(int** p, int r) {
    for (int i = 0; i < r; ++i) {
        delete[] p[i];
    }

    delete[] p;
}

#endif /* PROGRAM_3_16_H */
