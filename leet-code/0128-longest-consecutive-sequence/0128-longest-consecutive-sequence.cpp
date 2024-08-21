class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> ust;
        for(int num:nums){
            ust.insert(num);
        }

        int ans = 0;
        for(int num:nums){
            if(ust.find(num - 1) == ust.end()){
                int length = 1;
                while(ust.find(length + num) != ust.end()) length++;

                ans = max(length, ans);
            }
        }

        return ans;
    }
};