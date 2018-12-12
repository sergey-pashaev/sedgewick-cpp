// ex.4.78

// en: Provide an implementation for the polynomial ADT given in the
// text (Program 4.24) that uses linked lists as the underlying data
// structure. Your lists should not contain any nodes corresponding to
// terms with coefficient value 0.

// ru: Напишите реализацию для приведенного в тексте АТД полинома
// (программа 4.24), в которой в качестве базовой структуры данных
// используются связные списки. Списки не должны содержать узлов,
// соответствующих членам с нулевыми коэфициентами.

#include <cmath>
#include <iostream>
#include <ostream>

#include <catch.hpp>

template <typename T>
class Poly {
   private:
    struct Node {
        Node(T v, int exp, Node* n = nullptr) : v{v}, exp{exp}, next{n} {}

        T v;
        int exp;
        Node* next;
    };

   public:
    Poly() : head_{nullptr} {}

    Poly(T v, int exp) { head_ = new Node(v, exp, nullptr); }

    Poly(const Poly& other) : head_{nullptr} {
        for (const Node* cur = other.head_; cur; cur = cur->next) {
            AddSorted(*cur);
        }
    }

    Poly(Poly&& other) : Poly() { swap(*this, other); }

    Poly& operator=(Poly other) {
        swap(*this, other);
        return *this;
    }

    ~Poly() {
        Node* cur = head_;
        while (cur) {
            Node* next = cur->next;
            delete cur;
            cur = next;
        }
    }

    friend void swap(Poly& lhs, Poly& rhs) noexcept {
        using std::swap;
        swap(lhs.head_, rhs.head_);
    }

    double Eval(double x) const {
        double v = 0.0;
        for (Node* cur = head_; cur; cur = cur->next) {
            v += cur->v * std::pow(x, cur->exp);
        }
        return v;
    }

    friend Poly operator+(const Poly& lhs, T v) {
        if (!v) return lhs;
        Poly ret(lhs);
        ret.AddSorted(Node(v, 0));
        ret.RemoveZeros();
        return ret;
    }

    friend Poly operator+(T v, const Poly& lhs) {
        if (!v) return lhs;
        return lhs + v;
    }

    friend Poly operator+(const Poly& lhs, const Poly& rhs) {
        Poly ret(lhs);

        for (Node* cur = rhs.head_; cur; cur = cur->next) {
            ret.AddSorted(*cur);
        }

        ret.RemoveZeros();
        return ret;
    }

    friend Poly operator*(const Poly& lhs, const Poly& rhs) {
        Poly ret;

        for (Node* l = lhs.head_; l; l = l->next) {
            for (Node* r = rhs.head_; r; r = r->next) {
                ret.AddSorted(Node(l->v * r->v, l->exp + r->exp));
            }
        }

        ret.RemoveZeros();
        return ret;
    }

    friend Poly operator*(const Poly& lhs, T v) {
        Poly ret;
        if (!v) return ret;

        for (Node* l = lhs.head_; l; l = l->next) {
            ret.AddSorted(Node(l->v * v, l->exp));
        }

        ret.RemoveZeros();
        return ret;
    }

    friend Poly operator*(T v, const Poly& lhs) { return lhs * v; }

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const Poly<U>& p);

   private:
    // Add node and keep sorted order
    void AddSorted(const Node& node) {
        // skip nodes w/ zeor coefficients
        if (!node.v) return;

        Node* before = nullptr;
        Node* after = nullptr;

        for (before = head_; before; after = before, before = before->next) {
            if (node.exp < before->exp) break;

            if (node.exp == before->exp) {
                before->v += node.v;
                return;
            }
        }

        if (after) {
            after->next = new Node(node.v, node.exp, nullptr);
        } else {
            head_ = new Node(node.v, node.exp, before);
        }
    }

    void RemoveZeros() {
        Node* cur = head_;
        Node* prev = nullptr;
        while (cur) {
            Node* next = cur->next;
            if (!cur->v) {
                delete cur;
                if (prev) {
                    prev->next = next;
                } else {
                    head_ = next;
                }
            }

            prev = cur;
            cur = next;
        }
    }

    void Reset() {
        Node* cur = head_;
        while (cur) {
            Node* next = cur->next;
            delete cur;
            cur = next;
        }
        head_ = nullptr;
    }

   private:
    Node* head_;
};

template <typename U>
std::ostream& operator<<(std::ostream& os, const Poly<U>& p) {
    if (!p.head_) {
        os << 0;
        return os;
    }

    os << std::showpos;
    for (auto cur = p.head_; cur; cur = cur->next) {
        os << cur->v;

        if (cur->exp > 0) {
            os << 'x';
            if (cur->exp != 1) {
                os << '^' << std::noshowpos << cur->exp << std::showpos;
            }
        }

        if (cur->next) {
            os << ' ';
        }
    }

    os << std::noshowpos;

    return os;
}

TEST_CASE("polynomial addition") {
    Poly<int> x3(1, 3);
    Poly<int> x2(1, 2);
    Poly<int> x(1, 1);

    Poly<int> p = 0 + 5 + x + x2 + 1 + x3 + (-1);
    std::cout << p << '\n';
    auto f = [](int x) { return 0 + 5 + x + x * x + 1 + x * x * x - 1; };

    for (double v = 0.0; v < 15.0; v += 1.0) {
        REQUIRE(f(v) == p.Eval(v));
    }
}

TEST_CASE("polynomial multiply") {
    Poly<double> x3(1, 3);
    Poly<double> x2(1, 2);
    Poly<double> x(1, 1);

    Poly<double> l = 1 + (-1.0) * x + 0.5 * x2 + (-1.0 / 6.0) * x3;
    Poly<double> r = 1 + x + x2 + x3;

    Poly<double> p = l * r;
    std::cout << p << '\n';
    auto f = [](double x) {
        return 1.0 + x * x * 0.5 + x * x * x * (1.0 / 3.0) -
               x * x * x * x * (2.0 / 3.0) + x * x * x * x * x * (1.0 / 3.0) -
               x * x * x * x * x * x * (1.0 / 6.0);
    };

    for (double v = 0.0; v < 15.0; v += 1.0) {
        REQUIRE(Approx(f(v)) == p.Eval(v));
    }

    REQUIRE(Approx(0.0) == (p * 0.0).Eval(1.0));
}
