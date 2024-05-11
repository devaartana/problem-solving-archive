class Solution {
public:
    bool isAnagram(string s, string t) {

        int sizeS = s.size(), sizeT = t.size();
        if(sizeS != sizeT){
            return false;
        }

        int freq[256];
        memset(freq, 0, sizeof(int) * 256);

        for(int i=0; i<sizeS; i++){
            freq[s[i]]++;
            freq[t[i]]--;
        } 

        for(int i=0; i < 256; i++){
           if(freq[i]) return false;
        }
        return true;
    }
};