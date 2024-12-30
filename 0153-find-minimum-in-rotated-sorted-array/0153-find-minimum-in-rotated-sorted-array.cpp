class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            if (
                mid + 1 < nums.size() && mid - 1 >= 0 &&
                nums[mid - 1] > nums[mid] &&
                nums[mid + 1] > nums[mid] 
            )  return nums[mid];
            else if(nums[mid] > nums[hi]) {
                lo = mid + 1;
            } else if(nums[mid] < nums[hi]) {
                hi = mid - 1;
            } 
        }

        return nums[lo];
    }
};