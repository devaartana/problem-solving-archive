class Solution {
public:
    unordered_map<string, int> umap;
    unordered_map<int, set<string>> merge_result;

    int find_parent(vector<int> &parent, int v){
        if (v == parent[v])
            return v;

        return parent[v] = find_parent(parent, parent[v]);
    }

    void union_set(vector<int> &parent, int vertex1, int vertex2){
        int parent1 = find_parent(parent, vertex1);
        int parent2 = find_parent(parent, vertex2);

        if (parent1 != parent2)
            parent[parent2] = parent1;
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<int> parent(n);
        
        for(int i=0; i<n; i++){
            parent[i] = i;
        }

        for(int i=0; i<n; i++){
            for(int j=1; j<accounts[i].size(); j++){
                if(umap.find(accounts[i][j]) == umap.end()){
                    umap[accounts[i][j]] = i;
                } else {
                    union_set(parent, i, umap[accounts[i][j]]);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            parent[i] = find_parent(parent, i);
        }

        for(int i=0; i<n; i++){
            for(int j=1; j < accounts[i].size(); j++){
                merge_result[parent[i]].insert(accounts[i][j]);
            }
        }

        vector<vector<string>> result;
        for (auto it = merge_result.begin(); it != merge_result.end(); it++){
            vector<string> temp;

            temp.push_back(accounts[it->first][0]);

            for(const auto& email: it->second){
                temp.push_back(email);
            }

            result.push_back(temp);
        }

        return result;
    }
};