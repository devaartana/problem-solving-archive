class Solution {
public:
    char findTheDifference(string s, string t) {
        int freq[26], i;
        for(i=0; i<s.length(); i++){
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }
        freq[t[i] - 'a']--;

        for(i=0; i<26; i++){
            if(freq[i]) break;
        }

        return (char)(i+97);
    }
};