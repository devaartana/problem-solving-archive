class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> ump;
        vector<vector<string>> ans;

        int i = 0;
        for (string str : strs) {
            sort(str.begin(), str.end());
            auto result = ump.find(str);
            if (result != ump.end()) {
                ans[result->second].push_back(strs[i]);
            } else {
                ump[str] = ans.size();
                ans.push_back({strs[i]});
            }   
            i++;
        }

        return ans;
    }
};