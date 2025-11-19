// https://leetcode.com/problems/handling-sum-queries-after-update

class Solution {
public:
    template<class T, int SZ>
    struct LazySeg {
        static_assert(__builtin_popcount(SZ) == 1);
        const T ID{};
        T cmb(T a, T b) { return a+b; }
        T seg[2*SZ], lazy[2*SZ];
        LazySeg() {
            for (int i=0; i<2*SZ; i++)
                seg[i] = lazy[i] = ID;
        }
        void push(int ind, int L, int R) {
            if (lazy[ind] == 1)
                seg[ind] = (R-L+1) - seg[ind]; // here: seg[ind] += (R-L+1)*lazy[ind];
            if (L != R) {
                for (int i=0; i<2; ++i)
                    lazy[2*ind+i] ^= lazy[ind]; // here: lazy[2*ind+i] += lazy[ind];
            }
            lazy[ind] = 0;
        }
        void pull(int ind){
            seg[ind]=cmb(seg[2*ind],seg[2*ind+1]);
        }
        void build() {
            for (int i=SZ-1; i>=1; --i)
                pull(i);
        }
        void update(int lo,int hi,T inc,int ind=1,int L=0, int R=SZ-1) {
            push(ind,L,R); 
            if (hi < L || R < lo) return;
            if (lo <= L && R <= hi) {
                lazy[ind] = inc;
                push(ind,L,R);
                return;
            }
            int M = (L+R)/2;
            update(lo,hi,inc,2*ind,L,M);
            update(lo,hi,inc,2*ind+1,M+1,R);
            pull(ind);
        }
        T query(int lo, int hi, int ind=1, int L=0, int R=SZ-1) {
            push(ind,L,R);
            if (lo > R || L > hi) return ID;
            if (lo <= L && R <= hi) return seg[ind];
            int M = (L+R)/2;
            return cmb(query(lo,hi,2*ind,L,M), query(lo,hi,2*ind+1,M+1,R));
        }
    };

    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int N = (int)nums1.size();
        
        vector<long long> ans;
        const int SZ = (1 << 18);
        LazySeg<int, SZ> s;
        
        for (int i=SZ; i<SZ+N; i++)
            s.seg[i] = nums1[i-SZ];
        s.build();

        long long sum = 0;
        for (int i : nums2)
            sum += i;
        for (auto q : queries) {
            if (q[0] == 1) {
                s.update(q[1], q[2], 1);
            } else if (q[0] == 2) {
                sum += s.query(0, N-1) * q[1]; 
            } else if (q[0] == 3) {
                ans.push_back(sum);
            }
        }
        return ans;
    }
};