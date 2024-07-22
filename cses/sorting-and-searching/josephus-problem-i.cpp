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

  std::queue<int> q;

  if (n & 1) {
    for (int i = 1; i <= n; i++) {

      if (i & 1)
        q.push(i);
      else
        std::cout << i << " ";
    }

    while (!q.empty()) {
      std::cout << q.front() << " ";
      q.pop();

      if (!q.empty()) {
        int temp = q.front();
        q.push(temp);
        q.pop();
      }
    }
  } else {
    for (int i = 1; i <= n; i++) {

      if (i & 1)
        q.push(i);
      else
        std::cout << i << " ";
    }

    while (!q.empty()) {

      int temp = q.front();
      q.push(temp);
      q.pop();

      if (!q.empty()) {
        std::cout << q.front() << " ";
        q.pop();
      }
    }
  }
  return 0;
}
