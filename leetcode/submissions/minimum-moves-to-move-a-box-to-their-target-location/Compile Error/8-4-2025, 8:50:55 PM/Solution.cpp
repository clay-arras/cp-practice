// https://leetcode.com/problems/minimum-moves-to-move-a-box-to-their-target-location

class Solution {
public:
    int N, M;
    vector<vector<char>> g;

    int tto(int m, int n) {
        return m*N + n; 
    }
    pair<int, int> ott(int i) {
        return {i / N, i % N}; 
    }

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
    // assume you can walk though T

    void dfs()
        
    int minPushBox(vector<vector<char>>& grid) {
        // is there ever a situation where the position of the player matters in the state
        // i.e. pushing the box splits the area into two spaces.
        // answer: need to keep track of player position then??? or just space-wise, need to keep track of where they are.

        // idea: disjoint set union, to figure out connected spaces

        // simplification: assume guy can teleport anywhere. in that case, it would be a simple graph search. connect node A to node B if there's a space behind it.

        // dp
        // state: position of the box, region of the person (map) -> total pushes

        // first loop: for every position of the box, figure out which distinct spaces exist. i.e. 400 DSUs

        M = (int)grid.size();
        N = (int)grid[0].size();
        g = grid;

        vector<vector<DSU>> ds(M, vector<DSU> (N));
        for (int i=0; i<M; i++) {
            for (int j=0; j<N; j++) {
                if (grid[i][j] != '#') {
                    ds[i][j].init(tto(M, N));
                    char orig = grid[i][j];
                    grid[i][j] = '#';
                    // flood fill

                    grid[i][j] = orig;
                }
            }
        }
    }
};