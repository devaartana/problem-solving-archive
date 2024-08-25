class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size(), hi = size - 1;

        while(hi >= 0 && nums[hi] == val) hi--;
        for(int lo = 0; lo < hi; lo++) {
            if(nums[lo] == val) swap(nums[lo], nums[hi--]);
            while(hi >= 0 && nums[hi] == val) hi--;
        }
        return hi + 1;
    }
};