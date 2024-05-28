class Solution {
public:
    int firstUniqChar(string s) {
        int freq[26];
        memset(freq, 0, sizeof(int) * 26);
        
        int size = s.size();
        for(int i=0; i<size; i++){
            freq[s[i] - 97]++;    
        }

        for(int i=0; i<size; i++){
            if(freq[s[i] - 97] == 1) return i;
        }

        return -1;
    }
};