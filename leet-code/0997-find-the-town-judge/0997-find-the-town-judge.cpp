class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
           
        vector<int> count(n+1, 0);
        for(vector<int> edge:trust){
            count[edge[1]]++;
            count[edge[0]]--;
        }

        for(int vertex = 1; vertex <= n; vertex++){
            if(count[vertex] == n - 1) return vertex;
        }

        return -1;
    }
};