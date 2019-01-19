#ifndef PROGRAM_5_6_H
#define PROGRAM_5_6_H

// program 5.6

// en: Divide-and-conquer to find the maximum

// ru: Применение принципа "разделяй и властвуй" для отыскания
// максимума

template <typename T>
T max(T a[], int l, int r) {
    if (l == r) return a[l];
    int m = (l + r) / 2;
    T u = max(a, l, m);
    T v = max(a, m + 1, r);
    return u > v ? u : v;
}

#endif /* PROGRAM_5_6_H */
