// https://leetcode.com/problems/count-distinct-subarrays-divisible-by-k-in-sorted-array

class Solution:
    def numGoodSubarrays(self, nums: List[int], k: int) -> int:
        N = len(nums)

        pref = [0] * (N+1)
        for i in range(N):
            pref[i+1] += (pref[i] + nums[i]) % k

        ans = 0
        m = defaultdict(lambda: 0)

        for i in range(N):
            m[pref[i-1]] += 1
            if pref[i] in m:
                ans += m[pref[i]]

        for i, l in groupby(nums):
            if i % k != 0 and k % (i % k) != 0:
                continue

            s = 1 if i % k == 0 else int(k / (i % k))
            it = s
            l = list(l)
            while it <= len(l):
                ans -= max(0, len(l) - it)
                it += s

        return ans