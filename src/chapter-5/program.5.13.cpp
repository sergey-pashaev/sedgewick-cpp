// program 5.13

// en: Knapsack problem (dynamic programming)

// ru: Задача о ранце (динамическое программирование)

#include <cstdlib>
#include <iostream>
#include <vector>

constexpr int unknown = -1;

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

int knap(int cap, const std::vector<Item>& items, std::vector<int>& memo) {
    // check memo
    if (memo[cap] != unknown) return memo[cap];

    // calculate
    int i, space, max, t;
    const int n = items.size();
    for (i = 0, max = 0; i < n; ++i)
        if ((space = cap - items[i].size) >= 0)
            if ((t = knap(space, items, memo) + items[i].val) > max) max = t;

    // update memo
    memo[cap] = max;
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

    std::vector<int> memo(cap + 1, unknown);
    std::cout << knap(cap, items, memo) << '\n';

    return 0;
}
