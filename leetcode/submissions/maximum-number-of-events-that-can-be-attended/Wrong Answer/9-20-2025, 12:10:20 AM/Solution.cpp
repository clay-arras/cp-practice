// https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[1] == b[1])
                return a[0] < b[0];
            return a[1] < b[1];
        });

        int ans = 0;
        int t = 0;
        int N = (int)events.size();
        for (int i=0; i<N; i++) {
            if (t <= events[i][1]) {
                ans++;
                t = max(t, events[i][0]);
                t++;
            }
        }

        return ans;
    }
};