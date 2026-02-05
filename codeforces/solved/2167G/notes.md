we can do this with regular dp. 

definition: `dp[i][val]` is the minimum cost to cover up to and including the
ith value, with the max value being val

base case: 
- `dp[N-1][INT_MAX] = c[N-1]`
- `dp[N-1][A[N-1]] = 0`

transitions:

if A[i-1] <= val: 
    ans = min(ans, dp(i-1, A[i-1]));
ans = min(ans, dp(i-1, val) + C[i-1]);

