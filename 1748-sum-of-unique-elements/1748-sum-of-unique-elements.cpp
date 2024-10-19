class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> ump;
        for(int num:nums){
            ump[num]++;
        } 

        int ans = 0;
        for(auto it = ump.begin(); it != ump.end(); it++){
            if(it->second == 1) ans += it->first;
        }

        return ans;
    }
};