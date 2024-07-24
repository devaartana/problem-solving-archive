class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), count = 0;

        bool status;
        vector<pair<int, int>> mv = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for(int i=0; i<n; i++){
            for(int j = 0; j < m; j++){
                if(!grid[i][j]){
                    
                    status =  true;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    grid[i][j] = 1;

                    while(!q.empty()){
                        auto temp = q.front();
                        q.pop();

                        if(!temp.first || !temp.second || temp.first == n - 1 || temp.second == m - 1) 
                            status = false;

                        for(auto [mvRow, mvCol]:mv){
                            int row = temp.first + mvRow, col = temp.second + mvCol;

                            if(row < 0 || col < 0 || row >= n || col >= m || grid[row][col]) continue;

                            q.push({row, col});
                            grid[row][col] = 1;
                        }
                    }
                    if(status) count++;
                }
            }
        }

        return count;
    }
};