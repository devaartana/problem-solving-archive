class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<bool> appear(nums.size());

        for(int num:nums){
            appear[num - 1] = true;
        }

        vector<int> ans;
        for(int i=0; i < nums.size(); i++){
            if(appear[i] == false) ans.push_back(i + 1);
        }

        return ans;
    }
};