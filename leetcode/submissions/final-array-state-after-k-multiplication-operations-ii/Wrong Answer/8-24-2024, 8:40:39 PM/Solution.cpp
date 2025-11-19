// https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-ii

class Solution {
public:
    long long binpow(long long a, long long b, long long mod) {
        const long long MOD = 1e9+7;
        long long res = 1;
        while (b > 0) {
            if (b & 1)
                res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        const long long MOD = 1e9+7;

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        int N = (int)nums.size();
        int MX = 0;
        for (int i=0; i<N; i++) {
            pq.push({nums[i], i});
            MX = max(MX, nums[i]);
        }

        int val = 0;
        while (k--) {
            pair<long long, int> x = pq.top();
            pq.pop();
            pq.push({(x.first * 1LL * multiplier) % MOD, x.second});
            if (pq.top().first * multiplier >= MX && !val) {
                val = k / N;
                k %= N;
            }
        } 

        while (!pq.empty()) {
            pair<int, int> x = pq.top();
            nums[x.second] = ((x.first*1LL*binpow(multiplier, val, MOD))%MOD);
            pq.pop();
        }
        return nums;
    }
};