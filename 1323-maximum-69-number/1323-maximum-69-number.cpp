class Solution {
public:
    int maximum69Number (int num) {
        
        int lastSix = 0, length = 1;
        for(int it = num; it; it/=10, length++){
            if(it%10 == 6) lastSix = length;
        }

        int ans = 0, ten = 1;
        for(int it = num, length = 1; it; it/=10, ten*=10, length++){
            if(length == lastSix) ans += 9 * ten;
            else ans += (it%10) * ten;
        }

        return ans;
    }
};