// ex.4.64

// en: Convert the equivalence-relations ADT in Section 4.5 to a
// first-class type.

// ru: Преобразуйте АТД отношения эквивалентности (из раздела 4.5) в
// тип данных первого класса.

#include <algorithm>
#include <cstddef>

#include <catch.hpp>

class UF {
   private:
    struct Node {
        int id = 0;
        int sz = 1;
    };

   public:
    explicit UF(std::size_t size = 0)
        : size_{size}, nodes_{size_ ? new Node[size_] : nullptr} {
        for (std::size_t i = 0; i < size_; ++i) {
            nodes_[i].id = i;
        }
    }

    UF(const UF& other)
        : size_{other.size_}, nodes_{size_ ? new Node[size_] : nullptr} {
        std::copy(other.nodes_, other.nodes_ + size_, nodes_);
    }

    UF(UF&& other) : UF() { swap(*this, other); }

    UF& operator=(UF other) {
        swap(*this, other);
        return *this;
    }

    friend void swap(UF& lhs, UF& rhs) noexcept {
        using std::swap;
        swap(lhs.size_, rhs.size_);
        swap(lhs.nodes_, rhs.nodes_);
    }

    ~UF() { delete[] nodes_; }

    int Find(int p, int q) { return Find(p) == Find(q); }

    void Unite(int p, int q) {
        int i = Find(p);
        int j = Find(q);
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
    int Find(int x) {
        while (x != nodes_[x].id) {
            nodes_[x].id = nodes_[nodes_[x].id].id;
            x = nodes_[x].id;
        }
        return x;
    }

   private:
    std::size_t size_;
    Node* nodes_;
};

struct TestCase {
    int p;
    int q;
    bool found;
};

std::vector<TestCase> test_set_1 = {
    {3, 4, false}, {4, 9, false}, {8, 0, false}, {2, 3, false},
    {5, 6, false}, {2, 9, true},  {5, 9, false}, {7, 3, false},
    {4, 8, false}, {5, 6, true},  {0, 2, true},  {6, 1, false}};

std::vector<TestCase> test_set_2 = {{0, 2, false}, {1, 4, false}, {2, 5, false},
                                    {3, 6, false}, {0, 4, false}, {6, 0, false},
                                    {1, 3, true}};

void test(UF& uf, const std::vector<TestCase>& test_set) {
    for (const auto& test : test_set) {
        bool found = uf.Find(test.p, test.q);
        REQUIRE(found == test.found);
        if (!found) {
            uf.Unite(test.p, test.q);
        }
    }
}

TEST_CASE("normal usage") {
    UF uf1(100);
    UF uf2(uf1);
    UF uf3 = uf2;

    SECTION("test set 1") {
        test(uf1, test_set_1);
        test(uf2, test_set_1);
        test(uf3, test_set_1);
    }

    SECTION("test set 2") {
        test(uf1, test_set_2);
        test(uf2, test_set_2);
        test(uf3, test_set_2);
    }
}
