class Solution {
public:
    vector<int> freq;

    void helper(string &s) {
        freq = vector<int>(26, 0);
        for(int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
        }
    }

    bool checkPermutation(string &s1, string &s2, int start) {
        vector<int> temp(freq);
        
        for(int i = start; i  < start + s1.size(); i++) {
            if(!temp[s2[i] - 'a']) {
                return false;
            }

            temp[s2[i] - 'a']--;
        }

        return true;
    }

    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        
        helper(s1);
        for(int i = 0; i < s2.size() - s1.size() + 1; i++) {
            if (checkPermutation(s1, s2, i)) return true;
        }

        return false;
    }
};