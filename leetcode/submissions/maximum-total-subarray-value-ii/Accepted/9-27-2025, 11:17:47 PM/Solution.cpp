// https://leetcode.com/problems/maximum-total-subarray-value-ii

class Solution {
public:
    template<class T>
    struct RMinQ {
        vector<T> v; vector<vector<int>> jmp;
        int level(int x) { return 31-__builtin_clz(x); }
        int cmb(int a, int b) {
            if (v[a] == v[b])
                return min(a, b);
            return v[a] < v[b] ? a : b;
        }
        void init(const vector<T>& _v) {
            int sz = (int)_v.size();
            jmp = { vector<int>(sz) };
            v = _v;
            iota(jmp[0].begin(), jmp[0].end(), 0);
            for (int j=1; (1<<j)<=sz; j++) {
                jmp.push_back(vector<int>(sz-(1<<j)+1));
                for (int i=0; i<(int)jmp[j].size(); i++)
                    jmp[j][i] = cmb(jmp[j-1][i], jmp[j-1][i+(1<<(j-1))]);
            }
        }
        int index(int l, int r) {
            int d = level(r-l+1);
            assert(l <= r);
            return cmb(jmp[d][l], jmp[d][r-(1<<d)+1]);
        }
        T query(int l, int r) { return v[index(l,r)]; }
    };
    
    template<class T>
    struct RMaxQ {
        vector<T> v; vector<vector<int>> jmp;
        int level(int x) { return 31-__builtin_clz(x); }
        int cmb(int a, int b) {
            if (v[a] == v[b])
                return max(a, b);
            return v[a] > v[b] ? a : b;
        }
        void init(const vector<T>& _v) {
            int sz = (int)_v.size();
            jmp = { vector<int>(sz) };
            v = _v;
            iota(jmp[0].begin(), jmp[0].end(), 0);
            for (int j=1; (1<<j)<=sz; j++) {
                jmp.push_back(vector<int>(sz-(1<<j)+1));
                for (int i=0; i<(int)jmp[j].size(); i++)
                    jmp[j][i] = cmb(jmp[j-1][i], jmp[j-1][i+(1<<(j-1))]);
            }
        }
        int index(int l, int r) {
            int d = level(r-l+1);
            assert(l <= r);
            return cmb(jmp[d][l], jmp[d][r-(1<<d)+1]);
        }
        T query(int l, int r) { return v[index(l,r)]; }
    };

    long long maxTotalValue(vector<int>& nums, int k) {
        int N = (int)nums.size();

        vector<pair<int, int>> idx;
        for (int i=0; i<N; i++)
            idx.push_back({nums[i], i});
        
        RMinQ<pair<int, int>> mn;
        mn.init(idx);
        RMaxQ<pair<int, int>> mx;
        mx.init(idx);

        priority_queue<pair<int, pair<int, int>>> m;
        for (int i=0; i<N; i++) {
            auto min_ = mn.query(0, i);
            auto max_ = mx.query(0, i);
            m.push({max_.first - min_.first, {0, i}});
        }

        long long ans = 0;
        while (k--) {
            auto x = m.top();
            m.pop();

            ans += x.first;
            if (x.second.first + 1 > x.second.second) 
                continue;
            auto min_ = mn.query(x.second.first + 1, x.second.second);
            auto max_ = mx.query(x.second.first + 1, x.second.second);
            m.push({max_.first - min_.first, {x.second.first + 1, x.second.second}});
        }
        return ans;
    }
};
