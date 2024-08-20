class Solution {
public:
    void reverseString(vector<char>& s) {
        char temp;
        int length = s.size();
        for(int i = 0; i < length/2; i++){
            temp = s[i];
            s[i] = s[length - 1 - i];
            s[length - 1- i] = temp;
        }
    }
};