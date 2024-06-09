class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int> result(rowIndex + 1);
        result[0] = result[rowIndex]=  1;

        for(int i=1; i<rowIndex; i++){
             
            result[i] = (long long)result[i-1] * (rowIndex - i + 1) / i; 
        }

        return result;
    }
};