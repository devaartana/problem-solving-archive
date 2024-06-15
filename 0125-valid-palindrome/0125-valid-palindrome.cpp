class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.length() - 1;

        int i = 0;
        while(i < len){
            
            while(!(tolower(s[i]) >= 'a' && tolower(s[i]) <= 'z' || s[i] >= '0' && s[i] <= '9') && i < len ) i++;
            
            while(!(tolower(s[len]) >= 'a' && tolower(s[len]) <= 'z' || s[len] >= '0' && s[len] <= '9') && i < len) len--;

            if(tolower(s[i]) != tolower(s[len]) && i < len) {
                return false;
            }

            i++; len--;
        }

        return true;
    }
};