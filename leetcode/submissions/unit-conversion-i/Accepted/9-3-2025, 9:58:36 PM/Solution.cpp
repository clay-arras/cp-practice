// https://leetcode.com/problems/unit-conversion-i

class Solution {
public:
    const static int MX = 1e9+7;
    vector<vector<pair<int, int>>> adj_list;
    vector<int> ans;
    vector<bool> visited;

    void dfs(int i) {
        visited[i] = true;

        for (auto x : adj_list[i]) {
            if (!visited[x.first]) {
                ans[x.first] = (ans[i] * 1LL * x.second) % MX;
                dfs(x.first);
            }
        }
    }

    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        int N = (int)conversions.size() + 1;
        ans = vector<int>(N, -1);
        visited = vector<bool>(N, false);

        adj_list.resize(N);
        for (int i=0; i<N-1; i++) {
            adj_list[conversions[i][0]].push_back({conversions[i][1], conversions[i][2]});
        }
        ans[0] = 1;

        dfs(0);
        return ans;
    }
};