class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans = 0, max;

        vector<int> result(nums.size(), 1);

        for(int i=0; i<nums.size(); i++){

            max = 0;
            for(int j=0; j<i; j++){
                if(nums[j] < nums[i] && result[j] + 1 > max){
                    max = result[j];
                }
            }

            result[i] = max + 1;
            if(result[i] > ans) ans = result[i];
        }

        return ans;
    }
};