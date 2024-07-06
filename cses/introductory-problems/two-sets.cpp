#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
typedef long long ll;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int n;
  std::cin >> n;

  if (((n * (n + 1)) / 2) & 1) {
    std::cout << "NO";
  } else {
    std::cout << "YES";

    ll firstSum = n, secSum = 0;
    std::vector<int> first = {n}, second;
    for (int i = n - 1; i > 0; i--) {
      if (firstSum >= secSum) {
        secSum += i;
        second.push_back(i);
      } else {
        firstSum += i;
        first.push_back(i);
      }
    }

    std::reverse(first.begin(), first.end());
    std::reverse(second.begin(), second.end());

    std::cout << "\n" << first.size() << "\n";
    for (ll data : first) {
      std::cout << data << " ";
    }

    std::cout << "\n" << second.size() << "\n";
    for (ll data : second) {
      std::cout << data << " ";
    }
  }

  return 0;
}
