class Solution {
public:
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
    
    bool equationsPossible(vector<string>& equations) {
        vector<int> parent(27, 0);

        for(int i=0; i<27; i++){
            parent[i] = i;
        }

        int x, y;
        for(auto eq:equations){
            if(eq[1] == '='){
                x = eq[0] - 'a';
                y = eq[3] - 'a';

                union_set(parent, x, y);
            }
        }

        for(int i=0; i<27; i++){
            parent[i] = find_parent(parent, i);
        }

        for(auto eq:equations){
            if(eq[1] == '!'){
                x = eq[0] - 'a';
                y = eq[3] - 'a';

                if(parent[x] == parent[y]) return false;
            }
        }

        return true;
    }
};