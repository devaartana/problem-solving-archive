#include <bits/stdc++.h>
typedef long long ll;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  ll n, coin1, coin2;
  std::cin >> n;

  for (int i = 0; i < n; i++) {
    std::cin >> coin1 >> coin2;

    if (coin2 > coin1)
      std::swap(coin1, coin2);
    ll difference = coin1 - coin2;

    if (difference <= coin2 && (coin1 + coin2 - difference * 3) % 3 == 0) {
      std::cout << "YES\n";
    } else {
      std::cout << "NO\n";
    }
  }
  return 0;
}
