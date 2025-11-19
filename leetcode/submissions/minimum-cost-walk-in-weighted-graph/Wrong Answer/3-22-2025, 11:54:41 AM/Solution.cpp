// https://leetcode.com/problems/minimum-cost-walk-in-weighted-graph

class Solution {
public:
    struct DSU {
        vector<int> e, a;
        void init(int N) {
            e = vector<int>(N,-1);
            a = vector<int>(N,-1); // all 1s in bitwise
        }
        int get(int x) {
            if (e[x] < 0)
                return x;
            return e[x] = get(e[x]);
        }
        int size(int x) {
            return -e[get(x)];
        }
        bool unite(int x, int y, int weight) {
            x = get(x), y = get(y);
            if (e[x] > e[y])
                swap(x,y);
            a[x] &= weight;
            if (x == y)
                return 0;
            e[x] += e[y];
            e[y] = x;
            return 1;
        }
    };

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        DSU d; d.init(n);
        for (auto i : edges) 
            d.unite(i[0], i[1], i[2]);
        
        vector<int> ans;
        for (auto q : query) {
            if (d.get(q[0]) == d.get(q[1]))
                ans.push_back(d.a[d.get(q[0])]);
            else ans.push_back(-1);
        }
        return ans;
    }
};