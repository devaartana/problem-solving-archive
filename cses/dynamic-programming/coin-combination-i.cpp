#include <climits>
#include <iostream>
#include <vector>
#define IOS                                                                    \
    std::ios_base::sync_with_stdio(false);                                     \
    std::cin.tie(NULL);                                                        \
    std::cout.tie(NULL);
const int N = 1e9 + 7;
typedef long long ll;

class Solution {
  private:
    int n, target;
    std::vector<int> coins;
    std::vector<ll> memo;

  public:
    void init() {
        std::cin >> n >> target;
        coins = std::vector<int>(n);
        memo = std::vector<ll>(target + 1, -1);

        for (int i = 0; i < n; i++) {
            std::cin >> coins[i];
        }
    }

    ll top_down(int sum) {
        if (sum > target) {
            return 0;
        }

        if (sum == target) {
            return 1;
        }

        if (memo[sum] != -1) {
            return memo[sum];
        }

        memo[sum] = 0;
        for (int coin : coins) {
            memo[sum] += top_down(sum + coin) % N;
        }

        return memo[sum] % N;
    }
};

int main() {
    IOS;

    Solution prob;
    prob.init();

    ll ans = prob.top_down(0);
    std::cout << ans;

    return 0;
}
