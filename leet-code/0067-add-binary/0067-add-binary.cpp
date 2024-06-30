class Solution {
public:    
    string add(string a, string b, int i, int j) {
        bool carry = false;
        int sum;
        string result;

        while (i >= 0 || carry) {
            
            sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';

            result.push_back(sum % 2 + '0');
            carry = sum > 1;
        }

        reverse(result.begin(), result.end());
        return result;
    }

    string addBinary(string a, string b) {

         int i = a.size()-1, j = b.size()-1;

        if(i >= j) return add(a, b, i, j);
        
        return add(b, a, j, i);      
    }   
};