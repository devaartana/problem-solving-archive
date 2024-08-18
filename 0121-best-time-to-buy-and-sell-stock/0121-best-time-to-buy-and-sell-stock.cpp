class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0, minPrice = prices[0];
        for(int i=0; i < prices.size(); i++){
            int profit = prices[i] - minPrice;
            if(profit > maxProfit){
                maxProfit = profit;
            } 

            minPrice = min(prices[i], minPrice);
        }

        return maxProfit;
    }
};