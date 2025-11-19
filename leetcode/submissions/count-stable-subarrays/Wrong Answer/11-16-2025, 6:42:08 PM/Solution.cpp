// https://leetcode.com/problems/count-stable-subarrays

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
            e++;
            T ra = unit, rb = unit;
            for (b += n, e += n; b < e; b /= 2, e /= 2) {
                if (b % 2) ra = f(ra, tree[b++]);
                if (e % 2) rb = f(tree[--e], rb);
            }
            return f(ra, rb);
        }
    };
    
    template<class T>
    T firstTrue(T l, T r, function<bool(T)> f) {
        r++;
        while (l < r) {
            T mid = l + (r - l) / 2;
            if (f(mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
 
    vector<long long> countStableSubarrays(vector<int>& nums, vector<vector<int>>& queries) {
        int N = (int)nums.size();
        SegTree<int> st(N, 0);
        vector<pair<int, int>> pq;
        for (int i=0; i<N; i++) {
            int l = i;
            while (i+1<N && nums[i] <= nums[i+1]) 
                i++;
            int hand = (i - l + 1) + 1;
            st.update(l, hand*(hand-1)/2);
            pq.push_back({l, i});
        }
        for (int i=N; i<2*N; i++)
            cout << st.tree[i] << " ";
        cout << endl;
        for (auto i : pq)
            cout << i.first << " " << i.second << endl;

        vector<long long> ans;
        int M = (int)pq.size();
        for (auto q : queries) {
            int l = q[0], r = q[1];
            int val = st.query(l, r);   
            
            int lidx = firstTrue<int>(0, M-1, [&](int k) {
                return l <= pq[k].second;
            });
            if (lidx >= 0 && lidx < M && (l <= pq[lidx].second && l > pq[lidx].first)) {
                int hand = (pq[lidx].second - l + 1) + 1;
                val += hand*(hand-1)/2;
            }

            for (int i=0; i<M; i++) {
                cout << (bool)(pq[i].first >= r);
            }
            cout << endl;
            int ridx = firstTrue<int>(0, M-1, [&](int k) {
                return pq[k].second >= r;
            });
            cout << ridx << endl;
            if (ridx >= 0 && ridx < M && (r < pq[ridx].second && r >= pq[ridx].first)) {
                int hand1 = (pq[ridx].second - pq[ridx].first + 1) + 1;
                val -= hand1*(hand1-1)/2;
                
                int hand2 = (r - pq[ridx].first + 1) + 1;
                cout << hand2 << endl;
                val += hand2*(hand2-1)/2;
            }
            ans.push_back(val);
        }
        return ans;
    }
};