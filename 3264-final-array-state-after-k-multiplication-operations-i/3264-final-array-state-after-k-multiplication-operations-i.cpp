class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int first;
        for(int i = 0; i < k; i++){

            first = 0;
            for(int j = 0; j < nums.size(); j++){
                if(nums[first] > nums[j]) first = j;
            }

            nums[first] *= multiplier;
        }

        return nums;
    }
};