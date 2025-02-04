class Solution {
public:
    std::vector<int> parent;

    int find_parent(int vertex) {
        if(vertex != parent[vertex]) {
            parent[vertex] = find_parent(parent[vertex]);
        }
        return parent[vertex];
    }

    bool union_set(int vertex1, int vertex2) {
        int parent1 = find_parent(vertex1);
        int parent2 = find_parent(vertex2);

        if(parent1 != parent2) {
            parent[parent1] = parent2;
            return true;
        }

        return false;
    }

    std::vector<int> findRedundantConnection(std::vector<std::vector<int>>& edges) {
        parent.resize(edges.size() + 1);
        
        for(int i = 0; i <= edges.size(); i++) {
            parent[i] = i;
        }

        std::vector<int> ans;
        for(const auto& edge : edges) {
            if(!union_set(edge[0], edge[1])) {
                ans = edge;
            }
        }

        return ans;
    }
};
