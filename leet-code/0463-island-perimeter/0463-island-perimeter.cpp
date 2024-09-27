class Solution {
public:



    int islandPerimeter(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j]){
                    int ans = 0; 
                    vector<int> mvRow = {1, -1, 0, 0};
                    vector<int> mvCol = {0, 0, 1, -1};
                    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    visited[i][j] = true;


                    while(!q.empty()){
                        auto temp = q.front();
                        q.pop();

                        for(int i = 0; i < 4; i++){
                            int row = temp.first + mvRow[i], col = temp.second + mvCol[i];                         
                            
                             if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) {
                                ans++;  
                            } else if (!grid[row][col]) {
                                ans++; 
                            } else if (!visited[row][col]) {
                                q.push({row, col});
                                visited[row][col] = true;
                            }
                        }
                    }

                    return ans;
                }
            }
        }

        return 0;
    }
};