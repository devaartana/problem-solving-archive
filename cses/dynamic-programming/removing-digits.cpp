#include <climits>
#include <iostream>
#include <unordered_map>
#define IOS                                                                    \
    std::ios_base::sync_with_stdio(false);                                     \
    std::cin.tie(NULL);                                                        \
    std::cout.tie(NULL);
const int N = 1e9 + 7;

class Solution {
  private:
    std::unordered_map<int, int> memo;

  public:
    int n;
    void init() { std::cin >> n; }

    int top_down(int n) {
        if (!n) {
            return 0;
        }

        if (memo.find(n) != memo.end()) {
            return memo[n];
        }

        memo[n] = 1e6;
        int target = n;

        while (target) {
            int digit = target % 10;
            if (digit) {
                memo[n] = std::min(top_down(n - digit) + 1, memo[n]);
            }
            target /= 10;
        }

        return memo[n];
    }
};

int main() {
    IOS;

    Solution prob;
    prob.init();
    std::cout << prob.top_down(prob.n);

    return 0;
}
