// https://leetcode.com/problems/find-minimum-diameter-after-merging-two-trees

class Solution {
public:
    unordered_map<int, vector<int>> adj_list;
    unordered_map<int, bool> visited;
    vector<int> pth;

    pair<int, int> dfs1(int s, int dist, bool frs = false) {
        if (frs) visited.clear();
        pair<int, int> ret = {dist, s};
        visited[s] = true;
        for (int i : adj_list[s]) {
            if (!visited[i])
                ret = max(ret, dfs1(i, dist+1));
        }
        return ret;
    }

    bool dfs2(int s, int en, bool frs = false) {
        if (frs) {
            visited.clear();
            pth.clear();
        }
        visited[s] = true;
        if (s == en) {
            pth.push_back(s);
            return true;
        }
        bool is_path = false;
        for (int i : adj_list[s]) {
            if (!visited[i])
                is_path |= dfs2(i, en);
        }
        if (is_path) pth.push_back(s);
        return is_path;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        for (auto e : edges1) {
            adj_list[e[0]].push_back(e[1]);
            adj_list[e[1]].push_back(e[0]);
        }
        for (auto e : edges2) {
            adj_list[-e[0]-1].push_back(-e[1]-1);
            adj_list[-e[1]-1].push_back(-e[0]-1);
        }

        int cn1 = 0, cn2 = 0;
        pair<int, int> n1, n2;
        const auto get_diameter_center = [&](int src) {
            n1 = dfs1(src, 0, true);
            n2 = dfs1(n1.second, 0, true);
            // dfs2(n1.second, n2.second, true);
            // int ret = pth[(int)pth.size()/2];
            // return ret;
            return n2.first;
        };

        if ((int)edges1.size() != 0) 
            cn1 = get_diameter_center(edges1[0][0]);
        if ((int)edges2.size() != 0) 
            cn2 = get_diameter_center(-edges2[0][0]-1);

        cout << cn1 << " " << cn2 << endl;
        return max({cn1, cn2, (int)ceil(cn1*1.0/2) + (int)ceil(cn2*1.0/2) + 1});
        // adj_list[cn1].push_back(cn2);
        // adj_list[cn2].push_back(cn1);

        // n1 = dfs1(cn1, 0, true);
        // n2 = dfs1(n1.second, 0, true);

        // return n2.first;
    }
};