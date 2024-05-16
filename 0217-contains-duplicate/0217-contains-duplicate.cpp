class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> freq;
        int size = nums.size();
        for(int i=0; i < size; i++){

            if(freq.find(nums[i]) != freq.end()) return true;

            freq.insert(nums[i]);
        }
    
        return false;
    }
};