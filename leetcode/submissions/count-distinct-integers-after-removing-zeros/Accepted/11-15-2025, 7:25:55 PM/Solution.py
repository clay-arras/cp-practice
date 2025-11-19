// https://leetcode.com/problems/count-distinct-integers-after-removing-zeros

class Solution:
    def countDistinct(self, n: int) -> int:
        ans = 0
        s = str(n)
        sz = len(s)
    
        for i, x in reversed(list(enumerate(s[::-1]))):
            if int(x) == 0:
                break
            ans += (int(x) - 1) * (9**i)
    
        for i in range(1, sz):
            ans += 9**i
        if "0" not in s:
            ans += 1
        return ans
