// https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable

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

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU d1, d2;
        d1.init(n);
        d2.init(n);

        vector<pair<int, int>> t[3];
        for (auto i : edges) 
            t[--i[0]].push_back({--i[1], --i[2]});

        int cnt = 0;
        for (auto [f, s] : t[2]) {
            if (d1.get(f) != d1.get(s)) {
                cnt++;
                d1.unite(f, s);
                d2.unite(f, s);
            }
        }
        for (auto [f, s] : t[1]) {
            if (d2.get(f) != d2.get(s)) {
                cnt++;
                d2.unite(f, s);
            }
        }
        for (auto [f, s] : t[0]) {
            if (d1.get(f) != d1.get(s)) {
                cnt++;
                d1.unite(f, s);
            }
        }
        if (d1.size(0) != n || d2.size(0) != n)
            return -1;
        return (int)edges.size() - cnt;
    }
};