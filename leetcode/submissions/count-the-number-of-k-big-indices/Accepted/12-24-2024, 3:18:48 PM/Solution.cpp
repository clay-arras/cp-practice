// https://leetcode.com/problems/count-the-number-of-k-big-indices

class Solution {
public:

    template<class T>
    struct SegTree {
        static constexpr T unit = 0;
        T f(T a, T b) { return a + b; }
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

    int kBigIndices(vector<int>& nums, int k) {
        map<int, vector<int>> m;
        int N = (int)nums.size();
        for (int i=0; i<N; i++) 
            m[nums[i]].push_back(i);

        int ans = 0;
        SegTree<int> st(N, 0);

        for (auto [ky, v] : m) {
            for (int i : v) {
                int l = st.query(0, i);
                int r = st.query(i, N);
                ans += (l >= k) && (r >= k);
            }
            for (int i : v)
                st.update(i, 1);
        }
        return ans;
    }
};