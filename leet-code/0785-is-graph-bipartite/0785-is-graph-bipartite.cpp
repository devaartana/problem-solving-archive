class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<bool> visited(graph.size(), false);
        vector<int> sets(graph.size(), -1);

        for(int i=0; i<graph.size(); i++){
            if(!visited[i]){
                queue<int> q;
                q.push(i);
                visited[i] = true;
                sets[i] = 0;

                while(!q.empty()){
                    int temp = q.front();
                    q.pop();

                    for(int vertex:graph[temp]){
                        if(!visited[vertex]){
                            q.push(vertex);
                            sets[vertex] = !sets[temp];
                            visited[vertex] = true;
                        } else if(sets[vertex] == sets[temp]){
                            return false;
                        }
                    }
                }
            }
        }
        
        return true;
    }
};