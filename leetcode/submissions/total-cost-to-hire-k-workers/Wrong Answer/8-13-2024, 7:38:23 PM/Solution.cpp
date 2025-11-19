// https://leetcode.com/problems/total-cost-to-hire-k-workers

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int> lq, rq;

        int N = (int)costs.size(), ans = 0;
        int l=0, r=N-1;
        for (int i=0; i<k; i++) {
            while ((int)lq.size() < candidates && l <= r) 
                lq.push(-costs[l++]);
            while ((int)rq.size() < candidates && l <= r) 
                rq.push(-costs[r--]);
            
            cout << (int)lq.size() << " " << (int)rq.size() << endl;
            // cout << (int)lq.top() << " " << (int)rq.top() << endl;
            cout << endl;
            if (rq.empty() || -lq.top() <= -rq.top()) {
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