// https://leetcode.com/problems/minimum-height-trees

class Solution {
public:
    const static int MAXN = 2e4+4;
    vector<int> adj_list[MAXN];
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
        queue<vector<int>> paths;
        queue<int> q;
        q.push(st);
        paths.push({st});
        vector<int> p = {st};

        while (!q.empty()) {
            int s = q.front();
            vector<int> path = paths.front();
            q.pop();
            paths.pop();
            visited[s] = true;

            if (s == en) {
                p = path;
                break;
            }

            for (int i : adj_list[s]) {
                if (!visited[i]) {
                    q.push(i);
                    path.push_back(s);
                    paths.push(path);
                }
            }
        }

        for (auto i : p)
            cout << i << " ";
        cout << endl;
        p.push_back(en);
        for (int i=0, len=(int)p.size(); i<len; i++) {
            if (len % 2 && i == dist) {
                return {p[i]};
            } else if (len % 2 == 0 && i == dist){
                return {p[i-1], p[i]};
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
        fill(visited.begin(), visited.end(), false);
        dfs(n1, 0, dist = 0, n2);
        fill(visited.begin(), visited.end(), false);
        vector<int> ans = bfs(n1, n2, floor(dist*1.0/2), n);

        return ans;
    }
};