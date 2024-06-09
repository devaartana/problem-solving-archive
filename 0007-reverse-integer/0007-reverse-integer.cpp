class Solution {
public:
    
    int reverse(int x) {
        int reversed = 0, count = 0;

        while(x != 0){
            count++;
            reversed += x%10;
            x/=10; 

            if(count == 9) break;
            reversed *= 10;
        }

        if(count < 9) return reversed/10;
        else if(abs(reversed) > INT_MAX/10 || x > 8) return 0;

        return reversed * 10 + x;
    }
};