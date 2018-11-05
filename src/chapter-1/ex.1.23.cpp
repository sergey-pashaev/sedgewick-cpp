// ex.1.23

// en: Modify your program from Exercise 1.22 to plot the number of
// edges needed to connect N items, for 100 <= N <= 1000.

// ru: Измените программу из упражнения 1.22, чтобы она выводила в
// виде графика количество ребер, требующихся для соединения N
// элементов, 100 <= N <= 1000.

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

#include <psv/cli_graph.h>

int usage(const char* bin) {
    std::cout << "Usage: " << bin << " <positive int X> <positive int Y>\n";
    return 1;
}

int calc_edges(int N) {
    std::vector<int> id(N);
    std::vector<int> sz(N, 1);
    std::iota(id.begin(), id.end(), 0);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, N - 1);

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

    return edges;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        return usage(argv[0]);
    }

    int X = std::atoi(argv[1]);
    int Y = std::atoi(argv[2]);
    if (X <= 0 || Y <= 0) {
        return usage(argv[0]);
    }

    // magic upper bound
    psv::DrawCLIGraph(100, 1000, calc_edges, 0, 7000, X, Y, "N", "edges");
    return 0;
}
