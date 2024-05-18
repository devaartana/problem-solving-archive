#include <bits/stdc++.h>
using namespace std;

struct graph {
  long vertexCount, edgeCount;
  vector<vector<long>> adjList;

  void init(long v) {
    vertexCount = v;
    edgeCount = 0;

    for (int i = 0; i < vertexCount; i++) {
      adjList.push_back({}); // inserts V ammount of empty vector
    }
  }

  void add_edge(long vertex1, long vertex2) {
    adjList[vertex1].push_back(vertex2);
    edgeCount++;
  }

  void dfs_recursive(vector<bool> &visited, long *count, long start, long end,
                     long depth, long maxDepth) {

    if (start == end) {
      (*count)++;
      return;
    }

    visited[start] = true;

    for (auto vertex : adjList[start]) {
      if (!visited[vertex] && depth < maxDepth)
        dfs_recursive(visited, count, vertex, end, depth + 1, maxDepth);
    }

    visited[start] = false;
  }
};

int main() {

  long n, k, a, b, d;
  cin >> n >> k >> a >> b >> d;

  graph g;
  g.init(n + 1);

  long v1, v2;

  for (int i = 0; i < k; i++) {
    cin >> v1 >> v2;

    g.add_edge(v1, v2);
  }

  vector<bool> visited(g.vertexCount, false);
  long count = 0;

  g.dfs_recursive(visited, &count, a, b, 0, d);

  cout << count;

  return 0;
}
