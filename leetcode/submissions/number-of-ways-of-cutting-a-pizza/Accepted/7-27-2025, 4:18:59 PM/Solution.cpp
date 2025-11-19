// https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza

class Solution {
public:
    const static int MOD = 1e9+7;
    const static int MXD = 51;
    const static int MXK = 11;
    int N, M;

    vector<vector<int>> pref;
    int memo[MXD][MXD][MXK];
    bool vis[MXD][MXD][MXK];

    int getPref(int x1, int x2, int y1, int y2) { // bigger is first
        return pref[x1+1][y1+1] - pref[x1+1][y2] - pref[x2][y1+1] + pref[x2][y2];
    }

    int dp(int i, int j, int k) {
        if (vis[i][j][k])
            return memo[i][j][k];
        if (getPref(N-1, i, M-1, j) < k)
            return 0;
        if (k == 1)
            return 1;
        
        int sum = 0;
        for (int x=i+1; x<N; x++) 
            if (getPref(x-1, i, M-1, j))
                sum = (sum + dp(x, j, k-1)) % MOD;
        for (int y=j+1; y<M; y++) 
            if (getPref(N-1, i, y-1, j))
                sum = (sum + dp(i, y, k-1)) % MOD;
            
        vis[i][j][k] = true;
        return memo[i][j][k] = sum;
    }

    int ways(vector<string>& pizza, int k) {
        N = (int)pizza.size(), M = (int)pizza[0].size();

        pref = vector<vector<int>>(N+1, vector<int>(M+1, 0));
        for (int i=1; i<=N; i++) {
            for (int j=1; j<=M; j++) {
                pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + (pizza[i-1][j-1] == 'A');
            }
        }
        int ans = dp(0, 0, k);

        return ans;
    }
};

// 2d prefix sum
// recursive solution w/ dp and memoization

// base case: 0 if if there's a apple inside, 1 if theres
// state {x1, x2}, {y1, y2}, k
// transitions: cut x, cut y (N + M)
// optimization: if group does NOT have k apples inside, then return early

// loop through and cut EVERY SINGLE COMBO
// time complexity: N^5 * K