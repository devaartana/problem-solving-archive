#include <bits/stdc++.h>
#include <vector>
#define IOS                                                                    \
  std::ios_base::sync_with_stdio(false);                                       \
  std::cin.tie(NULL);                                                          \
  std::cout.tie(NULL);
typedef long long ll;
const int N = 1e7 + 10;

void printPath(std::vector<int> &parent, int start, int end, int count) {

  if (start == end) {
    std::cout << count + 1 << "\n" << start << " ";
    return;
  }

  printPath(parent, parent[start], end, count + 1);
  std::cout << start << " ";
}

int main() {
  IOS;

  int v, e, v1, v2;
  std::cin >> v >> e;

  std::vector<std::vector<int>> al(v + 1, std::vector<int>());
  for (int i = 0; i < e; i++) {
    std::cin >> v1 >> v2;
    al[v1].push_back(v2);
    al[v2].push_back(v1);
  }

  std::vector<int> parent(v + 1, 0);
  std::vector<bool> visited(v + 1, false);

  for (int i = 1; i <= v; i++) {
    if (!visited[i]) {
      std::stack<int> st;
      st.push(i);
      visited[i] = true;

      while (!st.empty()) {
        int temp = st.top();
        st.pop();

        if (!visited[temp]) {
          visited[temp] = true;
        }

        for (int vertex : al[temp]) {
          if (!visited[vertex]) {
            st.push(vertex);
            parent[vertex] = temp;
          } else if (vertex != parent[temp]) {
            printPath(parent, temp, vertex, 1);
            std::cout << vertex << " ";
            return 0;
          }
        }
      }
    }
  }
  std::cout << "IMPOSSIBLE";
  return 0;
}
