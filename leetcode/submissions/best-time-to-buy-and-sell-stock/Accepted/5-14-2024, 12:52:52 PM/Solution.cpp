// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, minVal = INT_MAX;
        for (auto i : prices) {
            minVal = min(minVal, i);
            ans = max(ans, i - minVal);
        }
        return ans;
    }
};