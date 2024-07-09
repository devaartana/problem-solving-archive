#include <bits/stdc++.h>
typedef long long ll;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int n, tmp;
  std::cin >> n;

  std::unordered_set<int> exist;
  exist.reserve(200003);

  for (int i = 0; i < n; i++) {
    std::cin >> tmp;
    exist.insert(tmp);
  }

  std::cout << exist.size();

  return 0;
}
