#ifndef EX_4_29_H
#define EX_4_29_H

// ex.4.29

// en: Modify Program 4.11 to use path compression by halving.

// ru: Измените программу 4.11 так, чтобы в ней использовалось сжатие
// пути делением пополам.

class UF {
   public:
    explicit UF(int n) : id_{new int[n]}, sz_{new int[n]} {
        for (int i = 0; i < n; ++i) {
            id_[i] = i;
            sz_[i] = 1;
        }
    }

    ~UF() {
        delete[] id_;
        delete[] sz_;
    }

    int Find(int p, int q) { return Find(p) == Find(q); }

    void Unite(int p, int q) {
        int i = Find(p);
        int j = Find(q);
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
    int Find(int x) {
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
