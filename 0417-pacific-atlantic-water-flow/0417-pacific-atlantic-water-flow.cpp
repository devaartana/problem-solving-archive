class Solution {
public:
    vector<pair<int, int>> mv = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool isNotInGrid(int x, int y, int row, int col){
        return x < 0 || y < 0 || x >= row || y >= col;
    }

    void dfs(vector<vector<int>> &heights, vector<vector<bool>> &visited, int x, int y){

        visited[x][y] = true;

        for(auto [mvRow, mvCol]:mv){
            int row = x + mvRow, col = y + mvCol;

            if(isNotInGrid(row, col, heights.size(), heights[0].size()) || 
                visited[row][col] || heights[row][col] < heights[x][y]) continue;

            dfs(heights, visited, row, col);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<bool>> pasific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));

        for(int i=0; i<n; i++){
            dfs(heights, pasific, i, 0);
            dfs(heights, atlantic, i, m-1);
        }

        for(int i=0; i<m; i++){
            dfs(heights, pasific, 0, i);
            dfs(heights, atlantic, n-1, i);
        }

        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(pasific[i][j] && atlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }

        return ans;
    }
};