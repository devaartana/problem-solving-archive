#include <bits/stdc++.h>
typedef long long ll;

struct graph {
  long row, colomn;
  std::vector<std::vector<char>> adjMatrix;
  std::vector<std::vector<bool>> visited;

  void init() {
    adjMatrix = std::vector<std::vector<char>>(row, std::vector<char>(colomn));
    visited =
        std::vector<std::vector<bool>>(row, std::vector<bool>(colomn, false));
  }

  void bfs(std::pair<long, long> start) {
    std::queue<std::pair<long, long>> q;
    std::vector<std::pair<int, int>> mv = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    q.push(start);
    visited[start.first][start.second] = true;

    while (!q.empty()) {
      std::pair<long, long> temp = q.front();
      q.pop();

      for (auto [nextRow, nextCol] : mv) {
        int newRow = temp.first + nextRow, newCol = temp.second + nextCol;

        if (newRow >= 0 && newRow < row && newCol >= 0 && newCol < colomn &&
            !visited[newRow][newCol] && adjMatrix[newRow][newCol] == '.') {

          visited[newRow][newCol] = true;
          q.push({newRow, newCol});
        }
      }
    }
  }

  int countRooms() {
    int count = 0;
    for (int i = 0; i < row; i++) {

      for (int j = 0; j < colomn; j++) {

        if (!visited[i][j] && adjMatrix[i][j] == '.') {
          count++;
          bfs({i, j});
        }
      }
    }

    return count;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  graph g;
  std::cin >> g.row >> g.colomn;
  g.init();

  std::string temp;
  for (int i = 0; i < g.row; i++) {

    std::cin >> temp;
    for (int j = 0; j < g.colomn; j++) {
      g.adjMatrix[i][j] = temp[j];
    }
  }

  std::cout << g.countRooms();

  return 0;
}
