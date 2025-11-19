// https://leetcode.com/problems/minimum-height-trees

class Solution {
public:
    const static int MX = 2e4+1;
    vector<bool> visited;
    vector<int> adj_list[MX], ans;

    pair<int, int> dfs1(int s, int d=0) {
        visited[s] = true;
        pair<int, int> ret = {d, s};
        for (int i : adj_list[s]){
            if (!visited[i]) 
                ret = max(ret, dfs1(i, d+1));
        }
        return ret;
    }

    bool dfs2(int s, int d, int h, int en) {
        visited[s] = true;
            
        bool path = (s == en);
        for (int i : adj_list[s]) {
            if (!visited[i]) 
                path |= dfs2(i, d+1, h, en);
        }
        if (path && (d == h/2 || (d == h/2+1 && h%2)))
            ans.push_back(s);
        return path;
    }
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        for (auto i : edges) {
            adj_list[i[0]].push_back(i[1]);
            adj_list[i[1]].push_back(i[0]);
        }
        visited = vector<bool> (n, false);
        int a = dfs1(0).second;
        visited = vector<bool> (n, false);
        auto p = dfs1(a);
        int b = p.second, h = p.first;

        visited = vector<bool> (n, false);
        dfs2(a, 0, h, b);
 
        return ans;
    }
};