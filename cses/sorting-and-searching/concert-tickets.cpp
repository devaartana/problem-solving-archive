#include <bits/stdc++.h>
#define IOS                                                                    \
  std::ios_base::sync_with_stdio(false);                                       \
  std::cin.tie(NULL);                                                          \
  std::cout.tie(NULL);
typedef long long ll;
const int N = 1e7 + 10;

int main() {
  IOS;

  int n, m;
  std::cin >> n >> m;

  int temp;
  std::map<int, int> tickets;
  for (int i = 0; i < n; i++) {
    std::cin >> temp;
    tickets[temp]++;
  }

  int target;
  for (int i = 0; i < m; i++) {
    std::cin >> target;

    auto ans = tickets.upper_bound(target);
    if (ans == tickets.begin()) {
      std::cout << -1 << "\n";
    } else {
      std::cout << (--ans)->first << "\n";
      tickets[ans->first]--;

      if (tickets[ans->first] == 0)
        tickets.erase(ans);
    }
  }

  return 0;
}
