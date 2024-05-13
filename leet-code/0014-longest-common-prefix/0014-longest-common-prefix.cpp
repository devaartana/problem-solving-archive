class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int row = strs.size(), j = 0;

        char parameter;
        string commonPrefix;
        while(1){

            parameter = strs[0][j];
            for(int i=1; i<row; i++){
                
                if(strs[i][j] == '\0' || strs[i][j] != parameter) {
                    
                    commonPrefix = strs[0].substr(0, j);

                    return commonPrefix;                    
                }

            }

            j++;
        }

        commonPrefix = strs[0].substr(0, j);
        return commonPrefix;
    }
};