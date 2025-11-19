// https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid

class Solution {
public:
    int N, M;
    map<pair<int, int>, vector<pair<int, pair<int, int>>>> adj_list;
    
    template<class T>
    map<T, int> BFS01() {
        const int mxV = 1e9;
        deque<pair<int, int>> q;
        map<T, int> dist;
        for (int i=0; i<N; i++)
            for (int j=0; j<M; j++)
                dist[{i, j}] = mxV;

        dist[{0, 0}] = 0;
        q.push_back({0, 0});
        while (!q.empty()) {
            
            T x=q.front();
            q.pop_front();
            for (auto t : adj_list[x]) {
                if (dist[t.second] > dist[x]+t.first) {
                    dist[t.second] = dist[x]+t.first;
                    if (t.first == 1) q.push_back(t.second);
                    else q.push_front(t.second);
                }
            }
        }
        return dist;
    }
    vector<int> dy = {1, -1, 0, 0};
    vector<int> dx = {0, 0, 1, -1};
    
    int minCost(vector<vector<int>>& grid) {
        N = (int)grid.size(), M = (int)grid[0].size();
        
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                for (int k=0; k<4; k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (x >= 0 && x < N && y >= 0 && y < M) {
                        // if (k+1-(k%2 ? -1 : 1) == grid[x][y]) continue;
                        if (k+1 == grid[i][j]) {
                            adj_list[{i, j}].push_back({0, {x, y}});
                            continue;
                        }
                        adj_list[{i, j}].push_back({1, {x, y}});
                    }
                }
            }
        }
        map<pair<int, int>, int> dist = BFS01<pair<int, int>>();
        return dist[{N-1, M-1}];
    }
};