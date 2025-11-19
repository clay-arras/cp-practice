// https://leetcode.com/problems/find-the-safest-path-in-a-grid

class Solution {
public:
    const static short int MXN = 4e2;
    short int N;
    vector<vector<short int>> g;

    void fill(short int i, short int j) {
        queue<pair<short int, short int>> q;
        vector<vector<short int>> d(N, vector<short int>(N, SHRT_MAX));
        q.push({i, j});
        d[i][j] = 0, g[i][j] = 0;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if (x + 1 < N && d[x + 1][y] == SHRT_MAX) {
                d[x + 1][y] = d[x][y] + 1;
                if (g[x + 1][y] >= d[x + 1][y]) {
                    g[x + 1][y] = min(g[x + 1][y], d[x + 1][y]);
                    q.push({x + 1, y});
                }
            }
            if (y + 1 < N && d[x][y + 1] == SHRT_MAX) {
                d[x][y + 1] = d[x][y] + 1;
                if (g[x][y + 1] >= d[x][y + 1]) {
                    g[x][y + 1] = min(g[x][y + 1], d[x][y + 1]);
                    q.push({x, y + 1});
                }
            }
            if (x - 1 >= 0 && d[x - 1][y] == SHRT_MAX) {
                d[x - 1][y] = d[x][y] + 1;
                if (g[x - 1][y] >= d[x - 1][y]) {
                    g[x - 1][y] = min(g[x - 1][y], d[x - 1][y]);
                    q.push({x - 1, y});
                }
            }
            if (y - 1 >= 0 && d[x][y - 1] == SHRT_MAX) {
                d[x][y - 1] = d[x][y] + 1;
                if (g[x][y - 1] >= d[x][y - 1]) {
                    g[x][y - 1] = min(g[x][y - 1], d[x][y - 1]);
                    q.push({x, y - 1});
                }
            }
        }
    }

    short int lastTrue(short int lo, short int hi, function<bool(short int)> f) {
        lo--;
        for (short int dif = hi - lo; dif > 0; dif /= 2) {
            while (lo + dif <= hi && f(lo + dif)) {
                lo += dif;
            }
        }
        return lo;
    }

    bool dfs(short int x, short int y, vector<bitset<MXN>>& visited, short int k) {
        visited[x][y] = true;

        bool ans = (x == N - 1 && y == N - 1 && g[x][y] >= k);
        if (x + 1 < N && !visited[x + 1][y] && g[x + 1][y] >= k && !ans)
            ans |= dfs(x + 1, y, visited, k);
        if (y + 1 < N && !visited[x][y + 1] && g[x][y + 1] >= k && !ans)
            ans |= dfs(x, y + 1, visited, k);
        if (x - 1 >= 0 && !visited[x - 1][y] && g[x - 1][y] >= k && !ans)
            ans |= dfs(x - 1, y, visited, k);
        if (y - 1 >= 0 && !visited[x][y - 1] && g[x][y - 1] >= k && !ans)
            ans |= dfs(x, y - 1, visited, k);

        return ans;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        N = (short int)grid.size();
        g = vector<vector<short int>>(N, vector<short int>(N, SHRT_MAX));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (grid[i][j])
                    fill(i, j);
        
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++)
                cout << g[i][j] << " ";
            cout << endl;
        }

        return lastTrue(0, 2 * N - 1, [&](short int k) -> bool {
            vector<bitset<MXN>> visited(N);
            return (g[0][0] >= k && dfs(0, 0, visited, k));
        });
    }
};