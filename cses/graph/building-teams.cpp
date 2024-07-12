#include <bits/stdc++.h>
#include <vector>
#define IOS                                                                    \
  std::ios_base::sync_with_stdio(false);                                       \
  std::cin.tie(NULL);                                                          \
  std::cout.tie(NULL);
typedef long long ll;
const int N = 1e7 + 10;

int main() {
  IOS;

  ll v, e;
  std::cin >> v >> e;

  std::vector<std::vector<int>> adjList(v + 1, std::vector<int>());
  std::vector<bool> visited(v + 1, false);
  std::vector<int> team(v + 1, -1);

  int v1, v2;
  for (int i = 0; i < e; i++) {
    std::cin >> v1 >> v2;
    adjList[v1].push_back(v2);
    adjList[v2].push_back(v1);
  }

  for (int i = 1; i <= v; i++) {
    if (!visited[i]) {
      std::stack<int> st;
      st.push(i);
      team[i] = 0;

      while (!st.empty()) {
        int temp = st.top();
        st.pop();

        if (!visited[temp]) {
          visited[temp] = true;
        }

        for (int vertex : adjList[temp]) {
          std::cout << temp << " " << vertex << std::endl;
          if (!visited[vertex]) {

            team[vertex] = !team[temp];
            st.push(vertex);

          } else if (team[vertex] == team[temp]) {
            std::cout << vertex << " " << temp << " " << team[vertex] << " "
                      << team[temp] << "IMPOSSIBLE";
            return 0;
          }
        }
      }
    }
  }
  for (int i = 1; i <= v; i++) {
    std::cout << team[i] + 1 << " ";
  }
  return 0;
}
