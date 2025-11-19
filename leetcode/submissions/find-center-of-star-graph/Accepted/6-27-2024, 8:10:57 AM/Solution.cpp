// https://leetcode.com/problems/find-center-of-star-graph

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int, int> m;
        for (auto v : edges)
            m[v[0]]++, m[v[1]]++;
        pair<int, int> mx = {0, 0};
        for (auto [k, v] : m)
            mx = max(mx, {v, k});
        return mx.second;
    }
};