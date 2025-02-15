class Solution {
  public:
    std::string longestPalindrome(std::string s) {
        int ansBegin = 0, ansEnd = 0;

        for (int i = 0; i < s.size(); i++) {
            int oddBegin = i - 1, oddEnd = i + 1;
            while (oddBegin >= 0 && oddEnd < s.size() &&
                   s[oddBegin] == s[oddEnd]) {
                oddBegin--;
                oddEnd++;
            };

            if (oddEnd - oddBegin - 2 > ansEnd - ansBegin) {
                ansBegin = oddBegin + 1;
                ansEnd = oddEnd - 1;
            }

            int evenBegin = i, evenEnd = i + 1;
            while (evenBegin >= 0 && evenEnd < s.size() &&
                   s[evenBegin] == s[evenEnd]) {
                evenBegin--;
                evenEnd++;
            };

            if (evenEnd - evenBegin - 2> ansEnd - ansBegin) {
                ansBegin = evenBegin + 1;
                ansEnd = evenEnd - 1;
            }
        }

        return s.substr(ansBegin, ansEnd - ansBegin + 1);
    }
};
