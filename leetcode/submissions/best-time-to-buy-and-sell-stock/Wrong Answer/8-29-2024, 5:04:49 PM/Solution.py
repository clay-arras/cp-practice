// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        buy = prices[0]
        buy_day = 0
        try: 
            sell = prices[1]
        except IndexError:
            return 0
        sell_day = 1
        for day, price in enumerate(prices[1:]):
            if price >= sell:
                sell = price
                sell_day = day+1
        
        print(sell_day, sell)
        
        for day, price in enumerate(prices):
            if price < buy and day < sell_day:
                buy = price
                buy_day = day

        print(buy_day, buy)
            
                
        return max(sell - buy, 0)
        