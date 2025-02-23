class Solution {
  public:
    std::unordered_map<int, int> memo;

    int helper(std::vector<int> &coins, int amount) {
        if (!amount) {
            return 0;
        }

        if (memo.find(amount) != memo.end()) {
            return memo[amount];
        }

        memo[amount] = INT_MAX;
        for (int i = 0; i < coins.size(); i++) {
            if (coins[i] > amount) {
                continue;
            }

            int temp = helper(coins, amount - coins[i]);
            if (temp != INT_MAX) {
                memo[amount] = std::min(memo[amount], temp + 1);
            }
        }

        return memo[amount];
    }

    int coinChange(std::vector<int> &coins, int amount) {
        int ans = helper(coins, amount);
        return ans == INT_MAX ? -1 : ans;
    }
};
