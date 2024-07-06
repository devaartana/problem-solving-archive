#include <bits/stdc++.h>
#include <iostream>
typedef long long ll;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int n;
  std::cin >> n;

  if (n == 1 || n > 3) {
    std::vector<int> sequence(n);
    int i = 1;
    for (int j = 1; j < n; j += 2, i++) {
      sequence[j] = i;
    }

    for (int j = 0; j < n; j += 2, i++) {
      sequence[j] = i;
    }

    for (int data : sequence) {
      std::cout << data << " ";
    }
  } else {
    std::cout << "NO SOLUTION";
  }

  return 0;
}
