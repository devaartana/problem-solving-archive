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

        if (parent1 != parent2){
            if(parent1 > parent2) parent[parent1] = parent2;         
            else parent[parent2] = parent1;
        }
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> parent(26);

        for(int i=0; i<26; i++){
            parent[i] = i;
        }

        for(int i=0; i<s1.size(); i++){
            union_set(parent, s1[i] - 'a', s2[i] -'a');
        }

        for(int i=0; i<26; i++){
            parent[i] = find_parent(parent, i);
        }

        for(int i=0; i<baseStr.size(); i++){
            baseStr[i] = (char)(parent[baseStr[i] - 'a'] + 'a');
        }

        return baseStr;
    }
};