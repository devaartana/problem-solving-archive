class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morseCode = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

        unordered_set<string> ust;
        for(string word:words){
            string temp = "";

            for(char c:word){
                temp += morseCode[c - 'a'];
            }

            ust.insert(temp);
        }

        return ust.size();
    }
};