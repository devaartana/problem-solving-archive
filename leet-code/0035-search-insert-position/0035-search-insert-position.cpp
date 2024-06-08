class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int hi = nums.size() - 1, lo = 0, mid;

        while(lo <= hi){
            mid = (hi + lo)/2;

            if(target > nums[mid]){
                lo = mid + 1;
            } else if (target < nums[mid]){
                hi = mid - 1;
            }else{
                return mid;
            }

        }

        return lo;
        
    }
};