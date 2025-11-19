// https://leetcode.com/problems/count-beautiful-splits-in-an-array

class Solution {
public:
    pair<long long, long long> compute_hash(int num, long long hash_value, long long p_pow) {
        const int p = 31;
        const int m = 1e9 + 7;
        // Convert number directly without string conversion
        if (num == 0) {
            hash_value = (hash_value + p_pow) % m;
            p_pow = (p_pow * p) % m;
            return {hash_value, p_pow};
        }
        while (num) {
            hash_value = (hash_value + (num % 10 + 1) * p_pow) % m;
            p_pow = (p_pow * p) % m;
            num /= 10;
        }
        // Add separator
        hash_value = (hash_value + p_pow) % m;
        p_pow = (p_pow * p) % m;
        return {hash_value, p_pow};
    }

    int beautifulSplits(vector<int>& nums) {
        int N = nums.size();
        vector<vector<long long>> hash(N, vector<long long>(N));
        
        // Precompute hashes
        for (int i = 0; i < N; i++) {
            long long hash_value = 0;
            long long p_pow = 1;
            for (int j = i; j < N; j++) {
                auto [new_hash, new_pow] = compute_hash(nums[j], hash_value, p_pow);
                hash_value = new_hash;
                p_pow = new_pow;
                hash[i][j] = hash_value;
            }
        }

        int ans = 0;
        for (int i = 1; i < N-1; i++) {
            for (int j = i+1; j < N; j++) {
                if ((j-i >= i && hash[0][i-1] == hash[i][2*i-1]) ||
                    (N-j >= j-i && hash[i][j-1] == hash[j][i+2*(j-i)-1])) {
                    ans++;
                }
            }
        }
        return ans;
    }
};