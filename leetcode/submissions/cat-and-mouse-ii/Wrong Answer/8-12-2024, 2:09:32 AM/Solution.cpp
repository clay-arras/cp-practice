// https://leetcode.com/problems/cat-and-mouse-ii

class Solution {
public:
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};
    int N, M;
    vector<string> g;
    vector<vector<bool>> visited;
    pair<int, int> C, Ms, F;

    void dijkstras(int i, int j, int mx, vector<vector<int>>& d) {
        vector<vector<bool>> visited(N, vector<bool>(M, false));
        priority_queue<pair<int, pair<int, int>>> pq;
        d[i][j] = 0;
        pq.push({0, {i, j}});

        while (!pq.empty()) {
            int a = pq.top().second.first, b = pq.top().second.second;
            pq.pop();

            if (visited[a][b])
                continue;
            visited[a][b] = true;

            for (int v = 0; v < 4; v++) {
                for (int k = 1; k <= mx; k++) {
                    int x = a + dx[v] * k, y = b + dy[v] * k;
                    if (x >= 0 && x < N && y >= 0 && y < M) {
                        if (g[x][y] == '#')
                            break;
                        if (d[a][b] + 1 < d[x][y]) {
                            d[x][y] = d[a][b] + 1;
                            pq.push({-d[x][y], {x, y}});
                        }
                    }
                }
            }
        }
    }

    void dfs(int x, int y, int k, vector<vector<int>>& c,
             vector<vector<int>>& m) {
        visited[x][y] = true;
        for (int i = 0; i < 4; i++) {
            for (int j = 1; j <= k; j++) {
                int xnew = x + dx[i] * j;
                int ynew = y + dy[i] * j;
                if (xnew >= 0 && xnew < N && ynew >= 0 && ynew < M) {
                    if (g[xnew][ynew] == '#')
                        break;
                    if (!visited[xnew][ynew] &&
                        (m[xnew][ynew] < c[xnew][ynew] ||
                         (g[xnew][ynew] == 'F' &&
                          m[xnew][ynew] == c[xnew][ynew])))
                        dfs(xnew, ynew, k, c, m);
                }
            }
        }
    }

    bool canMouseWin(vector<string>& grid, int catJump, int mouseJump) {
        N = (int)grid.size();
        M = (int)grid[0].size();
        g = grid;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (g[i][j] == 'C')
                    C = {i, j};
                if (g[i][j] == 'M')
                    Ms = {i, j};
                if (g[i][j] == 'F')
                    F = {i, j};
            }
        }

        // const int MXV = INT_MAX-1e2;
        const int MXV = 20;
        vector<vector<int>> m(N, vector<int>(M, MXV)),
            c(N, vector<int>(M, MXV));

        dijkstras(C.first, C.second, catJump, c);
        dijkstras(Ms.first, Ms.second, mouseJump, m);

        visited = vector<vector<bool>>(N, vector<bool>(M, false));
        dfs(Ms.first, Ms.second, mouseJump, c, m);

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++)
                cout << setw(4) << c[i][j] << " ";
            cout << endl;
        }
        cout << endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++)
                cout << setw(4) << m[i][j] << " ";
            cout << endl;
        }

        cout << endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++)
                cout << visited[i][j];
            cout << endl;
        }

        return visited[F.first][F.second];
    }
};
// ["####F",
//  "#C...",
//  "M...."]

// ["C...#",
//  "...#F",
//  "....#",
//  "M...."]

// [".M...",
//  "..#..",
//  "#..#.",
//  "C#.#.",
//  "...#F"]

// ["#F..",
//  "..#.",
//  "..M.",
//  "..C."]

// ["FC#..",
//  ".....",
//  "M#..#"]

// ["........",
//  "F...#C.M",
//  "........"]
