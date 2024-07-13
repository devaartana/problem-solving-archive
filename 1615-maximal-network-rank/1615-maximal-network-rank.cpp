class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<bool>> adjMatrix(n, vector<bool>(n, false));
        vector<int> count(n, 0);
        for(auto edge:roads){
            adjMatrix[edge[0]][edge[1]] = adjMatrix[edge[1]][edge[0]] = true;
            count[edge[0]]++;
            count[edge[1]]++; 
        }

        int maxNetwork = 0, sum;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i != j){
                    sum = count[i] + count[j] - adjMatrix[i][j] * 1;
                    if(sum > maxNetwork) maxNetwork = sum;
                }
            }
        }

        return maxNetwork;
    }
};