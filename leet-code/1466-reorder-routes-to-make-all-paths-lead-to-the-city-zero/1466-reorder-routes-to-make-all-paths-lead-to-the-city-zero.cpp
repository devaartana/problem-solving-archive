class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        
        vector<vector<pair<int, int>>> adjList(n, vector<pair<int, int>>());
        for(auto edge:connections){
            adjList[edge[0]].push_back({edge[1], 1});
            adjList[edge[1]].push_back({edge[0], 0});
        }
        
        vector<bool> visited(n, false);
        
        queue<int> q;
        q.push(0);
        visited[0] = true;

        int count = 0;
        while(!q.empty()){
            int temp = q.front();
            q.pop();

            for(auto [vertex, direction]:adjList[temp]){
                if(!visited[vertex]){
                    q.push(vertex);
                    count += direction;
                    visited[vertex] = true;
                }
            } 
        }

        return count;
    }
};