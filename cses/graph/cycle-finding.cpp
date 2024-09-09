#include <bits/stdc++.h>
#define IOS                                                                    \
  std::ios_base::sync_with_stdio(false);                                       \
  std::cin.tie(NULL);                                                          \
  std::cout.tie(NULL);
typedef long long ll;
const int INF = 1e9;

struct graph {
  ll vertexCount, edgeCount;
  std::vector<std::tuple<ll, ll, ll>> edges;
  std::vector<ll> parent;

  void init(ll n, ll m) {
    vertexCount = n;
    edgeCount = m;

    edges.reserve(edgeCount);
    parent = std::vector<ll>(vertexCount, -1);
  }

  void findNegativeCycle(std::vector<ll> &distance) {
    int target;
    for (int i = 0; i < vertexCount; i++) {
      target = -1;
      for (auto [u, v, w] : edges) {
        if (distance[u] + w < distance[v]) {
          distance[v] = distance[u] + w;
          parent[v] = u;
          target = v;
        }
      }
    }

    if (target == -1) {
      std::cout << "NO\n";
      return;
    }

    for (ll i = 0; i < vertexCount; i++) {
      target = parent[target];
    }

    std::vector<ll> path;
    for (ll v = target;; v = parent[v]) {
      path.push_back(v);
      if (v == target && path.size() > 1)
        break;
    }

    reverse(path.begin(), path.end());

    std::cout << "YES\n";
    for (auto v : path) {
      std::cout << v << " ";
    }
    std::cout << "\n";
  }
};

int main() {
  IOS;

  ll v, e, v1, v2, w;
  std::cin >> v >> e;

  graph g;
  g.init(v + 1, e);

  for (int i = 0; i < e; i++) {
    std::cin >> v1 >> v2 >> w;
    g.edges.emplace_back(v1, v2, w);
  }

  std::vector<ll> distance(v, INF);
  distance[0] = 0;

  g.findNegativeCycle(distance);

  return 0;
}
