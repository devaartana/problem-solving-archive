#include <bits/stdc++.h>
#define IOS                                                                    \
  std::ios_base::sync_with_stdio(false);                                       \
  std::cin.tie(NULL);                                                          \
  std::cout.tie(NULL);
typedef long long ll;
const int N = 2 * 1e5 + 1;

int track[N];

int main() {
  IOS;

  int n, temp, count = 0;
  std::cin >> n;

  for (int i = 1; i <= n; i++) {
    std::cin >> temp;

    track[temp] = i;
  }

  temp = INT_MAX;
  for (int i = 1; i <= n; i++) {
    if (temp > track[i]) {
      count++;
    }

    temp = track[i];
  }

  std::cout << count;
  return 0;
}
