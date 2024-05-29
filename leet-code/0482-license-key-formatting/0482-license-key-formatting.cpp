class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int count = 0, size = s.size();
        string result;
        
        for(int i = size - 1; i >= 0; i--){
            if(s[i] != '-'){

                if(count == k) {
                    count = 0;
                    result.push_back('-');
                }

                result.push_back(toupper(s[i]));
                count++;
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }
};