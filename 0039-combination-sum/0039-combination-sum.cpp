class Solution {
public:
    std::vector<std::vector<int>> ans;
    std::vector<int> v;

    void helper(std::vector<int>& nums, int target, int end, int sum, int now) {
        if (sum == target) {
            ans.push_back(v);
            return;
        }

        for (int i = now; i < nums.size(); ++i) {
            if (sum + nums[i] > target)
                return;

            v.push_back(nums[i]);
            helper(nums, target, end + 1, sum + nums[i], i);
            v.pop_back();
        }
    }

    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates,
                                                 int target) {
        std::sort(candidates.begin(), candidates.end());
        helper(candidates, target, 0, 0, 0);

        return ans;
    }
};
