// https://leetcode.com/problems/count-number-of-balanced-permutations

class Solution {
public:
    int target;
    vector<int> rest;
    long long ans = 0;
    const int MOD = 1e9+7;

    // start at {}, sum, everything greater than index
    // if sum == target and arr.size = rest/2

    void subsets(vector<int> arr, long long sum, int index) {
        if (sum > target) return;
        if ((int)arr.size() > (int)rest.size()/2) return;
        if (sum == target && (int)arr.size() == (int)rest.size()/2) {
            // for (int i : arr)
            //     cout << i << " ";
            // cout << endl;
            
            unordered_map<long long, long long> m;
            for (int i : arr)
                m[i]++;
            long long add = tgamma((int)rest.size()/2 + 1);
            for (auto [k, v] : m) {
                add /= tgamma(v+1);
            }

            unordered_map<long long, long long> m2;
            for (int i : rest) {
                if (m[i] == 0) {
                    m2[i]++; 
                } else {
                    m[i]--;
                }
            }
            long long add2 = tgamma(ceil((int)rest.size()*1.0/2) + 1);
            for (auto [k, v] : m2) {
                add2 /= tgamma(v+1);
            }
            ans = (ans + (add2%MOD)*(add%MOD)) % MOD;
            return;
        }
        for (int i=index; i<(int)rest.size(); i++) {
            arr.push_back(rest[i]);
            sum += rest[i];
            subsets(arr, sum, i+1);
            arr.pop_back();
            sum -= rest[i];
        }
    }

    int countBalancedPermutations(string num) {
        for (char c : num) {
            target += c - '0';
            rest.push_back(c - '0');
        }
        if (target % 2) return 0;
        target /= 2;

        subsets({}, 0, 0);
        return ans;
    }
};