class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=1, temp = nums[0];

        for(int j = 0; j < nums.size(); j++){
            if(nums[j] != temp){
                temp = nums[i] = nums[j];
                i++;
            }
        }

        return i;
    }
};