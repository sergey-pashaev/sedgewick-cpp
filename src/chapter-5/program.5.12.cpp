// program 5.12

// en: Knapsack problem (recursive implementation)

// ru: Задача о ранце (рекурсивная реализация)

#include <cstdlib>
#include <iostream>
#include <vector>

struct Item {
    int size = 0;
    int val = 0;
};

int usage(const char* bin) {
    std::cout
        << "Usage: " << bin
        << " <positive int C - capacity> <positive int N - number of items>\n";
    return 1;
}

int knap(int cap, const std::vector<Item>& items) {
    int i, space, max, t;
    const int n = items.size();
    for (i = 0, max = 0; i < n; ++i)
        if ((space = cap - items[i].size) >= 0)
            if ((t = knap(space, items) + items[i].val) > max) max = t;
    return max;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        return usage(argv[0]);
    }

    int cap = std::atoi(argv[1]);
    if (cap <= 0) {
        return usage(argv[0]);
    }

    int n = std::atoi(argv[2]);
    if (n <= 0) {
        return usage(argv[0]);
    }

    // read items
    std::vector<Item> items;
    while (n--) {
        Item item;
        std::cin >> item.size;
        std::cin >> item.val;
        items.push_back(item);
    }

    std::cout << knap(cap, items) << '\n';

    return 0;
}
