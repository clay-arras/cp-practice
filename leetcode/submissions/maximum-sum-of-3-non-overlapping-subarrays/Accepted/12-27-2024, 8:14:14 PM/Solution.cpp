// https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays

class Solution {
public:
    template<class T>
    struct RMQ {
        vector<T> v; vector<vector<int>> jmp;
        int level(int x) { return 31-__builtin_clz(x); }
        int cmb(int a, int b) {
            if (v[a] == v[b])
                return min(a, b);
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
            assert(l <= r);
            int d = level(r-l+1);
            return cmb(jmp[d][l], jmp[d][r-(1<<d)+1]);
        }
        T query(int l, int r) { return v[index(l,r)]; }
    };

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int N = (int)nums.size();
        vector<int> pref(N-k+1);

        int sum = 0;
        for (int i=0; i<N; i++) {
            sum += nums[i];
            if (i >= k-1) {
                pref[i-k+1] = sum;
                sum -= nums[i-k+1];
            }
        }
        RMQ<int> spt;
        spt.init(pref);

        for (int i : pref)
            cout << i << " " ;
        cout << endl;
        
        int ans = 0;
        vector<int> ret = {INT_MAX, INT_MAX, INT_MAX};
        for (int i=k; i<=N-2*k; i++) {
            int l = spt.index(0, i-k);
            int r = spt.index(i+k, N-k);
            if (pref[i] + pref[l] + pref[r] == ans) {
                ret = min(ret, {l, i, r});
            } else if (pref[i] + pref[l] + pref[r] > ans) {
                ans = pref[i] + pref[l] + pref[r];
                ret = {l, i, r};
            }
        }

        return ret;
    }
};