class Solution {
public:
    void buildRowKeyboard(vector<vector<bool>> &rowKeyboard){
        vector<string> row = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < row[i].length(); j++){
                rowKeyboard[i][row[i][j] - 'a'] = true;
            }
        }
    }

    bool helper(vector<bool> const &rowKeyboard, string const& str){      
        for(int i = 0; i < str.length(); i++){
            if(!rowKeyboard[tolower(str[i]) - 'a']) return false;
        }

        return true;
    }

    vector<string> findWords(vector<string>& words) {
        vector<vector<bool>> rowKeyboard(3, vector<bool>(26, false));
        buildRowKeyboard(rowKeyboard);

        vector<string> ans;
        for(string &str: words){
            for(int i = 0; i < 3; i++){
                if(helper(rowKeyboard[i], str)) {
                    ans.push_back(str);
                    break;
                }
            }
        }

        return ans;
    }
};
