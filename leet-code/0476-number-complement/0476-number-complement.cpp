class Solution {
public:
    int findComplement(int num) {
    
        long long ans = 0, power = 1;
        while(num) {
            ans += ((num%2) ? 0 : 1) * power;
            num /= 2;
            power *= 2;
        }

        return ans;
    }
};