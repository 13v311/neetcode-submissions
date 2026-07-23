class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int maxProfit = 0;
       int p = 0;
       for(size_t i = 1; i < prices.size(); i++) {
            int currProfit = prices[i] - prices[p];
            if(currProfit > maxProfit) {
                maxProfit = currProfit;
            }

            if(prices[p] > prices[i]) {
                p = i;
            }
       }
       return maxProfit;
    }
};
