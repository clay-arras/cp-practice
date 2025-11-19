// https://leetcode.com/problems/minimum-height-trees

class Solution {
public:
    const static int MAXN = 2e4+4;
    vector<int> adj_list[MAXN];
    // vector<int> paths[MAXN];
    vector<bool> visited;

    void dfs(int s, int count, int& maxCount, int& maxNode) {
        visited[s] = true;
        count++;
        if (count >= maxCount) {
            maxCount = count;
            maxNode = s;
        }

        for (int i : adj_list[s]) {
            if (!visited[i]) {
                dfs(i, count, maxCount, maxNode);
            }
        }
    }

    vector<int> bfs(int st, int en, int dist, int n) {
        vector<vector<int>> paths = vector<vector<int>>(n, {});
        queue<int> q;
        q.push(st);

        while (!q.empty()) {
            int s = q.front();
            q.pop();
            visited[s] = true;

            for (int i : adj_list[s]) {
                if (!visited[i]) {
                    q.push(i);
                    paths[i].assign(paths[s].begin(), paths[s].end());
                    paths[i].push_back(s);
                }
            }
        }
        paths[en].push_back(en);
        for (int i=0, len=(int)paths[en].size(); i<len; i++) {
            if (len % 2 && i == dist) {
                return {paths[en][i]};
            } else if (len % 2 == 0 && i == dist){
                return {paths[en][i-1], paths[en][i]};
            }
        }
        return {};
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        for (auto e : edges) {
            adj_list[e[0]].push_back(e[1]);
            adj_list[e[1]].push_back(e[0]);
        }
        
        int n1 = 0, n2 = 0, dist = 0;
        visited = vector<bool> (n, false);
        dfs(0, 0, dist, n1);
        visited = vector<bool> (n, false);
        dfs(n1, 0, dist = 0, n2);
        visited = vector<bool> (n, false);
        cout << n1 << " " << n2 << endl;
        cout << dist << endl;

        return  bfs(n1, n2, floor(dist*1.0/2), n);
    }
};