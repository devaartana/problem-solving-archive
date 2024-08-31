class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> ump;

        for(int element:arr){
            ump[element]++;
        }

        vector<bool> freq(1001, false);

        for(auto it = ump.begin(); it != ump.end(); it++){
            if(freq[it->second]) return false;

            freq[it->second] = true;
        }

        return true;
    }
};