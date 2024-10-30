class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size() == 0) {
            return {};
        }

        if(nums.size() == 1) {
            return {to_string(nums[0])};
        }

        vector<string> ans;
        int start = 0;
        for(int i = 1; i < nums.size(); i++){
            if((long)(nums[i]) - nums[i-1] != 1) {
                if(i - 1 == start) {
                    ans.push_back(to_string(nums[start]));
                } else {
                    ans.push_back(to_string(nums[start]) + "->" + to_string(nums[i-1]));
                }
                start = i;
            }
        } 

        if((long)nums[nums.size() - 1] - nums[nums.size() - 2] != 1) {
            ans.push_back(to_string(nums[nums.size() - 1]));
        } else {
            ans.push_back(to_string(nums[start]) + "->" + to_string(nums[nums.size() - 1]));
        }
        return ans;
    }
};