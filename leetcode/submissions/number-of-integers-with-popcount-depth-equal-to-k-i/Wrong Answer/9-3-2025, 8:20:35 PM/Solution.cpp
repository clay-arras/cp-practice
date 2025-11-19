// https://leetcode.com/problems/number-of-integers-with-popcount-depth-equal-to-k-i

class Solution {
public:
    uint64_t greatest_lt_with_Pbits(uint64_t N, int P) {
        if (P < 0 || P > 64) return -LLONG_MAX; 
        if (N == 0) return -LLONG_MAX; 
        int Q = __builtin_popcountll(N);
    
        if (P < Q) {
            uint64_t x = N;
            for (int t = 0; t < Q - P; ++t) x &= (x - 1);
            return x;
        }
    
        for (uint64_t scan = N; scan; scan &= (scan - 1)) {
            int idx = __builtin_ctzll(scan);
            uint64_t prefix;
            if (idx == 63) prefix = 0; 
            else           prefix = (N >> (idx + 1)) << (idx + 1);
    
            int ones_above = __builtin_popcountll(prefix);
            int need = P - ones_above; 
            if (0 <= need && need <= idx) {
                uint64_t lower = (need == 0) ? 0ULL : (((1ULL << need) - 1) << (idx - need));
                return prefix | lower;
            }
        }
    
        return -LLONG_MAX; 
    }

    uint64_t nCk_u64(uint32_t n, uint32_t k) {
        if (k > n) return 0;
        k = std::min(k, n - k);
        __int128 r = 1;                    
        for (uint32_t i = 1; i <= k; ++i)  
            r = (r * (n - i + 1)) / i;
        return (uint64_t)r;               
    }

    long long calc(long long val) {
        long long bits = __builtin_popcount(val);
        long long sum = 0;
        for (long long i=54; i>=1; i--) {
            if ((1LL << i) & val) {
                sum += nCk_u64(i, bits);
                bits--;
            }
        }
        return sum;
    }

    long long popcountDepth(long long n, int k) {
        vector<int> cand;
        for (int i=1; i<=53; i++) {
            int val = i, sum = 0;
            while (val != 1) {
                val = __builtin_popcount(val);
                sum++;
            }
            if (sum == k - 1)
                cand.push_back(i);
        }

        long long sum = 0;
        for (auto i : cand)
            sum += greatest_lt_with_Pbits(n, i);
        return sum;
    }
};