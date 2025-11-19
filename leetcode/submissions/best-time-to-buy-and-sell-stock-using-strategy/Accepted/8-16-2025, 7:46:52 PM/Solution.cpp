// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-using-strategy

class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        // step 1: return base cost
        // step 4: sliding window? 

        int N = (int)prices.size();
        long long ans = 0, roll = 0;
        for (int i=0; i<N; i++) {
            ans += prices[i] * 1LL * strategy[i];
            if (i < k) {
                roll += (i < k/2 ? 0 : 1) * 1LL * prices[i];
            } else {
                roll += prices[i] * 1LL * strategy[i];
            }
        }
        cout << roll << endl;
        ans = max(roll, ans);
        
        for (int i=k; i<N; i++) {
            roll += prices[i-k] * 1LL * strategy[i-k];
            roll -= prices[i-k/2];
            roll += prices[i] - (prices[i] * 1LL * strategy[i]);
                 
            cout << roll << endl;
            ans = max(roll, ans);
        }
        return ans;
    }
};