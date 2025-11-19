// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(),
             [&](const vector<int>& x, const vector<int>& y) {
                 if (x[1] == y[1])
                     return x[0] < y[0];
                 return x[1] < y[1];
             });

        int N = (int)points.size();
        int ans = 0;
        vector<int> prev = points[0];
        for (int i=1; i<N; i++) {
            if (points[i][0] <= prev[1]) {
                ans++;
            } else {
                prev = points[i];
            }
        }
        return N - ans;
    }
};