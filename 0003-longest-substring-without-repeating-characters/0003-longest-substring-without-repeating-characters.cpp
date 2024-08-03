class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;

        int first_idx = 0, max_substring = 0;
        for(int i=0; i<s.length(); i++){
            if(mp[s[i]] > first_idx){
                max_substring = max(max_substring, i - first_idx);
                first_idx = mp[s[i]];
            }

           mp[s[i]] = i + 1;
        }

        return max(max_substring, (int)(s.length()) - first_idx);      
    }
};