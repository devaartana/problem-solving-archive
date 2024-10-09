class Solution {
public:

    bool isVowel(char c) {
        return c == 'a' || c == 'A' || c == 'i' || c == 'I' || c == 'u' || c == 'U' || c == 'e' || c == 'E' || c == 'o' || c == 'O';
    }

    string reverseVowels(string s) {
        int lo = 0, hi = s.length() - 1;
        while(lo < hi) {
            while( lo < hi && !isVowel(s[lo])) lo++;
            while( lo < hi && !isVowel(s[hi])) hi--;

            if(lo < hi) swap(s[lo], s[hi]);
            lo++; hi--;
        }

        return s;
    }
};