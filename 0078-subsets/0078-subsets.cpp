class Solution {
public:
    std::vector<std::vector<int>> ans;

    void helper(std::vector<int>& nums, int level, std::vector<int> temp) {
        if (level >= nums.size()) {
            ans.push_back(temp);
            return;
        }

        helper(nums, level + 1, temp);
        temp.push_back(nums[level]);
        helper(nums, level + 1, temp);
    }

    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        helper(nums, 0, {});
        return ans;
    }
};
