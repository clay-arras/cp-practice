// https://leetcode.com/problems/delete-and-earn

from collections import defaultdict

class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        cnt = defaultdict(lambda: 0)
        mx = -math.inf
        for i in nums:
            cnt[i] += i
            mx = max(mx, i)

        dp = [0] * (mx+2)
        print(cnt)

        for i in range(mx):
            dp[i+2] = max(dp[i+1], dp[i] + cnt[i+2])
        
        print(dp)

        return dp[mx]


        