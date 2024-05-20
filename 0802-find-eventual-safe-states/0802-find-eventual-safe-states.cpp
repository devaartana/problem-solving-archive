class Solution {
public:

    bool dfs_recursion( vector<vector<int>>& graph, vector<bool> &visited, vector<bool> &safe, int start){

        if(safe[start]) return true;
        if(visited[start]) return false;

        visited[start] = true;

        for(auto vertex:graph[start]){
            if(!dfs_recursion(graph, visited, safe, vertex)){
                return false;
            }
            
        }

        visited[start] = false;
        safe[start] = true;

        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int size = graph.size();
        vector<bool> visited(size, false);
        vector<bool> safe(size, false);

        for(int i=0; i<size; i++){
            if(graph[i].empty()) {
                safe[i] = true;
                continue;
            }

            if(!visited[i]) safe[i] = dfs_recursion(graph, visited, safe, i);
        }

        vector<int> safeNodes;
        for(int i=0; i<size; i++){
            if(!visited[i]) safeNodes.push_back(i);
        }

        return safeNodes;
    }
};