#include <bits/stdc++.h>
#define IOS                                                                    \
  std::ios_base::sync_with_stdio(false);                                       \
  std::cin.tie(NULL);                                                          \
  std::cout.tie(NULL);
typedef long long ll;
const int N = 1e9 + 7;

int main() {
  IOS;

  int n;
  std::cin >> n;

  std::vector<ll> array(n);
  for (int i = 0; i < n; i++) {
    std::cin >> array[i];
  }

  ll tempMax = array[0], maxSum = array[0];

  for (int i = 1; i < n; i++) {
    tempMax = std::max(array[i], array[i] + tempMax);

    if (tempMax > maxSum) {
      maxSum = tempMax;
    }
  }

  std::cout << maxSum;
  return 0;
}
