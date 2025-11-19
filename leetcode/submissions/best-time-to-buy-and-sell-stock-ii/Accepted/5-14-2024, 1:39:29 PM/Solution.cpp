// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, minVal = INT_MAX;
        for (int i : prices) {
            minVal = min(minVal, i);
            int val = i - minVal;
            if (val > 0) {
                minVal = i;
                ans += val;
            }
        }
        return ans;
    }
};
