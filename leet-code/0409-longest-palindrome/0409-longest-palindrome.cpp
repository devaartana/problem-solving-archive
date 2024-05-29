class Solution {
public:
    int longestPalindrome(string s) {
        int letter[59] = {0}, size = s.size(), length = 0;

        for(int i=0; i<size; i++){
            letter[s[i] - 'A']++;
        }

        int odd = 0;
        for(int i=0; i<59; i++) {
            if(!(letter[i]&1)) length += letter[i];
            else {
                odd = 1;
                length += letter[i] - 1;
            }
        }

        return length + odd;
    }
};