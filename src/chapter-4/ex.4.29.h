#ifndef EX_4_29_H
#define EX_4_29_H

// ex.4.29

// en: Modify Program 4.11 to use path compression by halving.

// ru: Измените программу 4.11 так, чтобы в ней использовалось сжатие
// пути делением пополам.

class UF {
   public:
    UF(int n) : id_{new int[n]}, sz_{new int[n]} {
        for (int i = 0; i < n; ++i) {
            id_[i] = i;
            sz_[i] = 1;
        }
    }

    int find(int p, int q) { return find(p) == find(q); }

    void unite(int p, int q) {
        int i = find(p);
        int j = find(q);
        if (i == j) return;
        if (sz_[i] < sz_[j]) {
            id_[i] = j;
            sz_[j] += sz_[i];
        } else {
            id_[j] = i;
            sz_[i] += sz_[j];
        }
    }

   private:
    int find(int x) {
        while (x != id_[x]) {
            id_[x] = id_[id_[x]];
            x = id_[x];
        }
        return x;
    }

   private:
    int* id_;
    int* sz_;
};

#endif /* EX_4_29_H */
