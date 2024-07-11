class Solution {
public:

     int different(string a, string b){
        int count = 0;
        for(int i=0; i < a.length(); i++) if(a[i] != b[i]) count++;
        
        return count;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        int row = wordList.size();

        vector<bool> visited(wordList.size(), false);
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while(!q.empty()){
            auto temp = q.front();
            q.pop();

            for(int i=0; i < row; i++){
                if(!visited[i] && different(temp.first, wordList[i]) == 1){
                    if(wordList[i].compare(endWord) == 0) return temp.second + 1;

                    visited[i] = true;
                    q.push({wordList[i], temp.second+1});
                }
            }
        }

        return 0;
    }
};