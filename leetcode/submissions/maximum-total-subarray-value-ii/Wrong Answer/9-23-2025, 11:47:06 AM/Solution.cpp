// https://leetcode.com/problems/maximum-total-subarray-value-ii

/*
counter examples: 

nums = [18,36,6]
k = 3

we never cover the subarray [18, 36] because of our greedy


*/


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

        vector<pair<int, int>> srt;
        for (int i=0; i<N; i++)
            srt.push_back({nums[i], i});
        vector<pair<int, int>> arr(srt.begin(), srt.end());
        sort(srt.begin(), srt.end());
        
        RMaxQ<pair<int, int>> mxr; 
        mxr.init(arr);
        RMinQ<pair<int, int>> mnr; 
        mnr.init(arr);
        
        long long ans = 0;
        int mnb = 0, mxb = N-1;
        bool sil = true; // small is left

        for (int sel=0; sel!=k; ) {
            // min is guaranteed to be diff, max can be same
            pair<int, int> mn_n = mnr.query(mnb + sil*(bool)sel, mxb - !sil*(bool)sel); 
            pair<int, int> mx_n = mxr.query(mnb, mxb);
            // rev
            pair<int, int> mn_x = mnr.query(mnb, mxb);
            pair<int, int> mx_x = mxr.query(mnb + !sil*(bool)sel, mxb - sil*(bool)sel);

            pair<int, int> mn, mx;
            if (mn_n == mn_x && mx_n == mx_x) {
                mn = mn_n;
                mx = mx_n;
            } else if (mx_n.first - mn_n.first >= mx_x.first - mn_x.first) {
                mn = mn_n;
                mx = mx_n;
            } else {
                mn = mn_x;
                mx = mx_x;
            }

            if (mx.first <= mn.first)
                break;

            int nmnb = min(mn.second, mx.second);
            int nmxb = max(mn.second, mx.second);
            // cout << nmnb << " " << nmxb << endl;

            int cnt = min((nmnb - mnb + 1) * (mxb - nmxb + 1), k - sel);
            if ((nmnb == mnb || nmxb == mxb) && sel)
                cnt = min(max(nmnb - mnb, 1) * max(mxb - nmxb, 1), k - sel);
            ans += cnt * (mx.first - mn.first);
            sel += cnt;
            
            mnb = nmnb, mxb = nmxb;
            sil = (mn.second < mx.second);
        }
        
        return ans;
    }
};

/*
problem: we don't NEED to move both bounds; we only need to move ONE. 
so we have to test the two different bound movements
- if they're different, then we need to check which one yields a greater difference
- in case of a tie, then we choose a random one

*/