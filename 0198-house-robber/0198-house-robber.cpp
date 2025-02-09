class Solution {
  public:
    std::vector<int> memo;

    int helper(std::vector<int> &nums, int i) {
        if (nums.size() <= i) {
            return 0;
        }

        if (memo[i] == -1) {
            memo[i] = std::max(nums[i] + helper(nums, i + 2), helper(nums, i + 1));
        }

        return memo[i];
    }

    int rob(std::vector<int> &nums) {
        memo = std::vector<int>(nums.size(), -1);

        return helper(nums, 0);
    }
};
