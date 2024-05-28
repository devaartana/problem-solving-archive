class Solution {
public:
    int addDigits(int num) {
        
        int sum = num, mem;

        while(sum > 9){
            mem = sum;
            sum = 0;

            while(mem > 0){
                sum += mem%10;
                mem /= 10;
            } 

        }
        
        return sum;
    }
};