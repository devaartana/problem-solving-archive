class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> ump;
        stringstream ss1(s1), ss2(s2);
        string word;

        while(ss1 >> word) ump[word]++;
        while(ss2 >> word) ump[word]++; 
        
        vector<string> ans;
        for(auto it = ump.begin(); it != ump.end(); it++){
            if(it->second == 1) ans.push_back(it->first);
        }
        return ans;
    }
};