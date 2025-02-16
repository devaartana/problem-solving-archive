class Solution {
  public:
    std::vector<int> memo;

    int helper(std::string &s, int index) {
        if (index == s.size()) {
            return 1;
        }

        if (index > s.size() || s[index] == '0') {
            return 0;
        }

        if (memo[index]) {
            return memo[index];
        }

        if (index < s.size() - 1) {
            int num = (s[index] - '0') * 10 + (s[index + 1] - '0');

            if (num > 0 && num <= 26) {
                memo[index] = helper(s, index + 1) + helper(s, index + 2);
                return  memo[index];
            }
        }

        memo[index] = helper(s, index + 1);
        return memo[index];
    }

    int numDecodings(std::string s) {
        memo = std::vector<int>(s.size(), 0);

        return helper(s, 0);
    }
};
