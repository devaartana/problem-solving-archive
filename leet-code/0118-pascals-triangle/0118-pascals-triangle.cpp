class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> result;
        
        result.push_back({1});

        if(numRows == 1) return result;
        
        result.push_back({1,1});
        for(int i=3 ; i<=numRows; i++){
            vector<int> temp(i);
            
            for(int j=1; j<i-1; j++){
                temp[j] = result[i-2][j] + result[i-2][j-1];
            }
            temp[0] = temp[i-1] = 1;

            result.push_back(temp);
        }

        return result;
    }
};