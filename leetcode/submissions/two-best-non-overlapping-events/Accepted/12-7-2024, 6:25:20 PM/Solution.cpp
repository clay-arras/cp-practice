// https://leetcode.com/problems/two-best-non-overlapping-events

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        priority_queue<pair<int, int>> pq;

        int N = (int)events.size();
        vector<int> m(N);
        iota(m.begin(), m.end(), 0);
        sort(m.begin(), m.end(), [&](const int a, const int b) {
            return events[a][1] < events[b][1];
        });

        for (int i=0; i<N; i++) 
            pq.push({events[m[i]][2], m[i]});

        int ans = 0;
        for (int i=0; i<N; i++) {
            int sum = events[m[i]][2];
            while (!pq.empty() && events[m[i]][1] >= events[pq.top().second][0]) 
                pq.pop();

            if (!pq.empty())
                sum += pq.top().first;
            ans = max(ans, sum);
        }
        return ans;
    }
};