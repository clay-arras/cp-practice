// https://leetcode.com/problems/minimum-moves-to-move-a-box-to-their-target-location

class Solution {
public:
    struct DSU {
        vector<int> e;
        void init(int N) {
            e = vector<int>(N,-1);
        }
        int get(int x) {
            if (e[x] < 0)
                return x;
            return e[x] = get(e[x]);
        }
        int size(int x) {
            return -e[get(x)];
        }
        bool unite(int x, int y) {
            x = get(x), y = get(y);
            if (x == y)
                return 0;
            if (e[x] > e[y])
                swap(x,y);
            e[x] += e[y];
            e[y] = x;
            return 1;
        }
    };

    int N, M;
    vector<vector<char>> g;
    vector<vector<bool>> visited;
    vector<vector<DSU>> ds;
    pair<int, int> bpos, spos, tpos;

    int tto(int m, int n) { return m*N + n;  }
    pair<int, int> ott(int i) { return {i / N, i % N};  }

    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};

    void dfs(int i, int j, DSU& d) {
        visited[i][j] = true;
        for (int k=0; k<4; k++) {
            int x = i + dx[k], y = j + dy[k];  
            if (x >= 0 && x < M && y >= 0 && y < N && !visited[x][y] && g[x][y] != '#') {
                d.unite(tto(i, j), tto(x, y));
                dfs(x, y, d);
            }
        }
    }
    int BIGN = INT_MAX - 2e7;

    vector<vector<unordered_map<int, int>>> memo, state;
    // state: position of the box, region of the person (map) -> total pushes
    int dp(int i, int j, int ci, int cj) { // worst case box splits into 4 positions
        int leader = ds[i][j].get(tto(ci, cj));
        if (state[i][j][leader] == 2)
            return memo[i][j][leader]; 
        if (i == bpos.first && j == bpos.second) {
            state[i][j][leader] = 2;
            return memo[i][j][leader] = 0;
        } // base case
        if (state[i][j][leader] == 1)
            return BIGN;

        state[i][j][leader] = 1;
        
        int ans = BIGN;
        for (int k=0; k<4; k++) {
            // int bx = i + dx[k], by = j + dy[k];   // where it was previously
            // int x = i + 2*dx[k], y = j + 2*dy[k];  // where s was previously
            int bx = i - dx[k],  by = j - dy[k];      // previous box position
            int x  = i - 2*dx[k], y  = j - 2*dy[k];   // previous player position
    
            if (bx < 0 || bx >= M || by < 0 || by >= N || g[bx][by] == '#')
                continue;
 
            if (x >= 0 && x < M && y >= 0 && y < N && 
                    g[x][y] != '#' && leader == ds[i][j].get(tto(bx, by))) {
                ans = min(ans, dp(bx, by, x, y) + 1);
            }
        }
        ans = min(ans, BIGN);
        state[i][j][leader] = 2;
        return memo[i][j][leader] = ans;
    }
        
    int minPushBox(vector<vector<char>>& grid) {
        // idea: disjoint set union, to figure out connected spaces

        M = (int)grid.size();
        N = (int)grid[0].size();
        g = grid;

        ds = vector<vector<DSU>> (M, vector<DSU> (N));
        for (int i=0; i<M; i++) {
            for (int j=0; j<N; j++) {
                if (g[i][j] != '#') {
                    ds[i][j].init(M*N);
                    char orig = g[i][j];
                    g[i][j] = '#';

                    visited = vector<vector<bool>>(M, vector<bool>(N, false));
                    for (int x=0; x<M; x++)
                        for (int y=0; y<N; y++)
                            if (!visited[x][y] && g[x][y] != '#')
                                dfs(x, y, ds[i][j]);
                    g[i][j] = orig;
                }
                if (g[i][j] == 'S')
                    spos = {i, j};
                if (g[i][j] == 'B')
                    bpos = {i, j};
                if (g[i][j] == 'T')
                    tpos = {i, j};
            }
        }
        memo = vector<vector<unordered_map<int, int>>>(M, vector<unordered_map<int, int>>(N));
        state = vector<vector<unordered_map<int, int>>>(M, vector<unordered_map<int, int>>(N));

        int leader = ds[bpos.first][bpos.second].get(tto(spos.first, spos.second));
        memo[bpos.first][bpos.second][leader] = 0;
        state[bpos.first][bpos.second][leader] = 2;
        int ret = dp(tpos.first, tpos.second, spos.first, spos.second);

        return (ret == BIGN ? -1 : ret);
    }
};
/*

[[".",".",".",".",".",".",".","."],
 [".",".","#",".",".",".",".","."],
 [".","T",".",".",".",".",".","#"],
 ["#",".",".",".","#",".",".","."],
 [".",".",".",".",".",".",".","."],
 [".",".",".",".",".",".",".","."],
 [".",".","S",".","B",".",".","."],
 [".",".",".",".",".",".",".","."]]

[[".",".",".",".",".",".",".","."],
 [".","T",".",".",".",".",".","."],
 [".",".",".",".",".",".",".","."],
 [".",".",".",".",".",".",".","."],
 [".",".","S",".","B",".",".","."],
 [".",".",".",".",".",".",".","."]]

*/