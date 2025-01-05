#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(), nums.end());  // Minimum possible largest sum
        int right = accumulate(nums.begin(), nums.end(), 0); // Maximum possible largest sum
        
        // Binary search on the answer range
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canSplit(nums, k, mid)) {
                right = mid; // Try to find a smaller largest sum
            } else {
                left = mid + 1; // Increase the range
            }
        }
        
        return left;
    }
    
private:
    bool canSplit(const vector<int>& nums, int k, int maxSum) {
        int current_sum = 0;
        int splits = 1; // Start with one subarray
        for (int num : nums) {
            if (current_sum + num > maxSum) {
                // Need to start a new subarray
                splits++;
                current_sum = num;
                if (splits > k) {
                    return false; // More splits than allowed
                }
            } else {
                current_sum += num;
            }
        }
        return true; // Possible to split within maxSum
    }
};
