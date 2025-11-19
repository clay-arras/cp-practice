// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<int> buy(k, -INT_MAX), sell(k, -INT_MAX);
        for (int i=0, N=(int)prices.size(); i<N; i++) {
            buy[0] = max(buy[0], -prices[i]);
            sell[0] = max(sell[0], buy[0]+prices[i]);
            for (int j=1; j<k; j++) {
                buy[j] = max(buy[j], sell[j-1]-prices[i]);
                sell[j] = max(sell[j], buy[j]+prices[i]);
            }
        }
        return sell[k-1];
    }
};