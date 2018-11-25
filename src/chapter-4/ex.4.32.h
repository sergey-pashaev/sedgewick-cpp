#ifndef EX_4_32_H
#define EX_4_32_H

// ex.4.32

// en: Modify Program 4.11 to use an array of structures instead of
// parallel arrays for the underlying data structure.

// ru: Измените программу 4.11 так, чтобы для представления структуры
// данных в ней вместо параллельных массивов использовался массив
// структур.

class UF {
   private:
    struct node {
        int id = 0;
        int sz = 1;
    };

   public:
    explicit UF(int n) : nodes_{new node[n]} {
        for (int i = 0; i < n; ++i) {
            nodes_[i].id = i;
        }
    }

    ~UF() { delete[] nodes_; }

    int find(int p, int q) { return find(p) == find(q); }

    void unite(int p, int q) {
        int i = find(p);
        int j = find(q);
        if (i == j) return;
        if (nodes_[i].sz < nodes_[j].sz) {
            nodes_[i].id = j;
            nodes_[j].sz += nodes_[i].sz;
        } else {
            nodes_[j].id = i;
            nodes_[i].sz += nodes_[j].sz;
        }
    }

   private:
    int find(int x) {
        while (x != nodes_[x].id) x = nodes_[x].id;
        return x;
    }

   private:
    node* nodes_;
};

#endif /* EX_4_32_H */
