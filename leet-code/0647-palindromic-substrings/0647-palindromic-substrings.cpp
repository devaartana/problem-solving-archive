class Solution {
  public:
    int countSubstrings(std::string s) {
        int ans = s.size();

        for (int i = 0; i < s.size(); i++) {
            int oddBegin = i - 1, oddEnd = i + 1;
            while (oddBegin >= 0 && oddEnd < s.size() &&
                   s[oddBegin] == s[oddEnd]) {
                oddBegin--;
                oddEnd++;
                ans++;
            };

            int evenBegin = i, evenEnd = i + 1;
            while (evenBegin >= 0 && evenEnd < s.size() &&
                   s[evenBegin] == s[evenEnd]) {
                evenBegin--;
                evenEnd++;
                ans++;
            };
        }

        return ans;
    }
};
