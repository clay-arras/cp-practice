// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        profit = 0
        for index, buy in enumerate(prices):
            for sell in prices[index:]:
                if sell - buy > 0 and sell - buy > profit: 
                    profit = sell - buy
        return profit
        