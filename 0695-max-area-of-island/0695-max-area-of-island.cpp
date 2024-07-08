class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size(), column = grid[0].size(), max = 0;
        vector<vector<bool>> visited(row, vector<bool>(column, false));
        vector<pair<int, int>> mv = {{0,1}, {0,-1}, {1, 0}, {-1, 0}};
        
        for(int i=0; i<row; i++){

            for(int j = 0; j < column; j++){

                if(grid[i][j] && !visited[i][j]){
                    int count = 1;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    visited[i][j] = true;
                    
                    while(!q.empty()){
                        pair<int, int> temp = q.front();
                        q.pop();

                        for(auto [mvRow, mvCol]:mv){
                            int newRow = temp.first + mvRow, newCol = temp.second + mvCol;

                            if(newRow >=0 && newRow < row && newCol >= 0 && newCol < column &&
                               !visited[newRow][newCol] && grid[newRow][newCol]){
                                count++;
                                q.push({newRow, newCol});
                                visited[newRow][newCol] = true;
                            }
                        }
                    }

                    if(count > max) max = count;
                }
            }
        }
        return max;
    }
};