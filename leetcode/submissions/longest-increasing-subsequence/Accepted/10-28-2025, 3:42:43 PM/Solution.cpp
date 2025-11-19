// https://leetcode.com/problems/longest-increasing-subsequence

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

    int lengthOfLIS(vector<int>& nums) {
        int N = (int)nums.size();

        vector<pair<int, int>> comp;
        for (int i=0; i<N; i++)
            comp.push_back({nums[i], i});
        sort(comp.begin(), comp.end());

        unordered_map<int, int> cc;
        int cnt = 0;
        for (int i=0; i<N; i++) {
            if (!cc.count(comp[i].first)) 
                cc[comp[i].first] = cnt++;
            comp[i] = {cc[comp[i].first], comp[i].second};
        }
        sort(comp.begin(), comp.end(), [](const pair<int, int>& a, 
                    const pair<int, int>& b) {
            if (a.second == b.second)  
                assert(false);
            return a.second < b.second;
        });

        SegTree<int> stree(cnt, 0);
        for (int i=0; i<N; i++) {
            int val = stree.query(0, comp[i].first) + 1;
            stree.update(comp[i].first, val);
        }
        return stree.query(0, cnt);
    }
};