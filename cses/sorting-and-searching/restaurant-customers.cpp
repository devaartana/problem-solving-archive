#include <bits/stdc++.h>
#include <unordered_set>
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

  std::map<int, int> mp;
  int timeIn, timeOut;
  for (int i = 0; i < n; i++) {
    std::cin >> timeIn >> timeOut;
    mp[timeIn] = 1;
    mp[timeOut] = -1;
  }

  int customer = 0, maxCustomer = 0;
  for (auto [key, time] : mp) {
    if (time == 1)
      customer++;
    else {
      if (customer > maxCustomer) {
        maxCustomer = customer;
      }

      customer--;
    }
  }

  std::cout << maxCustomer;
  return 0;
}
