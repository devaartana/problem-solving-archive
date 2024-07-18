class Solution {
public:
    int fib(int n) {
        vector<int> ans = {0, 1};

        int temp;
        for(int i=2; i<=n; i++){
            temp = ans[1];
            ans[1] = ans[0] + ans[1];
            ans[0] = temp;
        }   

        return ans[1];
    }
};