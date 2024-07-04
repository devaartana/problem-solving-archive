class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        int target = graph.size() - 1;
        queue<pair<int, vector<int>>> q;
        q.push({0, {0}});

        vector<vector<int>> ans;

        while(!q.empty()){
            auto temp = q.front();

            if(temp.first == target) ans.push_back(temp.second);
            
            int last = temp.second.size();
            temp.second.push_back(-1);
            q.pop();
            
            for(auto vertex:graph[temp.first]){
                temp.second[last] = vertex;
                q.push({vertex, temp.second});
            }
        }

        return ans;
    }
};