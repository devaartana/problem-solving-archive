#include <bits/stdc++.h>
#define IOS                                                                    \
  std::ios_base::sync_with_stdio(false);                                       \
  std::cin.tie(NULL);                                                          \
  std::cout.tie(NULL);
typedef long long ll;
const int N = 1e9 + 7;

int main() {
  IOS;

  int n, temp;
  std::cin >> n;

  std::map<int, int> mp;
  for (int i = 0; i < n; i++) {
    std::cin >> temp;

    auto result = mp.upper_bound(temp);
    if (result != mp.end()) {
      result->second--;
      if (result->second <= 0) {
        mp.erase(result);
      }
    }

    mp[temp]++;
  }

  int count = 0;
  for (auto it = mp.begin(); it != mp.end(); it++) {
    count += it->second;
  }

  std::cout << std::endl << count;
  return 0;
}
