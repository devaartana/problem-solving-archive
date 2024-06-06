class Solution {
public:
    int hammingWeight(int n) {
        if(!n) return 0;

        return n%2 + hammingWeight(n/2);
    }
};