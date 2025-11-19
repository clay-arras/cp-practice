// https://leetcode.com/problems/russian-doll-envelopes

class Solution {
public:
    template<class T>
    struct SegTree {
        static constexpr T unit = 0;
        T f(T a, T b) { return max(a, b); }
        vector<T> tree; int n;
        SegTree (int i = 0, T def = unit) : tree(2*i, def), n(i) {}
        void update(int pos, T val) {
            for (tree[pos += n] = val; pos /= 2;)
                tree[pos] = f(tree[pos * 2], tree[pos * 2 + 1]);
        }
        T query(int b, int e) {
            T ra = unit, rb = unit;
            for (b += n, e += n; b < e; b /= 2, e /= 2) {
                if (b % 2) ra = f(ra, tree[b++]);
                if (e % 2) rb = f(tree[--e], rb);
            }
            return f(ra, rb);
        }
    };

    const static int MX = 1e5+1;
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int N = (int)envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, 
                const vector<int>&b) {
            if (a[0] == b[0])
                return a[1] < b[1];
            return a[0] < b[0];
        });

        vector<pair<int, int>> heights;
        for (int i=0; i<N; i++)
            heights.push_back({envelopes[i][1], i});
        sort(heights.begin(), heights.end());

        unordered_map<int, pair<int, int>> h; // {local, global}
        unordered_map<int, int> minH;
        for (int i=0; i<N; i++) {
            if (!minH.count(heights[i].first))
                minH[heights[i].first] = i;
            h[heights[i].second] = {minH[heights[i].first], i};
        }

        map<int, vector<int>> w;
        for (int i=0; i<N; i++)
            w[envelopes[i][0]].push_back(i);
        
        SegTree<int> stree(N, 0);
        for (auto [k, v] : w) {
            queue<int> upd;
            for (int i : v) {
                int val = stree.query(0, h[i].first) + 1;
                upd.push(val);
            }
            for (int i : v) {
                int val = upd.front();
                stree.update(h[i].second, val);
                upd.pop();
            }
        }
        return stree.query(0, N);
    }
};