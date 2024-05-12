class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int row = grid.size(), column = grid[0].size();

        vector<vector<int>> newVec(row-2, vector<int>(column-2, 0));
        for(int i=0; i+3 <= row; i++){

            for(int j=0; j+3 <= column; j++){
                
                for(int x = i; x < i + 3; x++){
                    for(int y = j; y < j + 3; y++){
                        if(grid[x][y] > newVec[i][j]) newVec[i][j] = grid[x][y];
                    }
                }
            }

            cout << endl;
        }

       return newVec;

    }
};