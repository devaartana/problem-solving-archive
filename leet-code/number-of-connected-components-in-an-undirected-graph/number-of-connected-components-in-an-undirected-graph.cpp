#include <unordered_set>
#include <vector>

class Solution {
private:
  std::vector<int> parent;
  
  int find(int v) {
    if (v != parent[v]) {
      parent[v] = find(parent[v]);
    }

    return parent[v];
  }

  void unionSet(int v1, int v2) {

    int parent1 = find(v1);
    int parent2 = find(v2);

    if (parent1 != parent2) {
      parent[parent1] = parent2;
    }
  }
public:
  int countComponents(int n, std::vector<std::vector<int>> &edges) {
    parent.resize(n);
    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }

    for (const auto &edge : edges) {
      unionSet(edge[0], edge[1]);
    }

    std::unordered_set<int> ans;
    for(int i = 0; i < n; i++) {
      ans.insert(find(i));
    }
    
    return ans.size() + 1;
  }
};

int main() {

  Solution test;

  int n = 4;
  std::vector<std::vector<int>> test1 = {{0, 1}, {2, 3}, {1, 2}};

  test.countComponents(n, test1);
}
