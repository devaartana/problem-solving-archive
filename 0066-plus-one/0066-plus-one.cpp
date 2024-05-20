class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();

        int temp;
        for(int i=size-1; i>=0; i--){
            digits[i]++;

            if(digits[i] < 10) break;

            digits[i] = 0;
            
            if(i==0){
                digits.push_back(1);
                rotate(digits.rbegin(), digits.rbegin() + 1, digits.rend());
            }

        }

        return digits;
    }
};