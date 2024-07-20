class Solution {
public:
    vector<int> tab = vector<int>(46, 0);

    int climbStairs(int n) {
        if(n == 0) return 1;
        else if(n < 0) return 0;
        else if(tab[n]) return tab[n];

        return tab[n] = climbStairs(n-1) + climbStairs(n-2);
    }
};