#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <vector>
#define IOS                                                                    \
    std::ios_base::sync_with_stdio(false);                                     \
    std::cin.tie(NULL);                                                        \
    std::cout.tie(NULL);
const int N = 1e9 + 7;

class Solution {
  private:
    int n, target;
    std::vector<int> coins;
    std::vector<int> memo;

  public:
    void init() {
        std::cin >> n >> target;
        coins = std::vector<int>(n);
        memo = std::vector<int>(target + 1, -1);

        for (int i = 0; i < n; i++) {
            std::cin >> coins[i];
        }
    }

    int top_down(int sum) {
        if (sum > target) {
            return INT_MAX;
        }

        if (sum == target) {
            return 0;
        }

        if (memo[sum] != -1) {
            return memo[sum];
        }

        memo[sum] = INT_MAX;
        for (int coin : coins) {
            int temp = top_down(sum + coin);
            if (temp != INT_MAX) {
                memo[sum] = std::min(memo[sum], temp + 1);
            }
        }

        return memo[sum];
    }
};

int main() {
    IOS;

    Solution prob;
    prob.init();

    int ans = prob.top_down(0);
    std::cout << (ans != INT_MAX ? ans : -1);

    return 0;
}
