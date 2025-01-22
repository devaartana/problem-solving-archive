class Solution {
public:
    std::vector<std::vector<int>> ans;
    std::vector<int> v;
    int last;

    void helper(std::vector<int>& nums, int target, int now) {
        if (!target) {
            ans.push_back(v);
            return;
        }

        for (int i = now; i < nums.size(); ++i) {
           
            if (target - nums[i] < 0)
                return;

            if (i > now && nums[i] == nums[i - 1]) {
                continue;
            }

            v.push_back(nums[i]);
            helper(nums, target - nums[i], i + 1);
            v.pop_back();
        }
    }

    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates,
                                                  int target) {

        std::sort(candidates.begin(), candidates.end());
        helper(candidates, target, 0);
        return ans;
    }
};
