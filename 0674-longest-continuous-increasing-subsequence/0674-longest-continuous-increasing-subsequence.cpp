class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        
        int maxIncreasing = 0, current = 1, size = nums.size();

        for(int i=0; i<size-1; i++){
            if(nums[i] < nums[i+1]){
                current++;
            }else {
                if(current > maxIncreasing) maxIncreasing = current;
                current = 1;
            }
        }

        if(current > maxIncreasing) maxIncreasing = current;

        return maxIncreasing;
    }
};