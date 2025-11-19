// https://leetcode.com/problems/count-number-of-balanced-permutations

class Solution {
public:
    long long target;
    vector<long long> rest;
    long long ans = 0;
    const long long MOD = 1e9+7;
    long long f[101];

    long long mod_fact(long long n) {
        f[0] = 1;
        for(long long i=1; i<=n; i++)
            f[i] = (i*1LL * f[i-1]) % MOD;
        return f[n];
    }

    void subsets(vector<long long> arr, long long sum, long long index) {
        if (sum > target) return;
        if ((long long)arr.size() > ceil(rest.size()*1.0/2)) return;
        
        if (sum == target && ((long long)arr.size() == ((long long)rest.size()/2))) {
            map<long long, long long> m;
            for (long long i : arr)
                m[i]++;
            long long add = f[((long long)rest.size()/2)];
            for (auto [k, v] : m) {
                add /= f[(v)];
            }

            map<long long, long long> m2;
            for (long long i : rest) {
                if (m[i] == 0) {
                    m2[i]++; 
                } else {
                    m[i]--;
                }
            }
            long long add2 = f[(long long)(ceil((long long)rest.size()*1.0/2))];
            for (auto [k, v] : m2) {
                add2 /= f[(v)];
            }
            ans = (ans + (add2%MOD)*(add%MOD)) % MOD;
            return;
        }

        long long last = -1;
        for (long long i=index; i<(long long)rest.size(); i++) {
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
        cout << num << endl;
        mod_fact(100);
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