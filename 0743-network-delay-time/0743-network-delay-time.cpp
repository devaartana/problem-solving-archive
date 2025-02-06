class Solution {
  public:
    int networkDelayTime(std::vector<std::vector<int>> &times, int n, int k) {
        std::vector<std::vector<std::pair<int, int>>> adjList(n + 1);
        for (auto const &time : times) {
            adjList[time[0]].push_back({time[1], time[2]});
        }

        auto cmp = [](std::pair<int, int> const &a,
                      std::pair<int, int> const &b) {
            return a.second > b.second;
        };
        std::priority_queue<std::pair<int, int>,
                            std::vector<std::pair<int, int>>, decltype(cmp)>
            pq(cmp);
        std::vector<int> result(n + 1, INT_MAX);
        std::vector<int> visited(n + 1, false);

        pq.push({k, 0});
        result[k] = 0;

        while (!pq.empty()) {
            auto temp = pq.top();
            pq.pop();

            visited[temp.first] = true;

            for (auto [v, w] : adjList[temp.first]) {
                int total = w + temp.second;
                if (!visited[v] && total < result[v]) {
                    result[v] = total;
                    pq.push({v, total});
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if(!visited[i]) {
                return -1;
            }
            ans = std::max(ans, result[i]);
        }
        return ans;
    }
};
