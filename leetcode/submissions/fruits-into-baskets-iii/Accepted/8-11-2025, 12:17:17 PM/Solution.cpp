// https://leetcode.com/problems/fruits-into-baskets-iii

class Solution {
public:
    template<class T>
    struct SegTree {
        static constexpr T unit = {INT_MAX, -1};
        T f(T a, T b) { return min(a, b); }
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

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int N = (int)baskets.size();
        int mxV = *max_element(baskets.begin(), baskets.end());

        vector<int> srt;
        unordered_map<int, int> cc;
        for (int i=0; i<N; i++) {
            if (!cc[fruits[i]]) {
                cc[fruits[i]] = 1;
                srt.push_back(fruits[i]);
            }
            if (!cc[baskets[i]]) {
                cc[baskets[i]] = 1;
                srt.push_back(baskets[i]);
            }
        }
        sort(srt.begin(), srt.end());
        for (int i=0; i<(int)srt.size(); i++)
            cc[srt[i]] = i;

        SegTree<pair<int, int>> s((int)srt.size()+1);
        unordered_map<int, priority_queue<int>> m; // baskets[i], {-i...}
        for (int i=0; i<N; i++) 
            m[cc[baskets[i]]].push(-i);

        for (auto& [k, v] : m) {
            if (!v.empty()) {
                s.update(k, {-v.top(), k}); // baskets[i], {i, baskets[i]}
                v.pop();
            }
        }

        int ans = 0;
        for (int f : fruits) {
            auto val = s.query(cc[f], (int)srt.size()+1); // {i, baskets[i]}
            if (val.first == INT_MAX) {
                ans += 1;
                continue;
            }
            if (m[val.second].empty()) {
                s.update(val.second, {INT_MAX, val.second});
            } else {
                s.update(val.second, {-m[val.second].top(), val.second});
                m[val.second].pop();
            }
        }
        return ans;
    }
};