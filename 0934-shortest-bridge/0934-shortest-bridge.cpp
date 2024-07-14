class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int size = grid.size();
        vector<vector<bool>> visited(size, vector<bool>(size, false));
        vector<pair<int, int>> mv = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        bool firstIsland = false;
        queue<pair<pair<int, int>, int>> q1;
        for(int i=0; i<size; i++){
            if(!firstIsland){
                for(int j=0; j<size; j++){
                    if(grid[i][j]){
                        q1.push({{i, j}, 0});

                        queue<pair<int, int>> q;
                        q.push({i, j});
                        visited[i][j] = true;

                        while(!q.empty()){
                            auto temp = q.front();
                            q.pop();

                            for(auto [mvRow, mvCol]:mv){
                                int newRow = temp.first + mvRow, newCol = temp.second + mvCol;

                                if(newRow < 0 || newRow >= size || newCol < 0 || newCol >= size || !grid[newRow][newCol] || visited[newRow][newCol]) continue;

                                q.push({newRow, newCol});
                                q1.push({{newRow, newCol}, 0});
                                visited[newRow][newCol] = true;
                            }
                        }

                        firstIsland = true;
                        break;
                    }
                }
            }
        }

        // while(!q1.empty()){
        //     auto temp = q1.front();
        //     q1.pop();
        //     cout << temp.first.first << " " << temp.first.second << endl;
        // }
        while(!q1.empty()){
            auto temp = q1.front();
            q1.pop();

            for(auto [mvRow, mvCol]:mv){
                int newRow = temp.first.first + mvRow, newCol = temp.first.second + mvCol;
                
                if(newRow < 0 || newRow >= size || newCol < 0 || newCol >= size || visited[newRow][newCol]) continue;

                if(grid[newRow][newCol]) return temp.second;

                q1.push({{newRow, newCol}, temp.second + 1});
                visited[newRow][newCol] = true;
            }
        }

        return 0;
    }
};