class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long sn = ((1  + nums.size()) * nums.size()) / 2;
        for(int i = 0; i < nums.size(); i++){
            sn -= nums[i];
        }
        return sn;
    }
};