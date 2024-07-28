/*
 *  Time complexity: O(n log n)
 *  Space complexity: O(n)
 *  Data structure: std::map<int, int>(tree)
 *  Algorithms: -
 */
#include <bits/stdc++.h>
#define IOS                                                                    \
  std::ios_base::sync_with_stdio(false);                                       \
  std::cin.tie(NULL);                                                          \
  std::cout.tie(NULL);
typedef long long ll;
typedef std::vector<int> vi;
const int N = 1e9 + 7;

/*
 * n: input length
 * m: traffic current length
 * k: longest current length
 */
int main() {
  IOS;

  int temp, x, n;
  std::cin >> x >> n;

  // key: traffic light, value: passage lenght from previous traffic light
  std::map<int, int> traffic;

  // key: passage length, value: count
  std::map<int, int> longest;
  traffic[0] = 0;
  traffic[x] = x;

  for (int i = 0; i < n; i++) {
    std::cin >> temp;

    auto search = traffic.upper_bound(temp); // T(log m);

    // remove/decrement upper bound passage length
    longest[search->second]--;        // T(log k)
    if (longest[search->second] <= 0) // T(log k)
      longest.erase(search->second);

    // add new passage length for upper bound to map
    search->second = search->first - temp;
    longest[search->second]++; // T(log k)

    // add new traffic light and passage length from temp
    traffic[temp] = temp - (--search)->first; // T(log m)
    longest[traffic[temp]]++;                 // T(log k)

    std::cout << (--longest.end())->first << " ";
  }

  return 0;
}
