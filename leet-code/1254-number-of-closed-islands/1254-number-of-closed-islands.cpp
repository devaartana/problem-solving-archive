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
                    deque<pair<int, int>> q;
                    q.push_back({i, j});
                    grid[i][j] = 1;

                    while(!q.empty()){
                        auto [r, c] = q.front();
                        q.pop_front();

                        if(!r || !c || r == n - 1 || c == m - 1) 
                            status = false;

                        for(auto [mvRow, mvCol]:mv){
                            int row = r + mvRow, col = c + mvCol;

                            if(row < 0 || col < 0 || row >= n || col >= m || grid[row][col]) continue;

                            q.push_back({row, col});
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