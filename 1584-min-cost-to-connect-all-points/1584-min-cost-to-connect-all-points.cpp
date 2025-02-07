class Solution {
private:
    std::vector<int> parent;

public:
    int find_parent(int v) {
        if (v != parent[v]) {
            parent[v] = find_parent(parent[v]);
        }

        return parent[v];
    }

    void union_set(int v1, int v2) {
        int parent1 = find_parent(v1);
        int parent2 = find_parent(v2);

        if (parent1 != parent2) {
            parent[parent1] = parent2;
        }
    }

    int minCostConnectPoints(std::vector<std::vector<int>>& points) {
        std::vector<int> visited(points.size(), false);
        std::vector<std::vector<int>> edges;

        for (int i = 0; i < points.size(); i++) {
            for (int j = i; j < points.size(); j++) {
                if (i == j || (visited[i] && visited[j])) {
                    continue;
                }

                int manhattan_distance = std::abs(points[i][0] - points[j][0]) +
                                         std::abs(points[i][1] - points[j][1]);

                edges.push_back({manhattan_distance, i, j});
            }
        }

        parent = std::vector<int>(points.size());
        for (int i = 0; i < points.size(); i++) {
            parent[i] = i;
        }

        std::sort(edges.begin(), edges.end());

        int ans = 0, count = 0;
        for (auto const& edge : edges) {
            int v1 = find_parent(edge[1]);
            int v2 = find_parent(edge[2]);

            if (v1 != v2) {
                ans += edge[0];
                count++;
                union_set(v1, v2);
                if (count == points.size() - 1) {
                    break;
                }
            }
        }

        return ans;
    }
};
