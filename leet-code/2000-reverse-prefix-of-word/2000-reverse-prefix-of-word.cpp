class Solution {
public:
    string reversePrefix(string word, char ch) {
        for(int i=0; i<size(word); i++){
            if(word[i] == ch){

                char temp;
                for(int j=0; j<=i/2; j++){
                    temp = word[j];
                    word[j] = word[i-j];
                    word[i-j] = temp;
                }

                return word;
            }
        }

        return word;
    }

};