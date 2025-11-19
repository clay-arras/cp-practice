// https://leetcode.com/problems/maximal-network-rank

class Solution {
public:
    const static int MAXN = 1e2 + 2;
    set<int> adj_list[MAXN];
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int M = (int)roads.size();
        for (int i=0; i<M; i++) {
            adj_list[roads[i][0]].insert(roads[i][1]);
            adj_list[roads[i][1]].insert(roads[i][0]);
        }

        int ans = 0;
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                set<int> s;
                set_union(adj_list[i].begin(), adj_list[i].end(), adj_list[j].begin(), adj_list[j].end(), inserter(s, s.begin()));
                ans = max(ans, (int)s.size());
                
            }
        }
        return ans;
    }
};