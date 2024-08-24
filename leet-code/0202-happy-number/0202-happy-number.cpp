class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> ust;

        int sum, temp;
        while(n != 1){
            sum  = 0;
            while(n){
                temp = n % 10;
                sum += temp * temp;
                n /= 10;
            }

            if(ust.find(sum) != ust.end()) return false;
            
            ust.insert(sum);
            n = sum;
        }

        return true;
    }
};