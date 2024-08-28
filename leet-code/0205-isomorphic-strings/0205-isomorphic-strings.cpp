class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> lastIndexS(256, -1);
        vector<int> lastIndexT(256, -1);

        for(int i = 0; i < s.length(); i++){
            if(lastIndexS[s[i]] != lastIndexT[t[i]]) {
                cout << i;
                return false;
            }
            lastIndexS[s[i]] = i;
            lastIndexT[t[i]] = i;
        }

        return true;
    }
};