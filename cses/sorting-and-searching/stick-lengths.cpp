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

  std::vector<int> data(n);

  for (int i = 0; i < n; i++) {
    std::cin >> data[i];
  }

  sort(data.begin(), data.end());

  ll sum = 0;
  for (int it : data) {
    sum += abs(it - data[n / 2]);
  }

  std::cout << sum;
  return 0;
}
