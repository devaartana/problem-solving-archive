class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        
        int ans = 0;
        for(int i = 0; i < timeSeries.size() - 1; i++){
            if(timeSeries[i] + duration < timeSeries[i+1]) ans += duration;
            else ans += timeSeries[i+1] - timeSeries[i]; 
        }

        return ans + duration;
    }
};