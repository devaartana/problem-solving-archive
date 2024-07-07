class Solution {
public:

    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size(), column = grid[0].size(), count = 0;
        vector<vector<bool>> visited(row, vector<bool>(column, false));
        vector<pair<int, int>> mv = {{0,1}, {0,-1}, {1, 0}, {-1, 0}};
        for(int i=0; i<row; i++){

            for(int j = 0; j < column; j++){

                if(grid[i][j] == '1' && !visited[i][j]){
                    count++;
                    
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    visited[i][j] = true;
                    
                    while(!q.empty()){
                        pair<int, int> temp = q.front();
                        q.pop();

                        for(auto [mvRow, mvCol]:mv){
                            int newRow = temp.first + mvRow, newCol = temp.second + mvCol;

                            if(newRow >=0 && newRow < row && newCol >= 0 && newCol < column &&
                               !visited[newRow][newCol] && grid[newRow][newCol] == '1'){
                                
                                q.push({newRow, newCol});
                                visited[newRow][newCol] = true;
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};