// https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>> pq;
        int N = (int)nums.size();
        for (int i=0; i<N; i++)
            pq.push({-nums[i], -i});

        while (k--) {
            pair<int, int> x = pq.top();
            pq.pop();
            pq.push({x.first * multiplier, x.second});
        } 

        while (!pq.empty()) {
            pair<int, int> x = pq.top();
            nums[-x.second] = -x.first;
            pq.pop();
        }
        return nums;
    }
};