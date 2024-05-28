class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int freq[101];

        memset(freq, 0, sizeof(int) * 101);

        for(int num:nums){
            freq[num]++;
        }

        int max = 0, total = 0;

        for(int i=0; i<101; i++){
            if(freq[i] > max){
                max = total = freq[i];
            } else if(freq[i] == max){
                total += freq[i];
            }
        }    
    
        return total;
    }

};