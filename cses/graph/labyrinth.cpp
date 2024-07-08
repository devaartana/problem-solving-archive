#include <bits/stdc++.h>
typedef long long ll;
typedef std::pair<std::string, std::pair<int, int>> data;

struct graph {
  long row, colomn;
  char adjMatrix[1000][1000];
  int prev[1000][1000];
  std::vector<std::vector<bool>> visited =
      std::vector<std::vector<bool>>(1000, std::vector<bool>(1000, false));
  std::vector<std::pair<int, int>> mv = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
  std::string mvName = "RDUL";

  void bfs(std::pair<long, long> start, std::pair<long, long> target) {
    std::queue<std::pair<int, int>> q;

    q.push(start);
    visited[start.first][start.second] = true;

    while (!q.empty()) {
      auto temp = q.front();
      q.pop();

      for (int i = 0; i < 4; i++) {
        int newRow = temp.first + mv[i].first,
            newCol = temp.second + mv[i].second;
        if (newRow < 0 || newRow >= row || newCol < 0 || newCol >= colomn ||
            adjMatrix[newRow][newCol] == '#' || visited[newRow][newCol])
          continue;

        visited[newRow][newCol] = true;
        q.push({newRow, newCol});
        prev[newRow][newCol] = i;
      }
    }
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  graph g;
  std::cin >> g.row >> g.colomn;

  std::pair<long, long> start, end;
  for (int i = 0; i < g.row; i++) {
    for (int j = 0; j < g.colomn; j++) {

      std::cin >> g.adjMatrix[i][j];

      if (g.adjMatrix[i][j] == 'A')
        start = {i, j};
      else if (g.adjMatrix[i][j] == 'B')
        end = {i, j};
    }
  }

  g.bfs(start, end);

  if (g.visited[end.first][end.second]) {
    std::cout << "YES\n";

    std::vector<int> path;
    while (start != end) {
      int index = g.prev[end.first][end.second];
      path.push_back(index);
      end = {end.first - g.mv[index].first, end.second - g.mv[index].second};
    }

    std::reverse(path.begin(), path.end());

    std::cout << path.size() << '\n';

    for (int i : path)
      std::cout << g.mvName[i];
  } else {
    std::cout << "NO";
  }
  return 0;
}
