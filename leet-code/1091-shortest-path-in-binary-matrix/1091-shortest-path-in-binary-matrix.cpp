typedef struct{
    int x, y, distance;
}position;

class Solution {
public:

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        vector<int> nextRow = {0, 1, 1, 1, 0, -1, -1, -1}, 
                    nextCol = {1, 1, 0, -1, -1, -1, 0, 1}; 
        
        queue<position> q;
        if(!grid[0][0]) {
            if(n == 1) return 1;
            
            q.push({0,0,1});
            visited[0][0] = true;
        }

        while(!q.empty()){
            position temp = q.front();
            q.pop();

            for(int i=0; i<8; i++){
                int newRow = temp.x + nextRow[i], newCol = temp.y + nextCol[i];

                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < n 
                && !grid[newRow][newCol]
                && !visited[newRow][newCol]){
                    
                    if(newRow == n - 1 && newCol == n - 1) return temp.distance + 1;
                    
                    q.push({newRow, newCol, temp.distance + 1});
                    visited[newRow][newCol] = true;
                }                
            }
        } 

        return -1;
    }
};