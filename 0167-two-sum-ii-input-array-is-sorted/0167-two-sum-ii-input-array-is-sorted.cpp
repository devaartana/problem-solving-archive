class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lo = 0, hi = numbers.size() - 1, sum;

        while(lo < hi){
            sum = numbers[lo] + numbers[hi];
            if(sum > target) hi--;
            else if(sum < target) lo++; 
            else return {lo + 1, hi + 1};
        }

        return {-1};
    }
};