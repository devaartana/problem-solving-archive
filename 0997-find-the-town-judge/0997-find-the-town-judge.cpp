class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        if(!trust.size()) return (n > 1) ? -1 : 1;
        
        vector<int> count(n+1, 0);
        vector<bool> citizen(n+1, false);

        for(vector<int> edge:trust){
            count[edge[1]]++;
            citizen[edge[0]] = true;
        }

        int max = 0, vertex;
        for(int i=1; i <= n; i++){
            if(count[i] > max){
                vertex = i;
                max = count[i];
            }
        }

        return (!citizen[vertex] && count[vertex] == n - 1) ? vertex : -1;
    }
};