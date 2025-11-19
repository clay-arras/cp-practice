// https://leetcode.com/problems/non-overlapping-intervals

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
            [&](const vector<int>& x, const vector<int>& y) {
                if (x[1] == y[1])
                    return x[0] < y[0];
                return x[1] < y[1];
            });

        int N = (int)intervals.size();
        int ans = 0;
        vector<int> prev = intervals[0];
        for (int i = 1; i < N; i++) {
            if (intervals[i][0] < prev[1]) {
                ans++;
            } else {
                prev = intervals[i];
            }
        }
        return ans;
    }
};