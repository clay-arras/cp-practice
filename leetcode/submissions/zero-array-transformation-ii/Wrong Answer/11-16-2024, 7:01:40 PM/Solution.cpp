// https://leetcode.com/problems/zero-array-transformation-ii

class Solution {
public:
    template<class T>
    T firstTrue(T l, T r, function<bool(T)> f) {
        r++;
        while (l < r) {
            T mid = l + (r - l) / 2;
            if (f(mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int N = (int)nums.size();
        int M = (int)queries.size();

        function<bool(int)> ok = [&](int k) {
            vector<int> diff(N+1, 0);
            for (int i=0; i<k; i++) {
                diff[queries[i][0]] -= queries[i][2];
                diff[queries[i][1]+1] += queries[i][2];
            }

            vector<int> A(N, 0);
            A[0] = diff[0];
            for (int i=1; i<N; i++)
                A[i] = diff[i] + A[i-1];

            bool ans = true;
            for (int i=0; i<N; i++)
                ans &= ((A[i] + nums[i]) <= 0);
            return ans;
        };

        int ans = firstTrue(0, M-1, ok);
        return (ans == M ? -1 : ans);
    }
};