/*
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Data structure: std::unordered_map(hashmap)
 * Algoritms: sliding windows
 */
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

  // first_idx: start index after meet duplicate
  int temp, first_idx = 0, maxUniqueSequence = 1;
  std::unordered_map<int, int> memo;
  memo.rehash(200003);

  for (int i = 0; i < n; i++) {
    std::cin >> temp;

    // update first_idx if encounter a duplicate in the range  of first_idx
    // and current index
    if (memo[temp] > first_idx) {
      int length = i - first_idx;

      // updaet max length
      if (length > maxUniqueSequence) {
        maxUniqueSequence = length;
      }

      first_idx = memo[temp];
    }

    memo[temp] = i + 1;
  }

  int length = n - first_idx;

  if (length > maxUniqueSequence) {
    maxUniqueSequence = length;
  }

  std::cout << maxUniqueSequence;
  return 0;
}
