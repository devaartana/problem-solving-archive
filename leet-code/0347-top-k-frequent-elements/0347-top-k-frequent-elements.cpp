class Solution {
public:
    static bool compare(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> ump;

        for (int num : nums) {
            ump[num]++;
        }

        vector<pair<int, int>> freq(ump.begin(), ump.end());
        sort(freq.begin(), freq.end(), compare);

        vector<int> ans(k);
        for (int i = 0; i < k; i++) {
            ans[i] = freq[i].first;
        }
        return ans;
    }
};