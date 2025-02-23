class Solution {
  public:
    bool canPartition(std::vector<int> &nums) {
        int sum = 0;
        for (const int num : nums) {
            sum += num;
        }

        if (sum & 1) {
            return false;
        }

        sum/=2;
        std::unordered_set<int> ust;
        ust.insert(0);
        ust.insert(nums[0]);

        for (int i = 1; i < nums.size(); i++) {
            int size = ust.size(), j = 0;
            for (auto it = ust.begin(); j < size; it++, j++) {
                int temp = *it + nums[i];
                if (temp == sum) {
                    return true;
                }

                if (ust.find(temp) == ust.end()) {
                    ust.insert(temp);
                }
            }
        }

        return false;
    }
};
