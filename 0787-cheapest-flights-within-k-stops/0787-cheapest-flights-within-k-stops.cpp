class Solution {
  public:
    int findCheapestPrice(int n, std::vector<std::vector<int>> &flights,
                          int src, int dst, int k) {
        std::vector<int> cost(n, INT_MAX);
        cost[src] = 0;

        for (int i = 0; i < k + 1; i++) {
            std::vector<int> tempCost = cost;

            for (auto const &flight : flights) {
                if (cost[flight[0]] == INT_MAX) {
                    continue;
                }

                int total = cost[flight[0]] + flight[2];
                if (tempCost[flight[1]] > total) {
                    tempCost[flight[1]] = total;
                }
            }
            cost = tempCost;
        }

        return cost[dst] == INT_MAX ? -1 : cost[dst];
    }
};
