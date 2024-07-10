class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
       ios::sync_with_stdio(false); 
       cin.tie(0); 
       
       vector<int> count(n, 0), ans;
       for(auto edge:edges){
        count[edge[1]]++;
       }

       for(int i=0; i < n; i++){
        if(!count[i]) ans.push_back(i);
       }

       return ans;
    }
};