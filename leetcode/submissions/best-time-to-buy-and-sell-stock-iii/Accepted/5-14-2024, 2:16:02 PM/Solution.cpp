// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int N = (int)prices.size();

        vector<int> arr(N), diff(N+1);
        for (int i=N-1, maxVal=-INT_MAX; i>=0; i--) {
            maxVal = max(maxVal, prices[i]);
            arr[i] = maxVal;
        }
        for (int i=N-1, maxVal=-INT_MAX; i>=0; i--) {
            maxVal = max(maxVal, arr[i] - prices[i]);
            diff[i] = maxVal;
        }

        int ans = 0;
        for (int i=0, minVal=INT_MAX; i<N; i++) {
            minVal = min(minVal, prices[i]);
            ans = max(ans, prices[i] - minVal + diff[i+1]);
        }

        return ans;
    }
};