// https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-ii

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        const long long MOD = 1e9+7;

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        int N = (int)nums.size();
        for (int i=0; i<N; i++)
            pq.push({nums[i], i});

        while (k--) {
            pair<long long, int> x = pq.top();
            pq.pop();
            pq.push({(x.first * 1LL * multiplier) % MOD, x.second});
        } 

        while (!pq.empty()) {
            pair<int, int> x = pq.top();
            nums[x.second] = x.first;
            pq.pop();
        }
        return nums;
    }
};