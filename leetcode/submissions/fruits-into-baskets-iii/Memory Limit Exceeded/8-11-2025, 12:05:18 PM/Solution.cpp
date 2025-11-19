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

        SegTree<pair<int, int>> s(mxV+1);
        unordered_map<int, priority_queue<int>> m; // baskets[i], {-i...}
        for (int i=0; i<N; i++) 
            m[baskets[i]].push(-i);

        for (auto& [k, v] : m) {
            if (!v.empty()) {
                s.update(k, {-v.top(), k}); // baskets[i], {i, baskets[i]}
                v.pop();
            }
        }

        int ans = 0;
        for (int f : fruits) {

            auto val = s.query(f, mxV+1); // {i, baskets[i]}
            cout << val.first << " " << val.second << endl;;
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

        // set<pair<int, int>> s;

        // for (int i=0; i<N; i++) {
        //     s.insert({baskets[i], i});
        // }
        // int ans = 0;
        // for (int f : fruits) {
        //     auto it = s.lower_bound({f, -1});
        //     cout << it->first << " " << it->second << endl;
        //     if (it == s.end()) {
        //         ans += f;
        //         continue;
        //     }
        //     s.erase(it); 
        // }
        // return ans;
        // segment tree w/ min. idx = capacity, val = idx. range query (minCap, end), then remove value from segTree
    }

    /*

tree = 

{{first = 2147483647, second = -1}, 
{first = 0, second = 3}, 
{first = 0, second = 3}, 
{first = 2147483647, second = -1}, 
{first = 0, second = 3}, 
{first = 1, second = 5}, 
{first = 2147483647, second = -1}, 
{first = 2147483647, second = -1}, 
{first = 2147483647, second = -1}, 
{first = 0, second = 3}, 
{first = 2, second = 4}, 
{first = 1, second = 5}}, 
n = 6}

    */
};