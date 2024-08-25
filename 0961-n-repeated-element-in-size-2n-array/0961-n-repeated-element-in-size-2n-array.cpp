class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        vector<int> freq((int)1e4 + 1, 0);

        for(int i = 0; i < nums.size(); i++){
            freq[nums[i]]++;

            if(freq[nums[i]] == nums.size()/2) return nums[i];
        }

        return -1;
    }
};