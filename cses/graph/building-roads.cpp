#include <bits/stdc++.h>
#define IOS                                                                    \
  std::ios_base::sync_with_stdio(false);                                       \
  std::cin.tie(NULL);                                                          \
  std::cout.tie(NULL);
typedef long long ll;
const int N = 1e7 + 10;

int find_parent(std::vector<int> &parent, int vertex) {
  if (vertex == parent[vertex]) {
    return vertex;
  }

  return parent[vertex] = find_parent(parent, parent[vertex]);
}

void union_set(std::vector<int> &parent, int vertex1, int vertex2) {
  int parent1 = find_parent(parent, vertex1);
  int parent2 = find_parent(parent, vertex2);

  if (parent1 != parent2) {
    parent[parent2] = parent1;
  }
}

int main() {
  IOS;

  int v, e, v1, v2;
  std::cin >> v >> e;

  std::vector<int> parent(v + 1);
  std::vector<bool> visited(v + 1, false);
  for (int i = 1; i <= v; i++) {
    parent[i] = i;
  }

  for (int i = 0; i < e; i++) {
    std::cin >> v1 >> v2;
    visited[v1] = visited[v2] = true;
    union_set(parent, v1, v2);
  }

  std::map<int, bool> umap;

  for (int i = 1; i <= v; i++) {
    parent[i] = find_parent(parent, parent[i]);
    umap[parent[i]] = true;
  }

  std::cout << umap.size() - 1 << "\n";
  int prev = -1;
  for (auto &pair : umap) {
    if (prev == -1) {
      prev = pair.first;
    } else {
      std::cout << prev << " " << pair.first << "\n";
      prev = pair.first;
    }
  }

  return 0;
}
