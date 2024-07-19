#include <bits/stdc++.h>
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

  std::vector<int> sequence;
  int temp;
  std::cin >> temp;
  sequence.push_back(temp);

  for (int i = 1; i < n; i++) {
    std::cin >> temp;

    if (temp > sequence.back()) {
      sequence.push_back(temp);
    } else {
      auto index = std::lower_bound(sequence.begin(), sequence.end(), temp);
      *index = temp;
    }
  }

  std::cout << sequence.size();

  return 0;
}
