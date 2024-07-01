
#define coordinate pair<int, int>

class Solution {
public:
    bool isTrue(vector<vector<bool>> const& visited, vector<vector<char>> const& maze ,int r, int c){
        return r >= 0 && r < maze.size() && c >= 0 && c < maze[0].size() && !visited[r][c] && maze[r][c] == '.'; 
    }

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
        vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(), false));
        vector<pair<int, int>> mv = {{1, 0}, {-1, 0}, {0, 1}, {0, -1} };
        queue<pair<coordinate, int>> q;
        q.push({{entrance[0], entrance[1]}, 0});

        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            
            int row = temp.first.first, col = temp.first.second;

            for(int i=0; i<4; i++){
                int newRow = row + mv[i].first, newCol = col + mv[i].second;
                
                if((newRow == 0 || newRow == maze.size() - 1 || newCol == 0 || newCol == maze[0].size() - 1) && !(newRow == entrance[0] && newCol == entrance[1]) && newRow < maze.size() && newCol < maze[0].size() &&  maze[newRow][newCol] == '.'){
                    return temp.second + 1;
                }

                if(isTrue(visited, maze, newRow, newCol)){
                    cout << newRow << " " << newCol << " " << temp.second << endl;
                    q.push({{newRow, newCol}, temp.second + 1});
                    visited[newRow][newCol] = true;
                }
            }
        }

        return -1;
    }
};