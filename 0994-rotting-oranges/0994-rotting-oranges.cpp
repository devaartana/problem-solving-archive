class Solution {
public:
    int orangesRotting(std::vector<std::vector<int>>& grid) {
        int ans = 0, fresh = 0, n = grid.size(), m = grid[0].size();

        std::vector<std::pair<int, int>> nextDirection = {
            {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        std::queue<std::pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        while (fresh > 0 && !q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto temp = q.front();
                q.pop();

                for (auto [nextRow, nextCol] : nextDirection) {
                    int row = temp.first + nextRow, col = temp.second + nextCol;

                    if (row < 0 || row >= n || col < 0 || col >= m ||
                        grid[row][col] != 1) {
                        continue;
                    }

                    grid[row][col] = 2;
                    q.push({row, col});
                    fresh--;
                }
            }
            ans++;
        }

        return fresh ? -1 : ans;
    }
};
