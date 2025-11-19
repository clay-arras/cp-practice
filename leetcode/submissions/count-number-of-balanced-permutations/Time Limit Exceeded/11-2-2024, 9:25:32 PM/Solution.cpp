// https://leetcode.com/problems/count-number-of-balanced-permutations

class Solution {
public:
    __int128 target;
    vector<__int128> rest;
    __int128 ans = 0;
    const __int128 MOD = 1e9+7;
    __int128 f[101];

    __int128 mod_fact(__int128 n) {
        f[0] = 1;
        for(__int128 i=1; i<=n; i++)
            f[i] = (i*1LL * f[i-1]);
        return f[n];
    }

    void subsets(vector<__int128> arr, __int128 sum, __int128 index) {
        if (sum > target) return;
        if ((__int128)arr.size() > (rest.size()*1.0/2)) return;
        
        if (sum == target && ((__int128)arr.size() == ((__int128)rest.size()/2))) {
            map<__int128, __int128> m;
            for (__int128 i : arr)
                m[i]++;
            __int128 add = f[((__int128)rest.size()/2)];
            for (auto [k, v] : m) {
                assert(add % f[v] == 0);
                add /= f[(v)];
            }

            map<__int128, __int128> m2;
            for (__int128 i : rest) {
                if (m[i] == 0) {
                    m2[i]++; 
                } else {
                    m[i]--;
                }
            }
            __int128 add2 = f[(__int128)(ceil((__int128)rest.size()*1.0/2))];
            for (auto [k, v] : m2) {
                assert(add2 % f[v] == 0);
                add2 /= f[(v)];
            }
            ans = (ans + (add2)*(add)) % MOD;
            return;
        }

        __int128 last = -1;
        for (__int128 i=index; i<(__int128)rest.size(); i++) {
            if (rest[i] == last) continue;
            arr.push_back(rest[i]);
            sum += rest[i];
            
            subsets(arr, sum, i+1);
            last = rest[i];
            
            arr.pop_back();
            sum -= rest[i];
        }
    }

    int countBalancedPermutations(string num) {
        sort(num.begin(), num.end());
        mod_fact(33);
        for (char c : num) {
            target += c - '0';
            rest.push_back(c - '0');
        }
        sort(rest.begin(), rest.end());
        if (target % 2) return 0;
        target /= 2;

        subsets({}, 0, 0);
        return ans % MOD;
    }
};