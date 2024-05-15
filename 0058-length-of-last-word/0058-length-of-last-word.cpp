class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = s.length() - 1, word = 0;

        while(length >= 0 && s[length] == ' ') {length--;}

        while(length >= 0 && s[length] != ' ') {word++; length--;}

        return word;
    }
};