class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> correctOrder = heights;
        sort(correctOrder.begin(), correctOrder.end());

        int ans = 0;
        for(int i = 0; i < heights.size(); i++){
            if(heights[i] != correctOrder[i]) ans++;
        }

        return ans;
    }
};