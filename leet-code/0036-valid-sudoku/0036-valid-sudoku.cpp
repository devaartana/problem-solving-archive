class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> 
            column(9, vector<bool>(9, false)), row(9, vector<bool>(9, false)), subgrid(9, vector<bool>(9, false));

        for(int i = 0; i < 9; i++) {

            for(int j = 0; j < 9; j++) {

                if (board[i][j] == '.') continue;

                int subgridIndex = (i/3) * 3 + (j/3);
                int boardIndex = board[i][j] - '0' - 1;
                
                if(column[j][boardIndex] || row[i][boardIndex] || subgrid[subgridIndex][boardIndex]) {
                    return false;
                } 
                
                column[j][boardIndex] = row[i][boardIndex] = subgrid[subgridIndex][boardIndex] = true;
            }
        }

        return true;
    }
};