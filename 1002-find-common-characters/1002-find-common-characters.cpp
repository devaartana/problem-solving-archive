class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> bound(26, 0);

        for(char c:words[0]){
            bound[c - 'a']++;
        }

        for(int i = 1; i < words.size(); i++){
            vector<int> tempFreq(26, 0);
            for(int j = 0; j < words[i].length(); j++){
                tempFreq[words[i][j] - 'a']++;
            }

            for(int j = 0; j < 26; j++){
                if(!tempFreq[j] || !bound[j]){
                    bound[j] = 0;
                }else if(tempFreq[j] && bound[j]){
                    bound[j] = min(tempFreq[j], bound[j]);
                }
            }
        }

        vector<string> ans;
        for(int i = 0 ; i < 26; i++){
            if(bound[i]){
                cout << bound[i] << " ";
                for(int j = 0; j < bound[i]; j++){
                    ans.push_back(string(1, i + 'a'));
                }
            }
        }

        return ans;
    }
};