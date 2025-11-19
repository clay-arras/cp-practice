// https://leetcode.com/problems/most-profitable-path-in-a-tree

class Solution {
public:
    const static int MX = 1e5+9;
    vector<int> adj_list[MX];
    vector<bool> visited;

    template<class T>
    vector<T> BFS(T src, int N, vector<int>& path, vector<int>& amount) {
        const T mxV = 1e17+9;
        queue<int> q;
        vector<T> dist(N, mxV);
        vector<long long> income(N, 0);

        dist[src] = 0;
        q.push(src);
        int timestep = -1;
        unordered_set<int>* thisLevel = new unordered_set<int> {};
        unordered_set<int>* nextLevel = new unordered_set<int> {};
        while (!q.empty()) {
            int x = q.front();
            thisLevel->insert(x);
            if (timestep < dist[x]) {
                timestep = dist[x]; 
                delete thisLevel;
                thisLevel = nextLevel;
                nextLevel = new unordered_set<int> {};

                if (timestep < (int)path.size()) {
                    if (thisLevel->count(path[timestep]))
                        amount[path[timestep]] /= 2;
                    else amount[path[timestep]] = 0;
                }
            }
            income[x] += amount[x];
            
            q.pop();
            for (int t : adj_list[x]) {
                if (dist[t] == mxV) {
                    dist[t] = dist[x] + 1;
                    nextLevel->insert(t);
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
        int N = (int)amount.size();
        for (auto e : edges) {
            adj_list[e[0]].push_back(e[1]);
            adj_list[e[1]].push_back(e[0]);
        }

        visited = vector<bool> (N, false);
        vector<int> path = dfs(bob);
        reverse(path.begin(), path.end());

        vector<long long> ans = BFS<long long>(0, N, path, amount);
        long long mxVal = -LLONG_MAX;
        for (int i=1; i<N; i++) {
            if ((int)adj_list[i].size() == 1)
                mxVal = max(mxVal, ans[i]);
        }

        return mxVal;
    }
};