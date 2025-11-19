// https://leetcode.com/problems/minimum-time-to-complete-all-deliveries

class Solution:
    def check(x, d, r):
        mul = math.lcm(*r)
        t0 = d[0] - (x // r[1] - x // mul)
        t1 = d[1] - (x // r[0] - x // mul)
        return x - (x // r[1]) - (x // r[0]) + (x // mul) >= max(t0, 0) + max(t1, 0)
        
    def minimumTime(self, d: List[int], r: List[int]) -> int:
        left = 0
        right = 10**16

        while left < right:
            mid = left + (right - left) // 2
            if Solution.check(mid, d, r):
                right = mid
            else: 
                left = mid + 1
        return left