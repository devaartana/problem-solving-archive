class Solution {
public:
    vector<vector<int>> al, critical_connections;
    vector<bool> visited;
    vector<int> ids, lowlinks;
    int i = 1;

    void tarjans(int start, int parent){
        visited[start] = true;

        lowlinks[start] = ids[start] = i++;

        for(int vertex:al[start]){
            if(vertex == parent) continue;

            if(!visited[vertex]){
                tarjans(vertex, start);

                lowlinks[start] = min(lowlinks[start], lowlinks[vertex]);

                if(ids[start] < lowlinks[vertex]){
                    critical_connections.push_back({start, vertex});
                }
            } else {
                lowlinks[start] = min(lowlinks[start], lowlinks[vertex]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        al = vector<vector<int>>(n, vector<int>());
        visited = vector<bool>(n, false);
        lowlinks = ids = vector<int>(n, 0);
        
        for(auto edge:connections){
            al[edge[0]].push_back(edge[1]);
            al[edge[1]].push_back(edge[0]);
        }    

        for(int i=0; i<n; i++){
            if(!visited[i]){
                tarjans(i, -1);
            }
        }
        return critical_connections;
    }
};