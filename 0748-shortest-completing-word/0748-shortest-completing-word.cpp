class Solution {
public:
    void countFreq(vector<int> &result, string &target){
        char temp;
        for(char c:target){
            temp = tolower(c);
            if(temp >= 'a' && temp < 'z') {
                result[temp - 'a']++;
            }
        }
    }

    bool isValid(vector<int> &target, vector<int> &base){
        
        for(int i = 0; i < 26; i++){
            if(base[i] && target[i] - base[i] < 0) return false;
        }

        return true;
    }

    string shortestCompletingWord(string licensePlate, vector<string>& words) {
    
        vector<int> licensePlateFreq(26, 0);
        countFreq(licensePlateFreq, licensePlate);

        int ans = 0, minLength = INT_MAX;
        for(int i = 0; i < words.size(); i++){
            vector<int> freq(26, 0);

            countFreq(freq, words[i]);     
            if(isValid(freq, licensePlateFreq) && words[i].length() < minLength) {
                ans = i;
                minLength = words[i].length();
            } 
        }


        return words[ans];
    }
};