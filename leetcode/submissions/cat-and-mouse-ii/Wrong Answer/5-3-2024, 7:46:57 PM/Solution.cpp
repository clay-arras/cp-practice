// https://leetcode.com/problems/cat-and-mouse-ii

class Solution {
public:
    int N, M;
    vector<string> g;
    pair<int, int> c, m, f;
    vector<int> dx = {0, 1, 0 , -1};
    vector<int> dy = {1, 0, -1 , 0};
    
    int dijkstras(int i, int j, int mx) {
        vector<vector<int>> d (N, vector<int> (M, INT_MAX - 1e2));
        vector<vector<bool>> visited (N, vector<bool> (M, false));
        
        priority_queue<pair<int, pair<int, int>>> pq;
        d[i][j] = 0;
        pq.push({0, {i, j}});
 
        while (!pq.empty()) {
            int a = pq.top().second.first, b = pq.top().second.second;
            pq.pop();
 
            if (visited[a][b])
                continue;
            visited[a][b] = true;
            
            for (int k=1; k<=mx; k++) {
                for (int v=0; v<4; v++) {
                    int x = a + dx[v] * mx, y = b + dy[v] * mx;
                    if (x >= 0
                        && x < N
                        && y >= 0
                        && y < M
                        && g[x][y] != '#') {
 
                        if (d[a][b] + 1 < d[x][y]) {
                            d[x][y] = d[a][b] + 1;
                            pq.push({-d[x][y], {x, y}});
                        }
                    }
                }
            }
        }
 
        return d[f.first][f.second];
    }
 
    bool canMouseWin(vector<string>& grid, int catJump, int mouseJump) {
        N = (int)grid.size();
        M = (int)grid[0].size();
        g = grid;
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                if (g[i][j] == 'C') 
                    c.first = i, c.second = j;
                if (g[i][j] == 'M')
                    m.first = i, m.second = j;
                if (g[i][j] == 'F')
                    f.first = i, f.second = j;
            }
        }
 
        int catSteps = dijkstras(c.first, c.second, catJump);
        int mouseSteps = dijkstras(m.first, m.second, mouseJump);
        cout << catSteps << endl;
        cout << mouseSteps << endl;
        return catSteps >= mouseSteps;
    }
};
