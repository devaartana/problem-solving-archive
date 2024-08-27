class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<bool> appear(1001, false), inAns(1001, false);
        vector<int> ans;

        for(int num:nums1){
            appear[num] = true;
        }

        for(int num:nums2){
            if(appear[num] && !inAns[num]) {
                inAns[num] = true;
                ans.push_back(num);
            }
        }

        return ans;
    }
};