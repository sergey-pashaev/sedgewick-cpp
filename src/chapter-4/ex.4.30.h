#ifndef EX_4_30_H
#define EX_4_30_H

// ex.4.30

// en: Modify our equivalence-relations interface (Program 4.9) and
// implementation (Program 4.11) to provide a function that will
// return the number of nodes known to be connected to a given node.

// ru: Устраните упоминаемую в тексте неэффективность программы
// добавив в программу 4.9 операцию, которая объединяет операции
// объединение и поиск, и соответствующим образом изменив программы
// 4.11 и 4.10.

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

    bool unite(int p, int q) {
        int i = find(p);
        int j = find(q);
        if (i == j) return false;
        if (sz_[i] < sz_[j]) {
            id_[i] = j;
            sz_[j] += sz_[i];
        } else {
            id_[j] = i;
            sz_[i] += sz_[j];
        }

        return true;
    }

   private:
    int find(int x) {
        while (x != id_[x]) x = id_[x];
        return x;
    }

   private:
    int* id_;
    int* sz_;
};

#endif /* EX_4_30_H */
