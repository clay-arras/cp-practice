// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int N = (int)prices.size();

        vector<int> arr(N);
        int maxVal = -INT_MAX;
        for (int i=N-1; i>=0; i--) {
            maxVal = max(maxVal, prices[i]);
            arr[i] = maxVal;
        }
        vector<int> diff(N+1, 0);
        for (int i=0; i<N; i++)
            diff[i] = arr[i] - prices[i];
        maxVal = -INT_MAX;
        for (int i=N-1; i>=0; i--) {
            maxVal = max(maxVal, diff[i]);
            diff[i] = maxVal;
        }

        int ans = 0, minVal = INT_MAX;
        for (int i=0; i<N; i++) {
            minVal = min(minVal, prices[i]);
            ans = max(ans, prices[i] - minVal + diff[i+1]);
        }

        return ans;
    }
};