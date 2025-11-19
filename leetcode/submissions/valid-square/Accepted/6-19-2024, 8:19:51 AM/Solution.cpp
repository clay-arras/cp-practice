// https://leetcode.com/problems/valid-square

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3,
                     vector<int>& p4) {
        vector<vector<int>> a = {p1, p2, p3, p4};
        sort(a.begin(), a.end());

        auto dist = [](vector<int> a, vector<int> b) {
            return (a[0] - b[0]) * (a[0] - b[0]) +
                   (a[1] - b[1]) * (a[1] - b[1]);
        };
        auto dot = [](vector<int> a, vector<int> b) {
            return (a[0] * b[0]) + (a[1] * b[1]);
        };
        auto subtr = [](vector<int> a, vector<int> b) -> vector<int> {
            return {(a[0] - b[0]), (a[1] - b[1])};
        };

        bool ans = true;
        ans &= (dist(a[0], a[1]) == dist(a[0], a[2]) &&
                dist(a[0], a[2]) == dist(a[3], a[1]) &&
                dist(a[3], a[1]) == dist(a[3], a[2]));
        ans &= (dot(subtr(a[0], a[3]), subtr(a[1], a[2])) == 0);
        ans &= (dot(subtr(a[0], a[1]), subtr(a[0], a[2])) == 0);
        ans &= (a[0] != a[1] && a[1] != a[2] && a[2] != a[3]);

        return ans;
    }
};