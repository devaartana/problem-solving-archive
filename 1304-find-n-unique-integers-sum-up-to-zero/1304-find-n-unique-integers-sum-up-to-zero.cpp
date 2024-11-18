class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans(n);
        int k = 0;
        for(int i = n/2; i > 0; i--, k++) {
            ans[k] = 0 - i;
        }

        for(int i = n&1 ? 0 : 1; i <= n/2; i++, k++) {
            ans[k] = i;
        }

        return ans;
    }
};