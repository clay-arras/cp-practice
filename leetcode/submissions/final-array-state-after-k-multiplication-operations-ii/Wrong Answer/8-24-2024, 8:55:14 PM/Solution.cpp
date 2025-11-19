// https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-ii

class Solution {
public:
    long long binpow(long long a, long long b, long long m) {
        a %= m;
        long long res = 1;
        while (b > 0) {
            if (b & 1)
                res = res * a % m;
            a = a * a % m;
            b >>= 1;
        }
        return res;
    }

    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        const long long MOD = 1e9+7;

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        long long N = (int)nums.size();
        long long MX = 0;
        for (int i=0; i<N; i++) {
            pq.push({nums[i], i});
            MX = max(MX, 1LL*nums[i]);
        }

        long long val = 0;
        for (int i=0; i<k; i++) {
            if (pq.top().first * 1LL * multiplier >= MX && !val) {
                val = k / N;
                k = k % N;
            }
            if (i >= k)
                break;
            pair<long long, int> x = pq.top();
            pq.pop();
            pq.push({(x.first * 1LL * multiplier) % MOD, x.second});
            MX = max(MX, (x.first * 1LL * multiplier) % MOD);
        } 

        while (!pq.empty()) {
            pair<long long, int> x = pq.top();
            nums[x.second] = ((((x.first*1LL)%MOD)*binpow(multiplier, val, MOD))%MOD);
            pq.pop();
        }
        return nums;
    }
};