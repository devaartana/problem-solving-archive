class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 0, divisor = 1;

        while(divisor < num / divisor){
            if(!(num%divisor)){
                sum += divisor + num/divisor;
            } 

            divisor++;
        }
        return sum - num == num;
    }
};