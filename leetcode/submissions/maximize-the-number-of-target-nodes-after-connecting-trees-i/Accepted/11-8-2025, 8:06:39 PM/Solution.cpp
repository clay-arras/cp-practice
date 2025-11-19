// https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-i

class Solution {
public:
    vector<int> BFS(int src, int N, vector<vector<int>>& adj_list) {
        queue<int> q;
        vector<int> dist(N, INT_MAX);

        dist[src] = 0;
        q.push(src);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int t : adj_list[x]) {
                if (dist[t] == INT_MAX) {
                    dist[t] = dist[x] + 1;
                    q.push(t);
                }
            }
        }
        return dist;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        // run a bfs from every node and get the number of dists smaller than k
        // sum the MAXIMUM of that value to the bfs to every node in tree1
        int N = (int)edges1.size() + 1;
        int M = (int)edges2.size() + 1;

        vector<vector<int>> adj_list1(N);
        vector<vector<int>> adj_list2(M);

        for (auto e : edges1) {
            adj_list1[e[0]].push_back(e[1]);
            adj_list1[e[1]].push_back(e[0]);
        }
        for (auto e : edges2) {
            adj_list2[e[0]].push_back(e[1]);
            adj_list2[e[1]].push_back(e[0]);
        }

        int ans = 0;
        for (int i=0; i<M; i++) {
            vector<int> fs = BFS(i, M, adj_list2);
            int cnt = 0;
            for (int f : fs)
                cnt += (f <= k-1);
            ans = max(ans, cnt);
        }

        vector<int> ret(N);
        for (int i=0; i<N; i++) {
            vector<int> fs = BFS(i, N, adj_list1);
            int cnt = 0;
            for (int f : fs)
                cnt += (f <= k);
            ret[i] = (cnt + ans);
        }
        return ret;
    }
};