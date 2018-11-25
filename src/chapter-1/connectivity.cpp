// connectivity problem

#include <algorithm>
#include <array>
#include <iostream>
#include <list>
#include <random>
#include <utility>

class Connectivity {
   protected:
    std::vector<int> id_;
    int n_ = 0;
    int accesses_ = 0;
    int prev_accesses_ = 0;

   public:
    explicit Connectivity(int n = 10) { reset(n); }

    void run(const std::list<std::pair<int, int>>& pairs) {
        for (const auto& p : pairs) {
            add(p.first, p.second);
        }
        std::cout << "total accesses: " << accesses_ << "\n\n";
    }

    void randomInput(const std::vector<int> sizes) {
        std::random_device rd;
        std::mt19937 gen(rd());

        // ex.1.22
        // generat random pairs of numbers 0..N-1
        // add pairs until N-1 union happened
        // print amount of edges in graph
        for (int n : sizes) {
            std::cout << "N = " << n << ' ';
            std::uniform_int_distribution<int> dist(0, n - 1);
            reset(n);
            int unions = 0;
            int edges = 0;
            do {
                ++edges;
                if (!add_impl(dist(gen), dist(gen))) ++unions;
            } while (unions < n - 1);
            std::cout << "done\n";
            std::cout << "edges = " << edges << "\n\n";
        }
    }

   protected:
    virtual void reset(int n) {
        n_ = n;
        id_.resize(n_);
        std::iota(id_.begin(), id_.end(), 0);
    }

    void add(int p, int q) {
        std::cout << "input " << p << ',' << q << '\t';
        if (add_impl(p, q)) {
            std::cout << "found ";
        } else {
            std::cout << "merge ";
        }
        print();
    }

    virtual bool add_impl(int p, int q) = 0;

    virtual void print(int i) { std::cout << id_[i] << ' '; }

    void print() {
        std::cout << "id: ";
        for (int i = 0; i < n_; ++i) {
            print(i);
        }
        std::cout << '\t';

        std::cout << " accesses: " << accesses_ - prev_accesses_ << '\n';
        prev_accesses_ = accesses_;
    }

    int& at(int i) {
        ++accesses_;
        return id_.at(i);
    }
};

// program 1.1
// find: objects p & q are connected if a[p] == a[q]
// union: (all objects with a[p] value) = a[q]
class QuickFind : public Connectivity {
   public:
    bool add_impl(int p, int q) override {
        // quick find
        if (at(p) == at(q)) return true;

        // slow union
        const int t = at(p);
        for (int i = 0; i < n_; ++i) {
            if (at(i) == t) at(i) = at(q);
        }

        return false;
    }
};

// program 1.2
// find: i -> a[i], represents link to parent object,
// a[i] == i - means that i is root
// if roots for i & j are same - they connected
// union: a[i] = j, make i node child of j node
class QuickUnion : public Connectivity {
   public:
    bool add_impl(int p, int q) override {
        // slow find
        int i, j;
        for (i = p; i != at(i); i = at(i))
            ;
        for (j = q; j != at(j); j = at(j))
            ;
        if (i == j) return true;

        // quick union
        at(i) = j;

        return false;
    }
};

// program 1.3
// find: i -> a[i], represents link to parent object,
// a[i] == i - means that i is root
// if roots for i & j are same - they connected
// union: make link as in program 1.2 but connect lesser tree with bigger tree
class WeightedQuickUnion : public Connectivity {
   protected:
    std::vector<int> sz_;

    void print(int i) override { std::cout << id_[i] << '(' << sz_[i] << ") "; }

   public:
    explicit WeightedQuickUnion(int n = 10) { reset(n); }

    bool add_impl(int p, int q) override {
        // slow find
        int i, j;
        for (i = p; i != at(i); i = at(i))
            ;
        for (j = q; j != at(j); j = at(j))
            ;
        if (i == j) return true;

        // check size of tree & join with smallest
        if (sz_[i] < sz_[j]) {
            at(i) = j;
            sz_[j] += sz_[i];
        } else {
            at(j) = i;
            sz_[i] += sz_[j];
        }

        return false;
    };

   protected:
    void reset(int n) override {
        Connectivity::reset(n);
        sz_.resize(n_);
        std::fill(sz_.begin(), sz_.end(), 1);
    }
};

// program 1.4
// find: i -> a[i], represents link to parent object,
// a[i] == i - means that i is root, also create links
// for i to current grandparent (a[i] - parent, a[a[i]] - grandparent)
// if roots for i & j are same - they connected
// union: make link as in program 1.2 but connect lesser tree with bigger tree
class WeightedQuickUnionWithPathCompressionByHalving : public Connectivity {
   protected:
    std::vector<int> sz_;

    void print(int i) override { std::cout << id_[i] << '(' << sz_[i] << ") "; }

   public:
    explicit WeightedQuickUnionWithPathCompressionByHalving(int n = 10) {
        reset(n);
    }

    bool add_impl(int p, int q) override {
        // slow find
        int i, j;
        for (i = p; i != at(i); i = at(i)) at(i) = at(at(i));
        for (j = q; j != at(j); j = at(j)) at(j) = at(at(j));
        if (i == j) return true;

        // check size of tree & join with smallest
        if (sz_[i] < sz_[j]) {
            at(i) = j;
            sz_[j] += sz_[i];
        } else {
            at(j) = i;
            sz_[i] += sz_[j];
        }

        return false;
    }

   protected:
    void reset(int n) override {
        Connectivity::reset(n);
        sz_.resize(n_);
        std::fill(sz_.begin(), sz_.end(), 1);
    }
};

// ex 1.16
// find: i -> a[i], represents link to parent object,
// a[i] == i - means that i is root, also create links
// for i to root of parent
// if roots for i & j are same - they connected
// union: make link as in program 1.2 but connect lesser tree with bigger tree
class WeightedQuickUnionWithPathFullCompression : public Connectivity {
   protected:
    std::vector<int> sz_;

    void print(int i) override { std::cout << id_[i] << '(' << sz_[i] << ") "; }

   public:
    explicit WeightedQuickUnionWithPathFullCompression(int n = 10) { reset(n); }

    bool add_impl(int p, int q) override {
        // slow find
        int i, j;
        for (i = p; i != at(i); i = at(i))
            ;
        for (j = q; j != at(j); j = at(j))
            ;
        if (i == j) return true;

        // check size of tree & join with smallest
        int root = -1;
        if (sz_[i] < sz_[j]) {
            at(i) = j;
            sz_[j] += sz_[i];
            root = j;
        } else {
            at(j) = i;
            sz_[i] += sz_[j];
            root = i;
        }

        // path compression
        i = p;
        while (i != at(i)) {
            int parent = at(i);
            at(i) = root;
            i = parent;
        }

        j = q;
        while (j != at(j)) {
            int parent = at(j);
            at(j) = root;
            j = parent;
        }

        return false;
    }

   protected:
    void reset(int n) override {
        Connectivity::reset(n);
        sz_.resize(n_);
        std::fill(sz_.begin(), sz_.end(), 1);
    }
};

int main() {
    typedef std::list<std::pair<int, int>> Input;
    Input input1_1 = {{0, 2}, {1, 4}, {2, 5}, {3, 6}, {0, 4}, {6, 0}, {1, 3}};

    Input input1_7 = {{3, 4}, {4, 9}, {8, 0}, {2, 3}, {5, 6},
                      {5, 9}, {7, 3}, {8, 4}, {6, 1}};
    Input input1_8 = {{0, 1}, {2, 3}, {4, 5}, {6, 7}, {8, 9},
                      {0, 2}, {4, 6}, {0, 4}, {6, 8}};
    Input input1_9 = {{3, 4}, {4, 9}, {8, 0}, {2, 3}, {5, 6},
                      {5, 9}, {7, 3}, {8, 4}, {6, 1}};
    // ex.1.4
    {
        QuickFind f;
        std::cout << "quick find:\n";
        f.run(input1_1);
    }

    // ex.1.5
    {
        QuickUnion u;
        std::cout << "quick union:\n";
        u.run(input1_1);
    }

    // ex.1.6
    {
        WeightedQuickUnion w;
        std::cout << "weighted quick union (figure 1.7):\n";
        w.run(input1_7);
    }
    {
        WeightedQuickUnion w;
        std::cout << "weighted quick union (figure 1.8):\n";
        w.run(input1_8);
    }

    // ex.1.7
    {
        WeightedQuickUnion w;
        std::cout << "weighted quick union (figure 1.1):\n";
        w.run(input1_1);
    }

    // ex.1.8
    {
        WeightedQuickUnionWithPathCompressionByHalving h;
        std::cout << "weighted quick union w/ compression by halving:\n";
        h.run(input1_1);
    }

    // ex.1.17
    {
        WeightedQuickUnionWithPathFullCompression c;
        std::cout << "weighted quick union w/ full compression:\n";
        c.run(input1_9);
    }

    // ex.1.22
    {
        WeightedQuickUnionWithPathCompressionByHalving h;
        std::cout << "weighted quick union w/ compression by halving on random "
                     "numbers:\n";
        h.randomInput({1'000, 10'000, 100'000, 1'000'000});
    }

    return 0;
}
