class Solution {
public:

    int different(string a, string b){
        int count = 0;
        for(int i=0; i < 8; i++) if(a[i] != b[i]) count++;
        
        return count;
    }
    int minMutation(string startGene, string endGene, vector<string>& bank) {

        int row = bank.size();

        map<string, bool> visited;
        queue<pair<string, int>> q;
        q.push({startGene, 0});
        visited[startGene] = true;

        while(!q.empty()){
            auto temp = q.front();
            q.pop();

            for(int i=0; i<row; i++){
               if(!visited[bank[i]] && different(temp.first, bank[i]) == 1){
                    if(bank[i].compare(endGene) == 0) return temp.second + 1;

                    visited[bank[i]] = true;
                    q.push({bank[i], temp.second + 1});
               } 
            }
        }    

        return -1;
    }
};