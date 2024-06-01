class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        vector<bool> type(60, false);

        int sj = jewels.size(), ss = stones.size();
        for(int i=0; i < sj; i++){
            type[jewels[i] - 'A'] = true;
        }

        int count=0;
        for(int i=0; i<ss; i++){
            if (type[stones[i] - 'A'])count++;
        }

        return count;
    }
};