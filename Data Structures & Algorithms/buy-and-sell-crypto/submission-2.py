class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        lowest = prices[0]
        maxProfit = 0

        for i in range(1, len(prices)):
            if(lowest < prices[i]):
                maxProfit = max(maxProfit, prices[i]-lowest)
            if(lowest > prices[i]):
                lowest = prices[i]
        return maxProfit