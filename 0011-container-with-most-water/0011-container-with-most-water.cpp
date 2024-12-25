class Solution {
public:
    int maxArea(vector<int>& height) {
        int lo = 0, hi = height.size() - 1, ans = 0;

        while(lo < hi) {
            ans = max(ans, min(height[lo], height[hi]) * (hi - lo));
            if (height[lo] > height[hi]) hi--;
            else lo++;
        }

        return ans;
    }
};