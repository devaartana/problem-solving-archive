class Solution {
public:
    bool isPalindrome(int x) {
        if(x == 0) return true;
        if(x < 0 || x % 10 == 0) return false;

        int reversed = 0;
        while(x > reversed){
            reversed = reversed * 10 + x%10 ;
            x/=10;
        }

        return reversed == x || reversed/10 == x;
    }
};