// https://leetcode.com/problems/minimum-time-to-activate-string

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

    int minTime(string s, vector<int>& order, int k) {
        // binary search
        
        // check steps: 
        /*
        loop through and replace string w/ order (N time)
        use dp to count number of valid substrings

        dp[i] is the max number of valid substrings using the first i digits
        if s[i] == '*', then we add i to the count. dp[i] = dp[i-1] + (i + 1)
        if s[i] != '*', then we add prev, where prev was the index of the last '*'. dp[i] = dp[i-1] + (prev + 1)
        */

        // t is from 0 to n-1
        int MXK = 1e9+1;

        int N = (int)s.size();
        const auto ok = [&](int t) {
            string st = s;
            for (int i=0; i<=t; i++) 
                st[order[i]] = '*';

            vector<int> dp(N, 0);
            int prev = -1;
            for (int i=0; i<N; i++) {
                if (st[i] == '*') prev = i;
                if (prev != -1) {
                    dp[i] = prev + 1;
                    if (i) dp[i] += dp[i-1];
                    dp[i] = min(dp[i], MXK);
                }
            }
            return dp[N-1] >= k;
        };

        int ans = firstTrue<int>(0, N-1, ok);
        return ans == N ? -1 : ans;
    }
};