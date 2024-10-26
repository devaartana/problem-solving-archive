class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        
        unordered_set<int> ust;
        for(int type: candyType){
            ust.insert(type);
        }

        return min(candyType.size()/2, ust.size());
    }
};