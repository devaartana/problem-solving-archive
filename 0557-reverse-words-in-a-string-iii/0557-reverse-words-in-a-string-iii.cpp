class Solution {
public:

    void helper(int lo, int hi, string &s){
        while(lo < hi){
            swap(s[lo++], s[hi--]);
        }
    }
    
    string reverseWords(string s) {
        int j = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ' ') {
                helper(j, i - 1, s);
                j = i + 1;
            }
        }

        helper(j, s.length() - 1, s);

        return s;
    }
};