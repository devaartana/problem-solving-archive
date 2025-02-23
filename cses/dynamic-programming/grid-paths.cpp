#include <iostream>
#include <vector>
#define IOS                                                                    \
    std::ios_base::sync_with_stdio(false);                                     \
    std::cin.tie(NULL);                                                        \
    std::cout.tie(NULL);
const int N = 1e9 + 7;
typedef long long ll;

class Solution {
  private:
    int n;
    std::vector<std::vector<char>> grid;

  public:
    void init() {
        std::cin >> n;

        grid = std::vector<std::vector<char>>(n + 1, std::vector<char>(n + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                std::cin >> grid[i][j];
            }
            std::cin.ignore();
        }
    }

    ll solve() {
        if (grid[1][1] == '*') {
            return 0;
        }

        std::vector<std::vector<ll>> tab(n + 1, std::vector<ll>(n + 1, 0));
        tab[1][1] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (grid[i][j] == '*') {
                    continue;
                }

                if (grid[i - 1][j] != '*') {
                    tab[i][j] = (tab[i][j] + tab[i - 1][j]) % N;
                }

                if (grid[i][j - 1] != '*') {
                    tab[i][j] = (tab[i][j] + tab[i][j - 1]) % N;
                }
            }
        }

        return tab[n][n] % N;
    }
};

int main() {
    IOS;

    Solution prob;
    prob.init();
    std::cout << prob.solve();

    return 0;
}
