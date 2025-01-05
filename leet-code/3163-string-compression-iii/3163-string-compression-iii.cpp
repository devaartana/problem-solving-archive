class Solution {
public:
    string compressedString(string word) {
        string ans;
        for(int i = 0, op = 1; i < word.length(); i++, op++) {
            if(op == 9 || word[i] != word[i+1]) {
                ans += to_string(op);
                ans += word[i];
                op = 0;
            }
        }

        return ans;
    }
};