#include <bits/stdc++.h>
#define IOS                                                                    \
  std::ios_base::sync_with_stdio(false);                                       \
  std::cin.tie(NULL);                                                          \
  std::cout.tie(NULL);
typedef long long ll;
const int N = 1e7 + 10;

int main() {
  IOS;

  int n, temp, target;
  std::cin >> n >> target;

  std::unordered_map<int, int> umap;
  for (int i = 0; i < n; i++) {
    std::cin >> temp;

    if (temp < target) {
      auto search = umap.find(target - temp);

      if (search != umap.end()) {
        std::cout << search->second + 1 << " " << i + 1;
        return 0;
      }

      umap[temp] = i;
    }
  }

  std::cout << "IMPOSSIBLE";

  return 0;
}
