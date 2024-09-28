class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int target = image[sr][sc];
        vector<int> mvRow = {1, -1, 0, 0};
        vector<int> mvCol = {0, 0, 1, -1};
        vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size(), false));
        
        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;
        visited[sr][sc] = true;

        while(!q.empty()){
            auto temp = q.front();
            q.pop();

            for(int i = 0; i < 4; i++){
                int row = temp.first + mvRow[i], col = temp.second + mvCol[i];                         
                
                if (row < 0 || row >= image.size() || col < 0 || col >= image[0].size() || 
                    image[row][col] != target || visited[row][col]) continue;
                
                q.push({row, col});
                image[row][col] = color;  
                visited[row][col] = true;
            }
        }

        return image;
    }
};