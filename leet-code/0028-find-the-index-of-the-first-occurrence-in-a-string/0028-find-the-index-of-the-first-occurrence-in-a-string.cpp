class Solution {
public:
    int strStr(string haystack, string needle) {
        int a = size(haystack), b = size(needle);

        if( b > a){
            return -1;
        }       

        int j;
        for(int i=0; i<a; i++){
            if(haystack[i] == needle[0]){
                for(j=0; j<b; j++){
                    if(haystack[i+j] != needle[j]) break;
                }

                if(j == b) return i;
            }
        }

        return -1;
    }
};