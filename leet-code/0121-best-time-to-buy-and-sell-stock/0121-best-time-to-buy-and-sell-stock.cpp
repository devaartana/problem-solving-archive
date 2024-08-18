class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0, minPrice = INT_MAX;
        for(int i=0; i < prices.size(); i++){
            int profit = prices[i] - minPrice;
            minPrice = min(prices[i], minPrice);
            maxProfit = max(profit, maxProfit);
        }

        return maxProfit;
    }
};