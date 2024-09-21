class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        
        int currLength = 0, lineCount = 1;
        for(int i = 0; i < s.length(); i++){          
            if(currLength + widths[s[i] - 'a'] > 100) {
                lineCount++;
                currLength = 0;
            }
            currLength += widths[s[i] - 'a'];
        }

        return {lineCount, currLength};
    }
};