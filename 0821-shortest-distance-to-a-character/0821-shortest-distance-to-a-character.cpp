class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> dis(s.length(), INT_MAX);
        vector<int> base;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == c) base.push_back(i);
        }

        for(int i = 0, j = 0; i < s.length(); i++){
            
            if(abs(i - base[j]) < dis[i]) dis[i] = abs(i - base[j]);


            if(j + 1 < base.size() && abs(i - base[j + 1]) < dis[i]) {
                dis[i] = abs(i - base[j + 1]);
                j++;
            }
        }
        
        return dis;
    }
};