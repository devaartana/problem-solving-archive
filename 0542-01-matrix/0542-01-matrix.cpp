class Solution {
public:
    bool isNotInGrid(int row, int col, int maxRow, int maxCol){
        return row < 0 || row >= maxRow || col < 0 || col >= maxCol;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> ans(m, vector<int>(n, INT_MAX - 1));
        vector<int> mvRow = {1, -1, 0, 0}, mvCol = {0, 0, 1, -1};

        queue<pair<int,int>> border;
        for(int i=0; i < m; i++){

            for(int j=0; j < n; j++){
                
                if(!mat[i][j]) ans[i][j] = 0;

                if(!visited[i][j] && mat[i][j]){
                    
                    queue<pair<int,int>> q;
                    q.push({i, j});
                    visited[i][j] = true;

                    while(!q.empty()){
                        auto temp = q.front();
                        q.pop();

                        for(int k=0; k < 4; k++){
                            int row = temp.first + mvRow[k], col = temp.second + mvCol[k];

                            if(isNotInGrid(row, col, m, n) || visited[row][col]) continue;
                            if(!mat[row][col]){
                                if(border.empty() || temp != border.front()){
                                    border.push(temp);
                                }

                                continue;
                            }
                                
                            q.push({row, col});
                            visited[row][col] = true;
                        }
                    }
                }
            }
        }

        while(!border.empty()){
            auto temp = border.front();
            border.pop();

            for(int i=0; i<4; i++){
                int row = temp.first + mvRow[i], col = temp.second + mvCol[i];

                if(isNotInGrid(row, col, m, n)) continue;

                if(ans[temp.first][temp.second] > ans[row][col] + 1) ans[temp.first][temp.second] = ans[row][col] + 1;
            
                if(visited[row][col] && mat[row][col]){
                    border.push({row, col});
                    visited[row][col] = false;    
                }
                
            }
        }

        return ans;
    }
};