class Solution {
public:
    int fib(int n) {
        if(!n) return 0;
        
        vector<int> ans = {0, 1, 0};
        for(int i=2; i<=n; i++){
            ans[2] = ans[1];
            ans[1] = ans[0] + ans[1];
            ans[0] = ans[2];
        }   

        return ans[1];
    }
};