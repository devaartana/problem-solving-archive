class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n =  word1.length(), m = word2.length();

        string ans;
        ans.resize(n + m);
        for(int i = 0, j = 0, k = 0; i < n || j < m; i++, j++){
            if(i < n) ans[k++] = word1[i];
            if(j < m) ans[k++] = word2[j];
        }

        return ans;
    }
};