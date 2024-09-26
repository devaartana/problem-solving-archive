class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        unordered_map<int, int> ump;

        vector<int> sorted = score;
        sort(sorted.begin(), sorted.end(), greater<int>());
        for(int i = 0; i < sorted.size(); i++) {
            cout << sorted[i] << " ";
            ump[sorted[i]] = i;
        }

        vector<string> rank = {"Gold Medal","Silver Medal","Bronze Medal"};
        vector<string> ans(score.size());
        for(int i = 0; i < score.size(); i++){
            if(ump[score[i]] < 3) ans[i] = (rank[ump[score[i]]]);
            else ans[i] = (to_string(ump[score[i]] + 1)); 
        }

        return ans;
    }
};