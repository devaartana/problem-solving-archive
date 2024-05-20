class Solution {
public:

    bool dfs_recursion( vector<vector<int>>& graph, vector<bool> &visited, int start){

        visited[start] = true;

        for(auto vertex:graph[start]){
            
            if(visited[vertex]) return false;
            
            if(!dfs_recursion(graph, visited, vertex)){
                return false;
            }    
        }

        visited[start] = false;
        
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int size = graph.size();
        vector<bool> visited(size, false);

        for(int i=0; i<size; i++){
            if(graph[i].empty()) continue;

            if(!visited[i]) dfs_recursion(graph, visited, i);
        }

        vector<int> safeNodes;
        for(int i=0; i<size; i++){
            if(!visited[i]) safeNodes.push_back(i);
        }

        return safeNodes;
    }
};