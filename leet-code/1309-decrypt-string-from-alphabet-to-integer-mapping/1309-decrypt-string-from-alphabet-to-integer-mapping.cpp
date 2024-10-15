class Solution {
public:
    string freqAlphabets(string s) {
        string ans;
        
        for(int i = s.length() - 1; i >= 0; i--) {
            if(s[i] == '#') {
                int num = stoi(s.substr(i - 2, 2));
                ans.push_back('a' + num - 1);
                i -= 2;
            } else {
                int num = s[i] - '0';
                ans.push_back('a' + num - 1);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
