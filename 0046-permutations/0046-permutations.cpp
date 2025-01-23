class Solution {
public:
    std::vector<std::vector<int>> ans;
    std::vector<int> v;
    std::vector<bool> included;

    void helper(std::vector<int>& nums) {
        if (v.size() == nums.size()) {
            ans.push_back(v);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (included[i]) {
                continue;
            }
            v.push_back(nums[i]);
            included[i] = true;
            helper(nums);
            v.pop_back();
            included[i] = false;
        }
    }

    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        included = std::vector<bool>(nums.size(), false);
        helper(nums);
        return ans;
    }
};
