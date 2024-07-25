#include <bits/stdc++.h>
#define IOS                                                                    \
  std::ios_base::sync_with_stdio(false);                                       \
  std::cin.tie(NULL);                                                          \
  std::cout.tie(NULL);
typedef long long ll;
const int N = 1e7 + 10;

int main() {
  IOS;

  int n;
  std::cin >> n;

  std::vector<std::pair<int, int>> vec(n);
  for (int i = 0; i < n; i++) {
    std::cin >> vec[i].second >> vec[i].first;
  }

  std::sort(vec.begin(), vec.end());

  int temp = 0, count = 0;
  for (int i = 0; i < n; i++) {
    if (vec[i].second >= temp) {
      count++;
      temp = vec[i].first;
    }
  }

  std::cout << count;
  return 0;
}
