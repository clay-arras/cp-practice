// https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths

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

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        vector<pair<vector<int>, int>> st;
        int Q = (int)queries.size();
        for (int i=0; i<Q; i++) 
            st.push_back({queries[i], i});
        
        sort(st.begin(), st.end(), 
            [](const pair<vector<int>, int>& x, const pair<vector<int>, int>& y) {
                return x.first[2] < y.first[2];
        });
        sort(edgeList.begin(), edgeList.end(), 
            [](const vector<int>& x, const vector<int>& y) {
                return x[2] < y[2];
        });

        int k = 0;
        DSU d; d.init(n);
        vector<bool> ans(Q);
        for (auto q : st) {
            int limit = q.first[2];
            int x = q.first[0], y = q.first[1];
            for (; k<(int)edgeList.size() && edgeList[k][2] < limit; k++) 
                d.unite(edgeList[k][0], edgeList[k][1]);
            ans[q.second] = (d.get(x) == d.get(y));
        }
        
        return ans;
    }
};