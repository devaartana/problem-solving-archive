class Solution {
public:

    int countDigit(int a){
        int count = 0;
        while(a) {
            a /= 10;
            count++;
        }

        return count;
    }
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(int num:nums){
            if(!(countDigit(num)&1)) ans++;
        }

        return ans;
    }
};