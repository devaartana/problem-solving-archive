#include <algorithm>
#include <bits/stdc++.h>
typedef long long ll;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int n, m, k;
  std::cin >> n >> m >> k;

  std::vector<ll> demands(n), apartements(m);
  for (ll i = 0; i < n; i++) {
    std::cin >> demands[i];
  }

  for (ll i = 0; i < m; i++) {
    std::cin >> apartements[i];
  }

  std::sort(demands.begin(), demands.end());
  std::sort(apartements.begin(), apartements.end());

  int count = 0, i = 0, j = 0;

  while (i != n && j != m) {
    if (demands[i] >= apartements[j] - k && demands[i] <= apartements[j] + k) {
      count++;
      i++;
      j++;
    } else if (demands[i] > apartements[j]) {
      j++;
    } else {
      i++;
    }
  }

  std::cout << count;

  return 0;
}
