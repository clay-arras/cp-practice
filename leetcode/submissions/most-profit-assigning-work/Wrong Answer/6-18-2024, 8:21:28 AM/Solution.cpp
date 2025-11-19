// https://leetcode.com/problems/most-profit-assigning-work

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int N = (int)profit.size(), M = (int)worker.size();
        vector<pair<int, int>> jobs;
        for (int i=0; i<N; i++)
            jobs.push_back({difficulty[i], profit[i]});
        
        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());
        int ans = 0;
        priority_queue<int> pq;
        pq.push(0);
        for (int i=0, ptr=0; i<M && ptr<N; i++) {
            while (ptr < N && worker[i] >= jobs[ptr].first) {
                pq.push(jobs[ptr].second);
                ptr++;
            }
            ans += pq.top();
        }

        return ans;
    }
};