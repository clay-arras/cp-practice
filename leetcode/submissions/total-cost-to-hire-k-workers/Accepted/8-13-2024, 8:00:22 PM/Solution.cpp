// https://leetcode.com/problems/total-cost-to-hire-k-workers

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int> lq, rq;

        long long N = (int)costs.size(), ans = 0;
        int l=0, r=N-1;
        for (int i=0; i<k; i++) {
            while ((int)lq.size() < candidates && l <= r) 
                lq.push(-costs[l++]);
            while ((int)rq.size() < candidates && l <= r) 
                rq.push(-costs[r--]);
            
            if ((lq.empty() ? INT_MAX : -lq.top()) <= (rq.empty() ? INT_MAX : -rq.top())) {
                ans += -lq.top();
                lq.pop();
            } else {
                ans += -rq.top();
                rq.pop();
            }
        }
        return ans;
    }
};