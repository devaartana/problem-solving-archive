#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        auto vecHash = [](const vector<int>& v) {
            size_t hash = 0;
            for (int i = 0; i < v.size(); i++) {
                hash ^= hash * 31 + hash + v[i];
            }
            return hash;
        };

        unordered_set<vector<int>, decltype(vecHash)> found(10, vecHash);

        vector<vector<int>> ans;
        for (int i = 0; i < nums.size() - 2; i++) {
            int j = i + 1, k = nums.size() - 1;

            while (j < k) {
                if (nums[j] + nums[k] == -nums[i] &&
                    found.find({nums[i], nums[j], nums[k]}) == found.end()) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    found.insert({nums[i], nums[j], nums[k]});
                    j++;
                } else if (nums[j] + nums[k] > -nums[i]) {
                    k--;
                } else {
                    j++;
                }
            }

            cout << endl;
        }

        return ans;
    }
};
