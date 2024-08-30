class Solution {
public:
    bool detectCapitalUse(string word) {
        int capital = -1, count = 0;

        for(int i = 0; i < word.length(); i++){
            if(word[i] <= 'Z' && word[i] >= 'A') {
                count++;
                capital = i;
            }
        }

        if(capital == -1 || capital == 0 && count == 1 || count == word.length()) return true;
        return false; 
    }
};