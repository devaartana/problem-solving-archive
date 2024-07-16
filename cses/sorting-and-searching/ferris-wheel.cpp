#include <bits/stdc++.h>
#define IOS                                                                    \
  std::ios_base::sync_with_stdio(false);                                       \
  std::cin.tie(NULL);                                                          \
  std::cout.tie(NULL);
typedef long long ll;
const int N = 1e7 + 10;

int main() {
  IOS;

  int n, x;
  std::cin >> n >> x;

  std::vector<int> children(n);
  for (int i = 0; i < n; i++) {
    std::cin >> children[i];
  }

  std::sort(children.begin(), children.end());

  int lo = 0, hi = children.size() - 1;
  while (lo < hi) {
    if (children[lo] + children[hi] <= x) {
      lo++;
    }
    hi--;
  }

  std::cout << children.size() - lo;

  return 0;
}
