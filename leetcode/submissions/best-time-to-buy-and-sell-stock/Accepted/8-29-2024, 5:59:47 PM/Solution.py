// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_profit = 0
        buy = prices[0]

        for price in prices:
            if price - buy > max_profit:
                max_profit = price - buy
            if price < buy:
                buy = price
            
        return max_profit
        
        