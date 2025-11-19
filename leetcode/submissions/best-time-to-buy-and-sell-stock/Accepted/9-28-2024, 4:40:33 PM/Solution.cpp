// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int diff = 0;
        int firstDay = 0;
        for (int i = 0; i < prices.size(); i++) 
        {
            if (prices[i] < prices[firstDay])
            {
                firstDay = i;
            }
            else if (prices[i] - prices[firstDay] > diff)
            {
                diff = prices[i] - prices[firstDay];
            }
        }
        return diff;
    }
};