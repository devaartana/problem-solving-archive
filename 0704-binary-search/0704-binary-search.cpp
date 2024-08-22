class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1, mid;

        while(lo < hi){
            mid = (hi - lo)/2 + lo;

            if(nums[mid] < target) lo = mid + 1;
            else if(nums[mid] > target) hi = mid - 1;
            else return mid;
        }

        return (nums[lo] == target) ? lo : -1;
    }
};