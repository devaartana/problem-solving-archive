
class Solution {
public:
    vector<vector<bool>> visited;

    void init(int row, int col){
        visited = vector<vector<bool>>(row, vector<bool>(col, false));
    }

    int bfs(vector<vector<int>> const& grid, int x, int y){
        vector<int> mvRow = {0, 0, 1, -1}, 
                    mvCol = {1, -1, 0, 0};
        int count = 1;

        queue<pair<int, int>> q;
        q.push({x, y});
        visited[x][y] = true;

        while(!q.empty()){
            auto temp = q.front();
            q.pop();

            for(int i=0; i<4; i++){
                int newRow = temp.first + mvRow[i],
                    newCol = temp.second + mvCol[i];
                
                if(newRow < 0 || newRow >= grid.size() || newCol < 0 || newCol >= grid[0].size() || visited[newRow][newCol] || !grid[newRow][newCol])
                    continue;

                q.push({newRow, newCol});
                visited[newRow][newCol] = true;
                count++;
            }
        }
        return count;
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int count = 0, row = grid.size(), col = grid[0].size();
    
        init(row, col);
        for(int i=0; i < row; i++){

            for(int j=0; j < col; j++){

                if(grid[i][j]) count++;
                
                if((i == 0 || i == row - 1|| j == 0 || j == col - 1) && !visited[i][j] && grid[i][j]){
                    count -= bfs(grid, i, j);
                }
            }
        }

        return abs(count);
    }
};