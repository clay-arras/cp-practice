// https://leetcode.com/problems/non-overlapping-intervals

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        int N = (int)intervals.size();
        int ans = 0;
        vector<int> prev = intervals[0];
        for (int i=1; i<N; i++) {
            if (intervals[i][0] < prev[1]) {
                ans++;
            } else {
                prev = intervals[i];
            }
        }
        return ans;
    }
};