// https://leetcode.com/problems/count-number-of-trapezoids-ii

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        // naive solution: n^4, 6e10
        // possible solutions: n^2logn, n^3

        auto sl = [](vector<int>& a, vector<int>& b) {
            return (a[1] - b[1]) * 1.0L / (a[0] - b[0]);
        };
        auto cross = [&](int i, int j, int k, int m) {
            auto i0 = points[i];
            auto j0 = points[j];
            auto k0 = points[k];
            auto m0 = points[m];
            return (i0[1] - j0[1]) * (k0[0] - m0[0]) == 
                   (i0[0] - j0[0]) * (k0[1] - m0[1]);
        };
        auto ok = [&](int i, int j, int k, int m) {
            if (cross(i, j, k, m))
                return true;
            if (cross(i, k, j, m))
                return true;
            if (cross(i, m, j, k))
                return true;
            return false;
        };

        int N = (int)points.size();
        int sum = 0;
        for (int i=0; i<N; i++) {
            for (int j=i+1; j<N; j++) {
                for (int k=j+1; k<N; k++) {
                    for (int m=k+1; m<N; m++) {
                        sum += ok(i, j, k, m);
                    }
                }
            }
        }

        return sum;
    }
};