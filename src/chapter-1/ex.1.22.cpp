// ex.1.22

// en: Modify Program 1.4 to generate random pairs of integers between
// 0 and N–1 instead of reading them from standard input, and to loop
// until N–1 union operations have been performed. Run your program
// for N = 10^3, 10^4, 10^5, and 10^6 and print out the total number
// of edges generated for each value of N.

// ru: Измените программу 1.4, чтобы она генерировала случайные пары
// целых чисел в диапазоне от 0 до N-1 вместо того, чтобы считывать их
// из стандартного ввода, и выполняла цикл до тех пор, пока не будет
// выполнено N-1 операций объединение. Выполните программу для
// значений N = 10^3, 10^4, 10^5, и 10^6 и выведите общее количество
// ребер, генерируемых для каждого значения N.

#include <algorithm>
#include <iostream>
#include <vector>

int usage(const char* bin) {
    std::cout << "Usage: " << bin << " <positive int N>\n";
    return 1;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        return usage(argv[0]);
    }

    int N = std::atoi(argv[1]);
    if (N <= 0) {
        return usage(argv[0]);
    }

    std::vector<int> id(N);
    std::vector<int> sz(N, 1);
    std::iota(id.begin(), id.end(), 0);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, N - 1);

    std::cout << "N = " << N;

    int unions = 0;
    int edges = 0;
    do {
        ++edges;

        // find
        int i;
        int j;
        for (i = dist(gen); i != id[i]; i = id[i]) id[i] = id[id[i]];
        for (j = dist(gen); j != id[j]; j = id[j]) id[j] = id[id[j]];
        if (i != j) {
            // check size of tree & join with smallest
            if (sz[i] < sz[j]) {
                id[i] = j;
                sz[j] += sz[i];
            } else {
                id[j] = i;
                sz[i] += sz[j];
            }

            ++unions;
        }
    } while (unions < N - 1);

    std::cout << " edges = " << edges << '\n';

    return 0;
}
