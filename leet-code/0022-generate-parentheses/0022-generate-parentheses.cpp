class Solution {
public:
    vector<string> ans;

    void helper(int n, string parentheses, int open, int close) {
        if (open + close > n * 2 || close > open || open > n)
            return;

        if (close == open && close + open == n * 2)
            ans.push_back(parentheses);

        helper(n, parentheses + "(", open + 1, close);
        helper(n, parentheses + ")", open, close + 1);
    }

    vector<string> generateParenthesis(int n) {
        helper(n, "(", 1, 0);
        return ans;
    }
};
