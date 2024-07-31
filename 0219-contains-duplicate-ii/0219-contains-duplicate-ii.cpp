class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> discovered;

        for(int i=0; i<nums.size(); i++){
            if(discovered[nums[i]] && abs(i + 1 - discovered[nums[i]]) <= k){
                return true;
            }

            discovered[nums[i]] = i + 1;
        }

        return false;
    }
};