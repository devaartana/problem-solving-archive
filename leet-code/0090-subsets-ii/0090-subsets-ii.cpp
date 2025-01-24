class Solution {
public:
    std::vector<std::vector<int>> ans;
    std::vector<int> v;

    void helper(std::vector<int>& nums, int level) {
        ans.push_back(v);
        for (int i = level; i < nums.size(); i++) {
            if(i > level && nums[i] == nums[i - 1]) {
                continue;
            }

            v.push_back(nums[i]);
            helper(nums, i + 1);
            v.pop_back();
        }
    }

    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<int> v;
        helper(nums, 0);
        return ans;
    }
};
