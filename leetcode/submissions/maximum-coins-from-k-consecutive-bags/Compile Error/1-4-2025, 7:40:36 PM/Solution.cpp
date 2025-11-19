// https://leetcode.com/problems/maximum-coins-from-k-consecutive-bags

class Solution {
public:
    long long maximumCoins(vector<vector<int>>& coins, int k) {
        // line sweep, at each point get max of forward and backwards??
        // map<int, int> line;
        // for (auto &i : coins) {
        //     line[i[0]] += i[2];
        //     line[i[1]] -= i[2];
        // }
        int N = (int)coins.size();
        sort(coins.begin(), coins.end());
        queue<vector<int>> q;
        long long ans = 0, sum = 0;
        for (int i=0; i<N; i++) {
            while (!q.empty() && coins[i][1] - k >= q.front()[1]) {
                sum -= 1LL * q.front()[2] * (q.front()[1] - q.front()[0] + 1);
                q.pop();
            }
            sum += 1LL * coins[i][2] * ((coins[i][1] - coins[i][0] + 1));
            q.push(coins[i]);
            ans = max(ans, sum - max(0, (1LL * coins[i][1] - k - q.front()[0] + 1) * q.front()[2]));
        }

        q = queue<vector<int>>();
        sum = 0;
        for (int i=N-1; i>=0; i--) {
            while (!q.empty() && coins[i][0] + k <= q.front()[0]) {
                sum -= 1LL * q.front()[2] * (q.front()[1] - q.front()[0] + 1);
                q.pop();
            }
            sum += 1LL * coins[i][2] * ((coins[i][1] - coins[i][0] + 1));
            q.push(coins[i]);
            ans = max(ans, sum - max(0, (1LL * q.front()[1] - (coins[i][0] + k) + 1) * q.front()[2]));
        }
        return ans;
    }
};