// https://leetcode.com/problems/maximum-area-rectangle-with-point-constraints-i

class Solution {
public:
    int maxRectangleArea(vector<vector<int>>& points) {
        // need two points to define a rectangle
        // have map exists where it returns if that exists 
        // function inside

        map<vector<int>, bool> exist;
        for (auto i : points)
            exist[i] = true;
        const auto in = [&](vector<int> a, vector<int> b, vector<int> c) {
            int xmx = max(a[0], b[0]), ymx = max(a[1], b[1]);
            int xmn = min(a[0], b[0]), ymn = min(a[1], b[1]);

            bool ok1 = (c[0] <= xmx && c[0] >= xmn);
            bool ok2 = (c[1] <= ymx && c[1] >= ymn);
            return ok1 && ok2;
        };
        const auto area = [&](vector<int> a, vector<int> b) {
            int xmx = max(a[0], b[0]), ymx = max(a[1], b[1]);
            int xmn = min(a[0], b[0]), ymn = min(a[1], b[1]);

            return (xmx - xmn) * (ymx - ymn);
        };

        int ans = -1;
        int N = (int)points.size();
        for (int i=0; i<N; i++) {
            for (int j=i+1; j<N; j++) {
                set<vector<int>> pts = {points[i], points[j], {points[i][0], points[j][1]}, {points[j][0], points[i][1]}};
                bool ok = true;
                for (int k=0; k<N; k++) {
                    if (!pts.count(points[k]))
                        ok &= !in(points[i], points[j], points[k]);
                }
                if (exist[{points[i][0], points[j][1]}] && exist[{points[j][0], points[i][1]}] && ok) {
                    ans = max(ans, area(points[i], points[j]));
                }
            }
        }

        return (ans ? ans : -1);
    }
};