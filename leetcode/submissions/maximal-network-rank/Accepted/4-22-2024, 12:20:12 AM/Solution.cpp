// https://leetcode.com/problems/maximal-network-rank

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> adj_list[n];
        map<pair<int, int>, int> m;
        for (auto r : roads) {
            adj_list[r[0]].push_back(r[1]);
            adj_list[r[1]].push_back(r[0]);
            m[{r[0], r[1]}] = 1;
            m[{r[1], r[0]}] = 1;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ans = max(ans, (int)adj_list[i].size() +
                                   (int)adj_list[j].size() - m[{i, j}]);
            }
        }
        return ans;
    }
};