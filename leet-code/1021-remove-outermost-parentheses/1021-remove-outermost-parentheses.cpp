class Solution {
public:
    string removeOuterParentheses(string s) {
        
        int track = 0;
        string ans;
        for(char c:s){
            if(c == '(') {
                track++;
                if(track > 1) ans.push_back(c);
            }else { 
                if(track > 1) ans.push_back(c);
                track--;
            }
        }

        return ans;
    }
};