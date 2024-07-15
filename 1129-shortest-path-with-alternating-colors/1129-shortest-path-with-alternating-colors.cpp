class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<vector<int>>> al(2, vector<vector<int>>(n, vector<int>()));
        vector<vector<bool>> visited(2, vector<bool>(n, false));

        for(auto edge:redEdges){
            al[0][edge[0]].push_back(edge[1]);
        }
        for(auto edge:blueEdges){
            al[1][edge[0]].push_back(edge[1]);
        }

        queue<pair<pair<int, int>, bool>> q;
        for(int i=0; i < 2; i++){
            visited[i][0] = true;
            q.push({{0, 0}, i});
        }
        
        vector<int> result(n, -1);
        result[0] = 0;
        while(!q.empty()){
            auto temp = q.front();
            q.pop();

            for(int vertex:al[!temp.second][temp.first.first]){
                if(!visited[!temp.second][vertex]){
                    if(result[vertex] == -1 || temp.first.second + 1 < result[vertex]){
                        result[vertex] = temp.first.second + 1;
                    }

                    visited[!temp.second][vertex] = true;
                    q.push({{vertex, temp.first.second + 1}, !temp.second});
                }
            }
        }

        return result;
    }
};