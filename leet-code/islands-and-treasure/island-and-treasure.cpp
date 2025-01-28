#include <queue>
#include <utility>
#include <vector>

class Solution {
public:
  void islandsAndTreasure(std::vector<std::vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    std::vector<std::pair<int, int>> nextDirection = {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    std::queue<std::pair<int, int>> q;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {

        if (!grid[i][j]) {
          q.push({i, j});

          while (!q.empty()) {
            auto temp = q.front();
            q.pop();

            for (auto [nextRow, nextCol] : nextDirection) {
              int row = temp.first + nextRow, col = temp.second + nextCol;

              if (row < 0 || row >= n || col < 0 || col >= m ||
                  grid[row][col] == -1) {
                continue;
              }

              if (grid[row][col] > grid[temp.first][temp.second] + 1) {
                grid[row][col] = grid[temp.first][temp.second] + 1;
                q.push({row, col});
              }
            }
          }
        }
      }
    }
  }
};
