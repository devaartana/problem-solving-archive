class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        int edgeCount = edges.size();
        vector<vector<pair<int, double>>> adjList(n);
        for(int i=0; i<n; i++){
            adjList[i] = {}; 
        }

        vector<bool> visited(n, false);

        for(int i=0; i < edgeCount; i++){
            adjList[edges[i][0]].push_back(make_pair(edges[i][1], succProb[i]));
            adjList[edges[i][1]].push_back(make_pair(edges[i][0], succProb[i]));
        }

        priority_queue<pair<double, int>> pq;
        succProb = vector<double>(n, 0.0);
        
        pq.push(make_pair(1.0, start_node));
        succProb[start_node] = 1.0;

        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();

            visited[temp.second] = true;

            for(auto vertex:adjList[temp.second]){
                int nextVertex = vertex.first;
                double prob = vertex.second;

                if(!visited[nextVertex]){

                    double probRil = temp.first * prob;
                    if(probRil > succProb[nextVertex]) {
                        succProb[nextVertex] = probRil;
                        pq.push(make_pair(probRil, nextVertex));
                    }
                }
            }

        }

        return succProb[end_node];
    }
};