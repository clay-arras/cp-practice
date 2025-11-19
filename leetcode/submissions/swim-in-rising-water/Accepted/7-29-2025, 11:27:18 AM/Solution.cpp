// https://leetcode.com/problems/swim-in-rising-water

class Solution {
public:
    template<class T>
    T firstTrue(T l, T r, function<bool(T)> f) {
        r++;
        while (l < r) {
            T mid = l + (r - l) / 2;
            if (f(mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }

    int N;
    vector<vector<int>> adj_list;
    vector<bool> visited;

    void dfs(int t) {
        visited[t] = true;
        for (int k : adj_list[t]) {
            if (!visited[k])
                dfs(k);
        }
    } 

    int swimInWater(vector<vector<int>>& grid) {
        N = (int)grid.size();
        auto ok = [&](int k) {
            adj_list = vector<vector<int>>(N*N);
            visited = vector<bool> (N*N, false);

            for (int i=0; i<N; i++) {
                for (int j=0; j<N; j++) {
                    if (grid[i][j] <= k) {
                        if (i && grid[i-1][j] <= k) {
                            adj_list[(i-1)*N + j].push_back(i*N + j);
                            adj_list[i*N + j].push_back((i-1)*N + j);
                        }
                        if (j && grid[i][j-1] <= k) {
                            adj_list[i*N + j-1].push_back(i*N + j);
                            adj_list[i*N + j].push_back(i*N + j-1);
                        }
                    }
                }
            }
            dfs(0);
            return visited[N*(N-1) + (N-1)];
        };

        return firstTrue<int>(0, N*N, ok);
    }
};
// logN * N^2
// firstTrue