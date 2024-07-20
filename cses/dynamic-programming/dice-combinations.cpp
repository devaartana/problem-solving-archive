#include <bits/stdc++.h>
#define IOS                                                                    \
  std::ios_base::sync_with_stdio(false);                                       \
  std::cin.tie(NULL);                                                          \
  std::cout.tie(NULL);
typedef long long ll;
const int N = 1e6;
const int MOD = 1e9 + 7;

ll tab[N] = {};

ll combination(ll n) {
  if (n == 0)
    return 1;
  else if (n < 0)
    return 0;
  else if (tab[n])
    return tab[n];

  return tab[n] =
             (combination(n - 1) + combination(n - 2) + combination(n - 3) +
              combination(n - 4) + combination(n - 5) + combination(n - 6)) %
             MOD;
}
int main() {
  IOS;

  int n;
  std::cin >> n;

  std::cout << combination(n);

  return 0;
}
