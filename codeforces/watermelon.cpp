#include <bits/stdc++.h>
using namespace std;

int solve(int data) {
  for (int i = 2; i < data; i += 2) {
    if (!((data - i) & 1) && !(i & 1)) {
      return 1;
    }
  }

  return 0;
}

int main() {

  int w;
  std::cin >> w;

  if (solve(w)) {
    printf("YES");
  } else {
    printf("NO");
  }

  return 0;
}
