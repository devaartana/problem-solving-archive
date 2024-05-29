class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int letter[26] = {0};

        for(int i=0; i<ransomNote.size(); i++){
            letter[ransomNote[i] - 'a']++;
        }

        for(int i=0; i<magazine.size(); i++){
            letter[magazine[i] - 'a']--;
        }

        for(int i=0; i<26; i++){
            if(letter[i] > 0) return false;
        }

        return true;
    }
};