// https://leetcode.com/problems/count-beautiful-splits-in-an-array

class Solution {
public:
    const static int p = 31;
    const static int m = 1e9 + 9;

    pair<long long, long long> compute_hash(string const& s, long long hash_value, long long p_pow) {
        const int p = 31;
        const int m = 1e9 + 9;
        for (char c : s) {
            hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
            p_pow = (p_pow * p) % m;
        }
        return {hash_value, p_pow};
    }

    int beautifulSplits(vector<int>& nums) {
        if ((int)nums.size() < 3)
            return 0;

        int N = (int)nums.size();
        vector<vector<long long>> hash(N, vector<long long> (N, -1));
        for (int i=0; i<N; i++) {
            long long hash_value = 0;
            long long p_pow = 1;
            for (int j=i; j<N; j++) {
                auto ret = compute_hash(to_string(nums[j]) + "#", hash_value, p_pow);
                hash_value = ret.first;
                p_pow = ret.second;
                hash[i][j] = hash_value;
            }
        }

        int ans = 0;
        for (int i=0; i<N; i++) {
            for (int j=i+1; j<N; j++) {
                if (2*j-i-1 < N && hash[i][j-1] == hash[j][2*j-i-1]) {
                    ans += (N - (2*j-i));
                    if ((2*j-i) == N) ans++;
                }
            }
        }
        return ans;
    }
};