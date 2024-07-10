#include <bits/stdc++.h>
#include <cinttypes>
#include <iostream>
using namespace std;

#define data long

struct graph {
  long vertexCount, edgeCount;
  vector<vector<pair<data, data>>> adjList;

  void init(data v) {
    vertexCount = v;
    edgeCount = 0;

    for (int i = 0; i < vertexCount; i++) {
      adjList.push_back({}); // inserts V ammount of empty vector
    }
  }

  void add_edge(data vertex1, data vertex2, data weight) {
    adjList[vertex1].push_back(make_pair(vertex2, weight));
    adjList[vertex2].push_back(make_pair(vertex1, weight));
    edgeCount++;
  }

  void dfs(vector<data> &result, data start) {
    vector<bool> visited(vertexCount, false);
    stack<data> st;

    st.push(start);
    visited[start] = true;
    result.push_back(start);

    while (!st.empty()) {
      data temp = st.top();
      st.pop();

      if (!visited[temp]) {
        result.push_back(temp);
        visited[temp] = true;
      }

      for (auto vertex : adjList[temp]) {
        if (!visited[vertex.first])
          st.push(vertex.first);
      }
    }
  }

  void bfs(vector<data> &result, data start) {
    vector<bool> visited(vertexCount, false);
    queue<data> q;

    q.push(start);
    visited[start] = true;
    result.push_back(start);

    while (!q.empty()) {
      data temp = q.front();
      q.pop();

      for (auto vertex : adjList[temp]) {
        if (!visited[vertex.first]) {
          q.push(vertex.first);
          visited[vertex.first] = true;
          result.push_back(vertex.first);
        }
      }
    }
  }

  void dijkstra(vector<long> &result, vector<long> &parent, data start) {
    vector<bool> visited(vertexCount, false);

    priority_queue<pair<data, data>, vector<pair<data, data>>,
                   greater<pair<data, data>>>
        pq;

    result = vector<long>(vertexCount, LONG_MAX);

    pq.push(make_pair(0, start));
    result[start] = 0;

    while (!pq.empty()) {
      auto temp = pq.top();
      pq.pop();

      visited[temp.second] = true;

      for (auto vertex : adjList[temp.second]) {
        long nextVertex = vertex.first;
        long weight = vertex.second;

        if (!visited[nextVertex]) {
          if (temp.first + weight < result[nextVertex]) {
            result[nextVertex] = temp.first + weight;
            parent[nextVertex] = temp.second;
            pq.push(make_pair(result[nextVertex], nextVertex));
          }
        }
      }
    }
  }
};

int main() {
  long v, e;
  cin >> v >> e;

  graph g;
  g.init(v + 1);

  long vertex1, vertex2;
  for (int i = 0; i < e; i++) {
    cin >> vertex1 >> vertex2;
    g.add_edge(vertex1, vertex2, 1);
  }

  vector<long> result(v + 1, 0);
  vector<long> parent(v + 1, 0);

  g.dijkstra(result, parent, 1);

  if (result[v] == LONG_MAX) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  } else {
    cout << result[v] + 1 << endl;
  }

  long target = v;
  vector<long> path;
  while (target) {
    path.push_back(target);
    target = parent[target];
  }

  reverse(path.begin(), path.end());
  for (long vertex : path) {
    cout << vertex << " ";
  }

  return 0;
}
