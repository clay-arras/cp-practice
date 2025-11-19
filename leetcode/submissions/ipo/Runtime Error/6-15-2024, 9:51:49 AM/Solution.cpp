// https://leetcode.com/problems/ipo

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int N = (int)profits.size();
        vector<pair<int, int>> a;
        priority_queue<pair<int, int>> pq;

        for (int i=0; i<N; i++)
            a.push_back({capital[i], -profits[i]});
        sort(a.begin(), a.end());

        int ans = w;
        for (int i=0, ptr=0; i<k; i++) {
            for (; ptr < N && ans >= a[ptr].first; ptr++) 
                pq.push({-a[ptr].second, a[ptr].first});
            auto x = pq.top(); pq.pop();
            ans += x.first;
        }

        return ans;
    }
};