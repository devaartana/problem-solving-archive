#include <algorithm>
#include <iostream>
#include <vector>
#define IOS                                                                    \
    std::ios_base::sync_with_stdio(false);                                     \
    std::cin.tie(NULL);                                                        \
    std::cout.tie(NULL);
const int N = 1e9 + 7;

class Solution {
  private:
    std::vector<int> prices, pages;
    std::vector<std::vector<int>> memo;

  public:
    int n, x;

    void init() {
        std::cin >> n >> x;
        pages = prices = std::vector<int>(n);
        memo = std::vector<std::vector<int>>(n, std::vector<int>(x + 1, -1));

        for (int i = 0; i < n; i++) {
            std::cin >> prices[i];
        }

        for (int i = 0; i < n; i++) {
            std::cin >> pages[i];
        }
    }

    int top_down(int index, int price) {
        if (index == n) {
            return 0;
        }

        if (memo[index][price] != -1) {
            return memo[index][price];
        }

        memo[index][price] = top_down(index + 1, price);
        if (price >= prices[index]) {
            memo[index][price] = std::max(memo[index][price], pages[index] + top_down(index + 1, price - prices[index]));
        }

        return memo[index][price];
    }

    int bottom_up() {
        std::vector<int> tab(x + 1, 0);

        for (int i = 0; i < n; i++) {
            for (int j = x; j >= prices[i]; j--) {
                tab[j] = std::max(tab[j], tab[j - prices[i]] + pages[i]);
            }
        }

        return tab[x];
    }
};

int main() {
    IOS;

    Solution prob;
    prob.init();
    std::cout << prob.bottom_up();

    return 0;
}
