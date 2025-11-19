// https://leetcode.com/problems/subarray-sums-divisible-by-k

class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        N = len(nums)

        pref = [0] * (N+1)
        for i in range(N):
            pref[i+1] += (pref[i] + nums[i]) % k

        ans = 0
        m = defaultdict(lambda: 0)

        for i in range(N):
            m[pref[i]] += 1
            if pref[i+1] in m:
                ans += m[pref[i+1]]

        return ans