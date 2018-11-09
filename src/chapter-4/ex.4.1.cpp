// ex.4.1

// en: Suppose that we wish to count the number of pairs of points
// that fall within a square of size d. Give two different versions of
// client and implementation to solve this problem: first, modify
// distance appropriately; second, replace distance with X and Y
// member functions.

// ru: Предположим, что необходимо подсчитать количество пар точек,
// нахрдящихся внутри квадрата со стороной d. Для решения этой задачи
// напишите две разные версии клиента и реализации: (1) модифицируйте
// соответствующим образом функцию distance; (2) замените функцию-член
// distance функциями-членами X() и Y().

#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>

class Point {
   public:
    Point() : x(random()), y(random()) {}

    float X() const { return x; }
    float Y() const { return y; }

    bool in_square(const Point& other, float side) const {
        float dx = this->x - other.x;
        float dy = this->y - other.y;
        return std::fabs(dx) <= side && std::fabs(dy) <= side;
    }

   private:
    float random() { return 1.0 * std::rand() / RAND_MAX; }

    float x;
    float y;
};

int usage(const char* bin) {
    std::cout << "Usage: " << bin
              << " <positive int N> <float square side D>\n";
    return 1;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        return usage(argv[0]);
    }

    int N = std::atoi(argv[1]);
    if (N <= 0) {
        return usage(argv[0]);
    }

    std::srand(std::time(nullptr));

    float D = std::atof(argv[2]);
    Point* a = new Point[N];

    // (1)
    {
        int cnt = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                if (a[i].in_square(a[j], D)) cnt++;
            }
        }
        std::cout << cnt << " pairs inside square with side of " << D << '\n';
    }

    // (2)
    {
        int cnt = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                if (std::fabs(a[j].X() - a[i].X()) <= D &&
                    std::fabs(a[j].Y() - a[i].Y()) <= D)
                    cnt++;
            }
        }
        std::cout << cnt << " pairs inside square with side of " << D << '\n';
    }

    delete[] a;

    return 0;
}
