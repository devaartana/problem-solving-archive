class Solution {
public:

    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();

        vector<int> minCost(size, 0);
        minCost[0] = cost[0];
        minCost[1] = cost[1];
    
        for(int i=2; i<size; i++){
            minCost[i] = cost[i] + min(minCost[i-1], minCost[i-2]);
        }

        return min(minCost[cost.size() - 1], minCost[cost.size() - 2]);
    }
};