#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> adjList;
  std::vector<bool> visited;
  std::vector<int> parent;

  bool helper(int vertex) {
    visited[vertex] = true;

    for (int neighbour : adjList[vertex]) {
      if (visited[neighbour] && neighbour != parent[vertex]) {
        return false;
      }

      if (visited[neighbour]) {
        continue;
      }

      parent[neighbour] = vertex;
      if (!helper(neighbour)) {
        return false;
      }
    }

    return true;
  }

  bool validTree(int n, std::vector<std::vector<int>> &edges) {

    adjList = std::vector<std::vector<int>>(n, std::vector<int>());
    visited = std::vector<bool>(n, false);
    parent = std::vector<int>(n, -1);

    for (const auto &edge : edges) {
      if (edge[0] == edge[1]) {
        return false;
      }
      adjList[edge[0]].push_back(edge[1]);
      adjList[edge[1]].push_back(edge[0]);
    }

    if (helper(0)) {
      for (bool status : visited) {
        if (!status) {
          return false;
        }
      }

      return true;
    }
    return false;
  }
};
