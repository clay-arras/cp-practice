// https://leetcode.com/problems/most-profitable-path-in-a-tree

class Solution {
public:
    const static int MX = 1e5+9;
    vector<int> adj_list[MX];
    vector<bool> visited;

    template<class T>
    vector<T> BFS(T src, int N, vector<int>& path, vector<int>& amount) {
        const T mxV = 1e9+9;
        queue<int> q;
        vector<T> dist(N, mxV);
        vector<int> income(N, 0);

        dist[src] = 0;
        q.push(src);
        int timestep = -1;
        while (!q.empty()) {

            int x = q.front();

            if (timestep < dist[x]) {
                timestep = dist[x]; 
                cout << timestep << endl;
                if (timestep < (int)path.size()) {
                    if (path[timestep] == x) 
                        amount[x] /= 2;
                    else amount[path[timestep]] = 0;
                }
            }
            income[x] += amount[x];
            
            q.pop();
            for (int t : adj_list[x]) {
                if (dist[t] == mxV) {
                    dist[t] = dist[x] + 1;
                    income[t] = income[x];
                    q.push(t);
                }
            }
        }
        return income;
    }

    vector<int> dfs(int s) {
        visited[s] = true;
        if (s == 0)  return {s};

        for (int i : adj_list[s]) {
            if (!visited[i]) {
                vector<int> val = dfs(i);
                if (val != vector<int>()) {
                    val.push_back(s);
                    return val;
                }
            }
        }
        return vector<int>();
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        // bfs
        // at each depth, figure out which node bob is going to. 
        // 2 cases: either its the same OR its completely different path (Alice and Bob meet at MOST once)
        // either way, we DIRECTLY modify the tree values
        int N = (int)amount.size();

        for (auto e : edges) {
            adj_list[e[0]].push_back(e[1]);
            adj_list[e[1]].push_back(e[0]);
        }

        visited = vector<bool> (N, false);
        vector<int> path = dfs(bob);
        reverse(path.begin(), path.end()); // path[i] is the node BOB is on at timestep i

        vector<int> ans = BFS<int>(0, N, path, amount);
        int mxVal = -INT_MAX;
        for (int i=1; i<N; i++) {
            if ((int)adj_list[i].size() == 1)
                mxVal = max(mxVal, ans[i]);
        }

        return mxVal;
    }
};