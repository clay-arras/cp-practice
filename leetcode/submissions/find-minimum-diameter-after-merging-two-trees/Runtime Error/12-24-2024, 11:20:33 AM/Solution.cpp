// https://leetcode.com/problems/find-minimum-diameter-after-merging-two-trees

class Solution {
public:
    unordered_map<int, vector<int>> adj_list;
    unordered_map<int, bool> visited;
    vector<int> pth;

    pair<int, int> dfs1(int s, int dist) {
        pair<int, int> ret = {dist, s};
        visited[s] = true;
        for (int i : adj_list[s]) {
            if (!visited[i])
                ret = max(ret, dfs1(i, dist+1));
        }
        return ret;
    }

    void dfs2(int s, int en, vector<int> path) {
        path.push_back(s);
        visited[s] = true;
        if (s == en) 
            pth = path;
        for (int i : adj_list[s]) {
            if (!visited[i])
                dfs2(i, en, path);
        }
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        // basic algorithm: 
        // - find midpoint node of both trees
        // - connect them
        // - find diameter

        // design: 
        // - one to find two diameter nodes and distance
        // - one to find midpoint of two nodes
        if ((int)edges1.size() == 0 && (int)edges2.size() == 0)
            return 1; 

        for (auto e : edges1) {
            adj_list[e[0]].push_back(e[1]);
            adj_list[e[1]].push_back(e[0]);
        }
        for (auto e : edges2) {
            adj_list[-e[0]-1].push_back(-e[1]-1);
            adj_list[-e[1]-1].push_back(-e[0]-1);
        }

        pair<int, int> n1 = dfs1(edges1[0][0], 0);
        visited.clear();
        pair<int, int> n2 = dfs1(n1.second, 0);
        visited.clear();
        dfs2(n1.second, n2.second, {});
        visited.clear();
        int cn1 = pth[(int)pth.size()/2];
        if ((int)edges2.size() == 0)
            return n2.first + 1;

        n1 = dfs1(edges2[0][0]-1, 0);
        visited.clear();
        n2 = dfs1(n1.second, 0);
        visited.clear();
        dfs2(n1.second, n2.second, {});
        visited.clear();
        int cn2 = pth[(int)pth.size()/2];
        if ((int)edges1.size() == 0)
            return n2.first + 1;

        adj_list[cn1].push_back(cn2);
        adj_list[cn2].push_back(cn1);

        n1 = dfs1(cn1, 0);
        visited.clear();
        n2 = dfs1(n1.second, 0);
        visited.clear();

        return n2.first;
    }
};