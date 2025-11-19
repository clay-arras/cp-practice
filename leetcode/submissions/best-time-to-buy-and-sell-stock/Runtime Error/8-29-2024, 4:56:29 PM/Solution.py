// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        buy = prices[0]
        buy_day = 0
        sell = prices[1]
        sell_day = 1
        profit = 0
        for day, price in enumerate(prices):
            if price > sell and day > buy_day:
                sell = price
                sell_day = day
        
        for day, price in enumerate(prices):
            if price < buy and day < sell_day:
                buy = price
                buy_day = day
            
                
        return max(sell - buy, 0)
        