class Solution {
  public:
    int rob(std::vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }

        int st = nums[0], nd = std::max(nums[0], nums[1]), temp, ans;
        for(int i = 2; i < nums.size() - 1; i++) {
            temp = std::max(nd, st + nums[i]);
            st = nd;
            nd = temp;
        }

        ans = nd;

        st = 0; nd = nums[1];
        for(int i = 2; i < nums.size(); i++) {
            temp = std::max(nd, st + nums[i]);
            st = nd;
            nd = temp;
        }

        return std::max(ans, nd);
    }
};
