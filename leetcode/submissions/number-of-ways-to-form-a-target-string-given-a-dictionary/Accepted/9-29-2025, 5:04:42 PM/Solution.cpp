// https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary

class Solution {
public:
    const static int MOD = 1e9+7;
    vector<unordered_map<char, int>> cnt;
    vector<unordered_map<int, int>> memo;
    int N, M;
    string tar;

    int dp(int i, int x) {
        if (i == N)
            return 1;
        if (x == M)
            return 0;
        if (memo[i].count(x))
            return memo[i][x];

        long long ans = 0;
        ans += dp(i, x+1);
        ans += dp(i+1, x+1) * 1LL * cnt[x][tar[i]];

        ans %= MOD;
        return memo[i][x] = ans;
    }

    int numWays(vector<string>& words, string target) {
        N = (int)target.size();
        M = (int)words[0].size();
        tar = target;
        
        cnt = vector<unordered_map<char, int>>(M);
        for (string s : words) {
            for (int i=0; i<M; i++)
                cnt[i][s[i]]++;
        }

        memo = vector<unordered_map<int, int>>(N);
        return dp(0, 0);
    }
};

/*

dp with optimization
N^2logN

DEFINITION
dp[target.length][words[j].length] = number of ways
dp[i][j]
how many ways we can form the target up to i using chars before and on the jth word char

query(x: all chars we can use, c: char we're looking for) => a list of indices where that works {x, j}

BASE CASE
dp = 0
query(0, target[0])
dp[0][x] += 1

TRANSITION
query(x, target[i])
dp[in][xn] += dp[i][x]

---

search w/ memo

start point: dp[0][0]
end point: when we finish, then we return 1
if (x == target.size())
    return 1;

currently O(N^2)
*/